#include "tree.h"

/*
 * Демонстрационная программа
 * первый аргумент - сколько чисел считать из файла
 * второй аргумент - входной файл(input.txt)
 * третий аргумент - выходной файл(out.txt)
 */
int main(int n, char *arr[]) {
    if (n == 1) {
        printf("The command line has no arguments\n");
        return 0;
    }
    FILE *input;
    input = fopen(arr[2], "r");
    size_t size = *arr[1] - '0';
    int data[size];
    for (int i = 0; i < size; i++) {
        fscanf(input, "%d", &data[i]);
    }
    fclose(input);
    struct node* node = add(NULL, data[0]);
    for (int i = 1; i < size; i++) {
        add(node, data[i]);
    }
    FILE *outFile;
    outFile = fopen(arr[3] ,"w");
    printFile(node, 1, outFile);
    fclose(outFile);
    return 0;
}