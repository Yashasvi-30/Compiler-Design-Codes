

//1.	WAP to count number of ‘scanf’ and ‘printf’ keywords  in the file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//write a code to count the number of 'scanf' and 'printf' keywords in the file.
int main() {
    FILE *file;
    char str[1000];
    int scanf_count = 0, printf_count = 0;
    int i = 0;

    file = fopen("file1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

   //do it for multiple lines 
   
    while (fgets(str, sizeof(str), file) != NULL) {
        if (strstr(str, "scanf") != NULL) {
            scanf_count++;
        }
        if (strstr(str, "printf") != NULL) {
            printf_count++;
        }
    }

    printf("scanf count: %d\n", scanf_count);
    printf("printf count: %d\n", printf_count);

    //create output file replace scanf with read and printf with write 
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
//when you replace just replace the word , keep the rest sentence intact 

    fseek(file, 0, SEEK_SET);
    while (fgets(str, sizeof(str), file) != NULL) {
        if (strstr(str, "scanf") != NULL) {
            fprintf(output_file, "%s", "read");
        } else if (strstr(str, "printf") != NULL) {
            fprintf(output_file, "%s", "write");
        } else {
            fprintf(output_file, "%s", str);
        }
    }

    fclose(file);
    return 0;
}




