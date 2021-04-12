#include "tree.h"
#include "../test/test.h"

int main() {
    struct node* node = add(NULL, 2);
    add(node, 4);
    add(node, 5);
    add(node -> children[0], 6);
    add(node -> children[0], 7);
    add(node -> children[1], 8);
    printConsole(node, 1);
    removeNode(node ->children[0]);
    printConsole(node, 1);
    printf("%d",(node ->children[2]) -> root ->value);
    FILE *outFile;
    outFile = fopen("out.txt" ,"w");
    printFile(node, 1, outFile);
    fclose(outFile);
    runTest();
    return 0;
}