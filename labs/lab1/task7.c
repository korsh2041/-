#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    const char *text = "text.txt";
    char *str = "привет";
    file = fopen(text, "a");
    fputs(str, file);
    fclose(file);
    printf("Записано");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    char line[256];
    
    FILE *file1, *file2;
    const char *text = "text.txt";
    char *str = "привет";
    
    file1 = fopen(text,"r");
    printf("Записано до:\n");
    
    do {
        printf("%s",line);
    }while(fgets(line,256,file1)!=NULL);
    
    fclose(file1);
    
    // file2 = fopen(text, "a");
    
    // fputs(str, file2);
    
    // printf("\n Записано после:\n");
    // while(fgets(line,256,file2)!=NULL){
    //     printf("%s",line);
    // }
    
    fclose(file2);
    
    return 0;
}
