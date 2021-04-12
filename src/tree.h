#include <stdio.h>
#include "stdlib.h"

struct node {
    struct node* root;
    int value;
    struct node* *children;
    int countChildren;
};

int getValue(struct node* node);

void setValue(struct node* node, int value);

int getSizeChildren(struct node* node);

struct node* getChildren(struct node* node);

struct node* getRoot(struct node* node);

struct node* add(struct node* node, int value);

void addNode(struct node* root, struct node* node);

void removeNodeAndChildren(struct node* children);

void removeNode (struct node* node);

void clearTrie(struct node* root);

void printConsole(struct node* node, int level);

void printFile(struct node *node, int level, FILE *out);
