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


