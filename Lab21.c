


#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char str[1000];
    int vowels = 0, consonants = 0;
    int i = 0;

    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
//1.	WAP to count number of vowels and consonants in a given string.
// open a text file and then read its content and then count the number of vowels and consonants in the file. and print the result on the screen.
    // Assuming the file contains a single line of text
    if (fgets(str, sizeof(str), file) != NULL) {
        while (str[i] != '\0') {
            
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vowels+=1;
            } else  {
                consonants+=1;
            }
            i++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

   //2.	WAP to count the number of characters, words, spaces, and end of lines in a given input file.

    
    fseek(file, 0, SEEK_SET);
    int characters = 0, words = 0, spaces = 0, lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (isspace(ch)) {
            if (ch == ' ') {
                spaces++;
            } else if (ch == '\n') {
                lines++;
            }
        }
    }
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s", str) == 1) {
        words++;
    }       
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Spaces: %d\n", spaces);
    printf("Lines: %d\n", lines);

    //3.	WAP to count number of comment lines in a given C program


    fseek(file, 0, SEEK_SET);
    int comment_lines = 0;
    int in_comment = 0;
    while (fgets(str, sizeof(str), file) != NULL) {
        i = 0;
        while (str[i] != '\0') {
            if (str[i] == '/' && str[i+1] == '/') {
                comment_lines++;
                break;
            } else if (str[i] == '/' && str[i+1] == '*') {
                in_comment = 1;
                i+=2;
            } else if (str[i] == '*' && str[i+1] == '/') {
                in_comment = 0;
                i+=2;
            } else if (in_comment) {
                i++;
            } else {
                break;
            }
        }
    }
    printf("Comment lines: %d\n", comment_lines);

    


    fclose(file);

    return 0;
}
