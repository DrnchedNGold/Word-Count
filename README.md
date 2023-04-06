# Word-Count
Simplified version of wc command in UNIX/Linux written in C

http://cs.middlesexcc.edu/~schatz/csc264/labs/csc264.lab3.html

CSC264 Computer Organization & Architecture II
Lab 3
Word Count

The wc command on unix/linux takes a file name and prints the following counts for the contents of the file: the number of newlines ('\n'), the number of words (contiguous non-whitespace characters). You can see examples and an explanation of the wc command at https://linuxize.com/post/linux-wc-command/

You can try the wc command on windows in windows powershell; you can try the wc command on OSX in a terminal window.

In this lab you will write your own version of wc. We will write a simplified version of the command which has no options and only accepts one filename.
Notes

    In the spirit of unix/linux, your output should be just the three counts: newlines, words, and then bytes, followed by the filename. Separate the counts with a couple of blanks. You don't need to print any words other than that.
    Words are separated by white space characters. White space consists of the characters blank (' ', ASCII value 3210 or 2016), tab ('\t', ASCII value 910 which is also 916), and newline ('\n', ASCII value 1010 or A16). Of course there can be multiple white space characters between words. All whitespace characters should be included in the byte count.
    Prompt the user to enter the filename. Create an array large enough to hold a filename of 40 characters. Don't forget to add an additional location to the array to hold the null byte. If the filename is 40 characters there won't be room for the null byte unless you increase the array size by one.
    Use fopen to open the file:

    FILE *fopen(const char *filename, const char *mode)

    Pass the filename as the first parm and "r" (for read mode) for the second parm. fopen returns a FILE pointer. If the file cannot be opened, fopen returns NULL.
    You will read the file line by line in main, and pass each line to a function that will count the characters and the words on the line. Create an array of 201 characters to hold the input line. We will assume that each line of the file is at most 200 characters.
    Use fgets to read from the file. fgets reads a line from the file into the string parm, similar to nextLine in Java. It adds a null byte after the characters that are read. To make sure that the input doesn't overflow the array, fgets takes the size of the array as a parm. fgets stops reading when a newline is encountered, or it reads n-1 bytes, or it reaches end of file, whichever comes first. If it reads a newline it adds a null byte after the newline. If n-1 characters are read before a newline is seen, then it stops reading and adds a null byte as the nth character. If end-of-file is encountered before a newline or n-1 characters are read, fgets adds a null byte to the end of the characters read. fgets returns NULL when it reaches end of file.

         char *fgets(char *str, int n, FILE *stream);

    When you call fgets pass the string (an array of characters), the length of the array, and the file pointer returned by fopen. fgets reads a line of input; this string is returned by fgets and is also contained in the first parameter after the call is complete. Pass this string to a function which will count the number of words and characters in the string. Pass the word and character counts to the function by reference and return those values in the reference parms.

    Email Me | Office Hours | My Home Page | Department Home | MCC Home Page

    © Copyright Emmi Schatz 2023

    Last Updated: 04/05/2023 12:06:10 