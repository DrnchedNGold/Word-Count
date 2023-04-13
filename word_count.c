#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcData(char* text, int* numNewlines, int* numWords, int* numBytes, int* isWhitespace) {
    for (int i = 0; text[i] != '\0'; i++) {     //go through each character in the string
        (*numBytes)++;         //increment bytes counter
        if(text[i] == ' ' || text[i] == '\t') {     //if character is a space or tab then set the flag to true
            *isWhitespace = 1;  //set flag to true
        }
        else if(text[i] == '\n') {    //if the character is a new line then increment new line counter and set the flat to true
            (*numNewlines)++;  //increment new line counter
            *isWhitespace = 1;  //set flag to true
        }
        else {      //if the character is not a whitespace
            if(*isWhitespace == 1) {     //if the previous character was a whitespace, then increment the word counter
                (*numWords)++; //increment words counter
            }
            *isWhitespace = 0;   //set the flag to false
        }
    }
}

int main (int argc, char** argv) {

    int numNewlines = 0, numWords = 0, numBytes = 0;    //counters for number of newlines, words, and bytes
    char fileName[41] = "input.txt", text[201];     
    int isWhitespace = 1;       //keeps track of the whether the last character was a whitespace or not

    //prompt for and read file name
    puts("Enter file name (40 characters max): ");
    scanf("%s", fileName);

    FILE *inputFile = fopen(fileName, "r");

    while (fgets(text, 201, inputFile) != NULL) {   //loop while there is another line in the file and store that line in the text string
        calcData(text, &numNewlines, &numWords, &numBytes, &isWhitespace);
    }

    printf("%d  %d %d\n", numNewlines, numWords, numBytes);       //print output
}