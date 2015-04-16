#include <stdio.h>
#include "hashtab.h"

#define MAXLENGTH 2000

// function prototypes
int pass1();

// Global variables
FILE * ifp; //input file
FILE * ofp; //output file
char * tokens[MAXLENGTH];
char token[100];
char * buffer;
int location_counter = 0;

int main(int argc, char const *argv[])
{
	// Read the arguments
	if (argc < 2)
	{
		printf("%s\n", "usage: pass <file name>");
		exit(0);
	}

	// Try to open the file
	printf("%s\n", argv[1]);
	if ((ifp = fopen(argv[1], "r")) == NULL)
	{
		printf("%s\n", "error: file not found");
		exit(0);
	}

	// Run first pass
	pass1();

	// hash table declaration
	hashtable_t *hashtable = ht_create( 65536 );

	ht_set( hashtable, "key1", "inky" );
	ht_set( hashtable, "key2", "pinky" );
	ht_set( hashtable, "key3", "blinky" );
	ht_set( hashtable, "key4", "floyd" );

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

	return 0;
}

int pass1(){
	char c;
	int i = 0;
	while ((c = getc(ifp)) != EOF){
		if (c != ' ' && c != '\t' && c != '\n')
		{
			token[i++] = c;
		}
		else {
			if (i > 0)
			{
				token[i] = '\0';
				i = 0;
				printf("%s\n", token);
			}
		}
	}
	return 1;
}