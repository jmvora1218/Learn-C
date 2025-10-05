#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

// c has no class everything is at global scope
struct Address {
    int id;
    // set is a flag
    int set;
    // max size of string value || that's why garbage... coz memory already allocated but not initialized.
    // mem optimization - if char* instead of char[] then we clould have improved memory
    // if needed then we could have allocated dynamic memory
    char name[MAX_DATA];   // 512 array size
    char email[MAX_DATA];   // 512 array size
};

struct Database {
    struct Address rows[MAX_ROWS];    // 100 array size
};

struct Connection {
    FILE *file;
    struct Database *db;        //nested to nested struct  // *db is variable pointer of dtabase stuct
};

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    //print in-address value to console
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        // if file not read 
        die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
    
    //action = create
    struct Connection *conn = (struct Connection *) malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error");

    // file me lock and open db file for read/write
    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error");

    if (mode == 'c') {
        // create file in write mode
        conn->file = fopen(filename, "w");
    } else {
        // read-write and pointer saved 
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            // pass by reference
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
            // if flush nahi bhi kia hota.. to bhi closed
            fclose(conn->file);
        if (conn->db)
            //memory block read == file size jo tha | free coz in mem
            free(conn->db);
        // file address - freed
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    //rewind() function moves the file pointer at beginning of the file //https://www.geeksforgeeks.org/g-fact-82/
    rewind(conn->file);

    // write all data to file
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

int main(int argc, char *argv[])
{
    // as a service i.e. while tru loop - then it'd leak memory
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");
    // ./ext17 ext7db create 23

    char *filename = argv[1];
    char action = argv[2][0];
    
    // struct Connection * <- pointer to a shared connection
    // file <- same shared lock file
    struct Connection *conn = Database_open(filename,
                                            //create
                                                action);
    // db loaded
    
    
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
