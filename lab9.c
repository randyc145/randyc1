// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1 // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename);

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s) ;

int main(int argc, char* argv[]) {
    char* wordlist[MAXWORDS];
    int wordCount;
    int i;
    wordCount = readWords(wordlist, argv[1]);

    if (DEBUG) {
        printf("Read %d words from %s \n",wordCount, argv[1]);

        readWords(wordlist, argv[1]);

        for(int j = 0; j < sizeof(wordlist); j++)
            printf("%s\n", wordlist[j]);

    }

// most of your code for part 2 goes here. Don't forget to include the ncurses library

    return 0;
}

int readWords(char* wl[MAXWORDS], char* filename){

    int i = 0;
    FILE* inFile = NULL;
    char tempArray[MAXWORDS];

    inFile = fopen(filename, "r");

    while(!feof(inFile)){

        fscanf(inFile, "%s", &tempArray[i]);
        trimws(&tempArray[i]);
        wl[i] = (char *) malloc(sizeof(tempArray));
        strcpy(wl[i], &tempArray[i]);

        i++;

    }

    return i;


}

void trimws(char* s){

    int length = sizeof(s);

    for(int f = 0; f < length; f++){

        if(isspace(s[f])){

            s[f] = '\0';

        }

    }


}
