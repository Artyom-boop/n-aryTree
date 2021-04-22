#include "tree.h"
#include "../test/test.h"


/*
 * Демонстрационная программа
 * первый аргумент - сколько чисел считать из файла
 * второй аргумент - входной файл(input.txt)
 * третий аргумент - выходной файл(out.txt)
 */
int main(int n, char *arr[]) {
    FILE *input;
    input = fopen(arr[2], "r");
    size_t size = *arr[1] - '0';
    int data[size];
    for (int i = 0; i < size; i++) {
        fscanf(input, "%d", &data[i]);
        printf("%d\n", data[i]);
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
    runTest();
    return 0;
}