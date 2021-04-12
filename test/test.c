#include "test.h"
#include "../src/tree.h"

int testAdd(struct node* root);

int testRemove(struct node* root);

int runTest() {
    srand(time(NULL));
    struct node *root = add(NULL, 1);
    printf("test add and addNode\n");
    testAdd(root);
    printConsole(root, 1);
    testAdd(root ->children[0]);
    printConsole(root, 1);
    printf("test add and addNode completed\n");
    for (int i = 0; i < N; ++i) {
        setValue(root ->children[i], i);
        assert(i == getValue(root ->children[i]));
    }
    printf("test removeNode and removeNodeAndChildren\n");
    testRemove(root);
    printf("test removeNode and removeNodeAndChildren completed\n");
    printf("test clearTrie\n");
    clearTrie(root);
    assert(0 == getSizeChildren(root));
    for (int i = 0; i < N; ++i) {
        root = add(NULL, 1);
        testAdd(root);
        printConsole(root, 1);
        clearTrie(root);
        assert(0 == getSizeChildren(root));
        printConsole(root, 1);
    }
    printf("test clearTrie completed\n");
}

int testAdd(struct node* root) {
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // диапазон случайных чисел от 0 до 100
        if (arr[i] % 2 == 0)
            add(root, arr[i]);
        else {
            struct node *node = add(NULL, arr[i]);
            addNode(root, node);
        }
        assert(arr[i] == getValue(root->children[i]));
        assert(root == getRoot(root->children[i]));
    }
    assert(N == root->countChildren);
    return 0;
}

int testRemove(struct node* root) {
    printConsole(root, 1);
    printf("launch removeNodeAndChildren\n");
    removeNodeAndChildren(root ->children[0]);
    printConsole(root, 1);
    assert(N - 1 == root ->countChildren);
    for (int i = 0; i < N - 1; ++i) {
        assert(i + 1 == getValue(root ->children[i]));
        assert(0 == getSizeChildren(root ->children[i]));
    }
    struct node* node = root ->children[1];
    for (int i = 0; i < N; ++i) {
        add(node, i);
        assert(i == getValue(node ->children[i]));
    }
    printConsole(root, 1);
    printf("launch removeNode\n");
    removeNode(node);
    printConsole(root, 1);
    assert(2 != getValue(root ->children[1]));
    assert(2 * N - 2 == getSizeChildren(root));
    for (int i = 0; i < N; ++i) {
        assert(i == getValue(root ->children[i + N - 2]));
    }
    return 0;
}
