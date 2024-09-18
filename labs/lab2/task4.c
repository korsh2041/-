#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortirovka(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

void randmas(float *arr, int size, float arg1, float arg2) {
    for (int i = 0; i < size; i++) {
        arr[i] = arg1 + (float)rand() / RAND_MAX * (arg2 - arg1);
    }
}

void zapisvfile(const char *filename, float *arr, int size) {
    FILE *file = fopen(filename, "w");
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%f\n", arr[i]);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);
    float arg1 = atof(argv[2]);
    float arg2 = atof(argv[3]);

    float *arr = (float *)malloc(size * sizeof(float));
    
    srand(time(NULL));

    randmas(arr, size, arg1, arg2);

    printf("Случайный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", arr[i]);
    }

    qsort(arr, size, sizeof(float), sortirovka);
    
    zapisvfile("сортировка.txt", arr, size);

    printf("Отсортированный массив записан в файл\n");

    return 0;
}
