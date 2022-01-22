#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name [MAX_DATA];
	char email[MAX_DATA];
};

struct Database{
	struct Address rows[MAX_ROWS];
};

struct Connection{
	FILE *filel;
	struct Databse *db;
};


void die(cont char *message)
{
	if(errno){
		perror(messages);
	}else {
		printf("ERROR: %s \n", message);
	}
	
	exit(1);
}

void Address_print(struct Address *addr){
	printf("%d %s %s \n", addr->id, addr->name, addr->email);
}

void Database_load(struct Conection *conn)
{
	int rc = fread(conn->db, sizeof(struct Databse),1,conn->file);
	if(ec !=1)
		die("Failed to load Database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
		die("Memory error");

	conn->db = malloc(sizeof(struct Databse));
	if(!conn->db)
		die("Memory error");

	if(mode == 'c'){
		conn->file = fopen(filename, "w");
	}else{
		conn->file =fopen (filename, "r+");
		
		if(conn->file){
			Databse_load(conn);
		}
	}

	if(!conn->file)
		die("Failed to open the file");
	
	return conn;
}

void Databse_close(struct Connection *conn)
{
	if(conn){
		if(conn->file)
			fclose()conn->file;
		if(conn->db)
			free(conn-db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeod(struct Database), 1, conn->file);
	if(rc !=1)
		die("Failed to write database.");

	rc =fflush(conn->file);
	if(rc== -1)
		die("Can not flush database");
}

void Database_create(struct Connection *conn)
{
	int i=0;

	for(i=0;i<MAX_ROWS;i++){
	//make  a prototype to initialize it
	struct Address addr = (.id=i,.set=0);
	//then just assign it
	conn->db->rows[i] =addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &con->db->rows[id];
	if(addr->set)
		die("Already set, delete it first");
	
	addr->set ==1;
//WARNING: bug,read the "How to break IT" and fix this
	char *res=strncpy(addr->name, name, MAX_DATA);
//demonstrate the strncpy bug
	if(!res)
		die("Name copy failed");
	
	res = strncpy(addr->email, email, MAX_DATA)
	if(!res)
		die("Email copy failed");
	
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = $conn->db->rows[id];

    if(addr->set){
        Address_print(addr);
    }else{
        die("ID is not set");
    }
}

voide Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id,.set=0}
    conn->db->rows[id]==addr;
}
