#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv) {

    int numNewlines = 0, numWords = 0, numBytes = 0;
    char fileName[41], text[201];

    //prompt for and read file name
    puts("Enter file name (40 characters max): ");
    scanf("%s", fileName);

    FILE *inputFile = fopen(fileName, "r");

    while (fgets(text, 201, inputFile) != NULL) {   //loop while there is another line in the file and store that line in the text string
        for (int i = 0; text[i] != '\0'; i++) {     //go through each character in the string
            if(text[i] == ' ' || text[i] == '\t') {     //if character is a whitespace
                if(text[i - 1] != ' ' && text[i - 1] != '\t') { // and if previous character was not a whitespace then increment words counter
                    numWords++;     
                }
            }
            if(text[i] == '\n')     //if the character is a new line then increment new line counter
                numNewlines++;
            numBytes++;         //increment bytes counter
        }
    }
    numWords++;     //increment words to fix offset

    printf(" %d  %d %d\n", numNewlines, numWords, numBytes);       //print output

}