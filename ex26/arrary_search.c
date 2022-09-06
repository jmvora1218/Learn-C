#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
        int num =0;
        char string[5000];
        char student[100] = {0};
        char *x;
     
        while(student[0]!= '0')
        {
                FILE *in_file = fopen("student.txt", "r");
                if (in_file == NULL)
                {
                        printf("Error file missing\n");
                        exit(1);
                }

                printf("please enter a word(enter 0 to end)\n");
                scanf("%s", student);
               
                while ( fscanf(in_file,"%s", string) == 1)
                {
                        //Add a for loop till strstr(string, student) does-not returns null. 
                        if (strstr(string, student)!=0){//if match found
                            num++;
                        }
                }
                printf("we found the word [%s] in the file %d times\n",student,num);

                num = 0;
                fclose(in_file);
        }
        return 0;
}

//https://stackoverflow.com/questions/29429384/search-string-in-a-file-in-c