#include <stdio.h>
#include <stdlib.h>
int main() {
    char line[256];

    const char *text = "text.txt";
    char *str = "привет";
    printf("Содержимое файла:\n");
    FILE *file1 = fopen(text, "r");
    if(file1)
    {
        while((fgets(line, 256, file1))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file1);
    } 
    FILE *file2 = fopen(text, "a");
    fputs(str,file2);
    printf("\n");
    fclose(file2);
    
    printf("Содержимое файла после записи:\n");
    FILE *file3 = fopen(text,"r");
    if(file3)
    {
        while((fgets(line, 256, file3))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file3);
    } 
    
    return 0;
}
