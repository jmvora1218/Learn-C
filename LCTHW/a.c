#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    
    // flag
    int set;
    
    // max size of string value
    // that's why garbage... coz emmory already allocated but not initialized
    // mem optimization - if char* instead of char[] then we clould have improved memory
        // if needed then we could have allocated dynamic memory
    char name[MAX_DATA];   // 512 array size
    char email[MAX_DATA];   // 512 array size
};

struct Addressv2 {
    int id;
    
    // flag
    int set;
    
    // max size of string value
    // that's why garbage... coz emmory already allocated but not initialized
    // mem optimization - if char* instead of char[] then we clould have improved memory
        // if needed then we could have allocated dynamic memory
    
    
    int nameSize;
    
    char* name;   
    char* email;
};

// complete other functions also | extra credit #2
struct Databasev2 {
    
    int maxSize ; 
    
    struct Address *rows;   // dynamic
};


struct Database { 
    struct Address rows[MAX_DATA];   // static 100 rows
};

struct Connection {
    FILE *file;
    struct Database *db;        //nested to nested struct  // *db is variable pointer of dtabase stuct
};


struct Connection *global_conn ;


void Database_findById(struct Connection *conn, int id);




void diev2(const char *message, struct Connection *conn, char* context)
{
    // we could have accepted the conn arguement and closed all in-memory accesses and save a clean file
        // if server program... 
        // extra ref - dirty reads
    
    // we do not know which function calls die coz no error handling in c
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
    
    // clean exit
    // if blah context = write function then revert the write pointer again...
    
    // extra ref - think of this as blue screen in windows with context #233446 blah
    free(conn->db);
    free(conn);
}

void die(const char *message)
{
    // we could have accepted the conn arguement and closed all in-memory accesses and save a clean file
        // if server program... 
        // extra ref - dirty reads
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    // print in-address value to console
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
    printf("\n");
    // print all array
    for(int i=0; i<MAX_DATA; i++) {
        printf("%c", addr->name[i]);
    }
}




void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error");

    // file me lock and open db file for read/write
    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    // if ever create conn
    if (conn) {
        // safely close
        if (conn->file)
            // agr flush nahi bhi kia hota.. to bhi closed
            fclose(conn->file);
        if (conn->db)
            // memory block read == file size jo tha | free coz in mem
            free(conn->db);
        // file address - freed
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    // file se ek piche
    rewind(conn->file);

    // write to file all data
    // fread = file ka size utni memory allocate - usme value load kar deta hai
    // source = memory fread pointer as copy
    int rc = fwrite(
        // input stream
        conn->db,
        // size of file
        sizeof(struct Database), 
        1,
        // output stream
        conn->file);
    
    
    if (rc != 1)
        die("Failed to write database.");

    // os ke paas fs cache - 
    // fs cache to disk force
    rc = fflush(conn->file);
    
    if (rc == -1)
        die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it created the null 100 raw(as per the size)file db created as per the struct  
        struct Address addr = {.id = i,.set = 0 };   // constructor 
        // then just assign it
        conn->db->rows[i] = addr;
        // memory fread pointer write
        // addr = address of fread open in memory
        printf("inside DB_create %d and addr is %p \n ",conn->db->rows[i], addr);

    }
}

void Database_set(struct Connection *conn, int id, const char *name,const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set)
        die("Already set, delete it first");

    // flag to show if value is written or not
    // file layout == <id> <set-flag> <name> <emnail>
    addr->set = 1;

    // WARNING: bug, read the "How To Break It" and fix this
    
    char *res = strncpy(addr->name, name, MAX_DATA);
    
    // char *res = "ok";
    // addr->name = name;

    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed");

    // default \0 terminated string - junk ja raha hai but read nahi karna
    res = strncpy(addr->email, email, MAX_DATA);
    if (!res)
        die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
    // address structu mem value ==  
      // global program address of data at value(id) 
    struct Address *addr = &(conn->db->rows[id]);

    if (addr->set) {
        // if value to yaha
        Address_print(addr);
    } else {
        
        // else return 0
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    // ignored the record in memory
    // created new record
    // assigned id=id and set=0
    struct Address addr = {.id = id,.set = 0 };
    // mem leaked coz we did not free value already read from fread
    // extra ref - cassandra tombstones
    
    // new allocated empty row to id in fread memory
    conn->db->rows[id] = addr;
    // extra ref - borrow checker feature in rust
}


// print all records to console OP
void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        // do not print empty tuples from db - clean output
        if (cur->set) {
            Address_print(cur);
        }
    }
}

void Database_findByName(struct Connection *conn, char* s_name) {
    struct Address *addr = conn->db->rows;
    struct Address *addr_obj; // = &(conn->db->rows[i]);
    
    int found = 0;

    for(int i=0; i<MAX_ROWS; i++) {

        addr_obj = &(conn->db->rows[i]);
    
        // printf("\nDEBUG :: %s == %s | op = %d", addr_obj->name, s_name, strcmp(addr_obj->name, s_name));

        if( strcmp(addr_obj->name, s_name) == 0 ) {
                found = 1;
                break;
            }
    } // read all record for find

    if(found) {
        Address_print(addr_obj);
    } else {
       printf("record not found!");
    }
}


int main(int argc, char *argv[])
{
    // as a service i.e. while tru loop - then it'd leak memory
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3) id = atoi(argv[3]);    // by default taking as a string ""
    if (id >= MAX_ROWS) die("There's not that many records.");

    switch (action) {
        case 'c':
            // in memory write
            Database_create(conn);
            
            // write to file
            Database_write(conn);
            
            break;

        case 'g':
            // get
            if (argc != 4)
                die("Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
            // set
            if (argc != 6)
                die("Need id, name, email to set");
                                    // 4 = name ; 5 = email
            Database_set(conn, id, argv[4], argv[5]);
            // above set in the inmemory file
            
            
            Database_write(conn);
            break;

        case 'd':
            // delete
            if (argc != 4)
                die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;
            
        case 'f':
            // delete
            if (argc != 4)
                die("Need name to find by name");

            Database_findByName(conn, argv[3]);
            break;

        case 'l':
            // list
            Database_list(conn);
            break;
        default:
            die("Invalid action: c=create, g=get, s=set, d=del, l=list");
    }

    // db close 
    Database_close(conn);

    // program stopped so clean up memory
    return 0;
}
