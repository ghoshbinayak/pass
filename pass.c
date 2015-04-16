#include "stdio.h"
#include "hashtab.h"

// function prototypes
int pass1();

// Global variables
FILE * ifp;

int main(int argc, char const *argv[])
{
	// Read the arguments
	if (argc < 2)
	{
		printf("%s\n", "usage: pass <file name>");
		exit(0);
	}

	// Try to open the file
	ifp = fopen(argv[1], "r");
	if (ifp == NULL)
	{
		printf("%s\n", "error: file not found");
		exit(0);
	}

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

	// 
	return 0;
}

int pass1(){
	char c;
	while ((c = getc(ifp)) != EOF){

	}

	return 1;
}