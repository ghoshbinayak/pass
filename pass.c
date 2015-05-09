#include <stdio.h>
#include "hashtab.h"

#define MAXLENGTH 2000

// function prototypes
int pass1();

// Global variables
FILE *ifp;  // input file
FILE *ofp;  // output file

char *tokens[MAXLENGTH];
char *linex[MAXLENGTH];

char token[100];
char line[MAXLENGTH];

char *buffer;
int locationCounter = 0;

int main(int argc, char const *argv[]) {
  // Read the arguments
  if (argc < 2) {
    printf("%s\n", "usage: pass <file name>");
    exit(0);
  }

  // Try to open the file
  if ((ifp = fopen(argv[1], "r")) == NULL) {
    printf("%s\n", "error: file not found");
    exit(0);
  }

  // Run first pass
  pass1();

  // hash table declaration
  hashtable_t *hashtable = ht_create(65536);

  // ht_set( hashtable, "key1", "inky" );
  // ht_set( hashtable, "key2", "pinky" );
  // ht_set( hashtable, "key3", "blinky" );
  // ht_set( hashtable, "key4", "floyd" );

  // printf( "%s\n", ht_get( hashtable, "key1" ) );
  // printf( "%s\n", ht_get( hashtable, "key2" ) );
  // printf( "%s\n", ht_get( hashtable, "key3" ) );
  // printf( "%s\n", ht_get( hashtable, "key4" ) );

  return 0;
}

int pass1() {
  char c, d;
  int i = 0; // line index
  int j = 0; // token index
  int tokenCount = 0;
  int skipLine = 0;
  int skipNextLine = 1;

  while ((c = getc(ifp)) != EOF) {
    // read a line
    if (c != '\n') {
      line[i++] = c;
    }
    else {
      line[i++] = '\n';
      line[i] = '\0';
      i = 0;

      // analyse tokens in the line
      while ((d = line[i++]) != '\0') {
        if (d != ' ' && d != '\t' && d != '\n') {
          token[j++] = d;
        }
        else {
          if (j > 0) {
            token[j] = '\0';
            tokenCount++;
            
            // check the first token of the line
            if(tokenCount == 1 && (token[0] == '.' || token[j-1] == ':')){
            	if (skipNextLine || strcmp(token, ".string") != 0)
            	{
            		skipLine = 1;
            	}
            	else{
            		skipNextLine = 1;
            	}
            	if(token[j-1] == ':'){
            		skipNextLine = 0;
            		// TODO: add symtab entry
            	}
            	// reset token index
            	j = 0;
            	break;
            }
        	// reset token index
            j = 0;
          }
        }
      }

      // print line if not directive
      if (!skipLine)
      {
      	printf("%s\n", line);
      }
      skipLine = 0;

      // reset token count 
      tokenCount = 0;

      // reset line index
      i = 0;
    }
  }

  return 1;
}