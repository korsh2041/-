#include <stdio.h>
#include <stdlib.h>
#define N 1024

int main() {
    FILE *file1, *file2, *file3;
    char line[N];
    int sch = 0;
    printf("Содержимое файл до:\n");
    file1 = fopen("text.txt", "r");
    
    if(file1)
    {
        while(fgets(line, sizeof(line), file1) != NULL)
        {
            printf("%s", line);
        }
    
        fclose(file1);
    } 
    file1 = fopen("text.txt", "r");
    file2 = fopen("text1.txt", "w");
 
    while (fgets(line, sizeof(line), file1) != NULL && sch < 3) {
        fputs(line, file2);
        sch++;
    }
    fclose(file2);
    printf("\n");
    file2 = fopen("text1.txt", "r");
    printf("Содержимое файла в файл записи:\n");
    
    if(file2)
    {
        while(fgets(line, sizeof(line), file2) != NULL)
        {
            printf("%s", line);
        }
        fclose(file2);
    } 
    
    fclose(file1);
    
    return 0;
}
