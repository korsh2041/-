
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10];
    int i;
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; 
    }
    
    printf("Сгенерированный массив:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    
    }
    
    printf("\n");
    
    char text[] ="text1.txt";
    FILE *file = fopen(text,"w");
    for (int i = 9; i >= 0; i--) {
        fprintf(file, "%d ", arr[i]);
    }
    
    fclose(file);
    
    printf("\nЗаписано в файл");
    return 0;
}
