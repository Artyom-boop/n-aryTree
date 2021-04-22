#include "tree.h"

int getValue(struct node* node) {
    return  node -> value;
}

void setValue(struct node* node, int value) {
    node -> value = value;
}

unsigned getSizeChildren(struct node* node) {
    return  node -> countChildren;
}

struct node* getChildren(struct node* node) {
    return *(node -> children);
}

struct node* getRoot(struct node* node) {
    return node -> root;
}

void addNode(struct node* root, struct node* node) {
    if (root ->countChildren == 0)
        root -> children = calloc((root ->countChildren) + 1,sizeof(struct node));
    else
        root->children = realloc(root->children, sizeof(struct node) * ((root->countChildren) + 1));
    (root->children)[root->countChildren] = node;
    node -> root = root;
    root->countChildren++;
}

struct node* add(struct node* node, int value) {
    if (node == NULL) {
        node = (struct node*)malloc(sizeof(struct node));
        node -> value = value;
        node -> countChildren = 0;
    } else {
        node -> countChildren++;
        unsigned n = node ->countChildren;
        struct node* nodeNew;
        nodeNew = (struct node*)malloc(sizeof(struct node));
        nodeNew -> value = value;
        nodeNew -> countChildren = 0;
        nodeNew -> root = node;
        if (n == 0)
            n++;
        struct node* children1[n];
        children1[n - 1] = nodeNew;
        for (int i = 0; i < n - 1; ++i) {
            children1[i] = node ->children[i];
        }
        node -> children = calloc((node ->countChildren) + 1,sizeof(struct node));
        for (int i = 0; i < n; ++i) {
            node ->children[i] = children1[i];
        }
    }

    return node;
}

void removeNodeAndChildren(struct node* children) {
    struct node *root = children ->root;
    for (int i = 0; i < root -> countChildren; i++) {
        if (children == root -> children[i]) {
            for (int j = i + 1; j < root -> countChildren; j++) {
                root -> children[j - 1] = root -> children[j];
            }
            root -> children = realloc(root -> children, sizeof(int) * (root -> countChildren - 1));
            root -> countChildren--;
            return;
        }
    }
}

void removeNode (struct node* node) {
    unsigned  n = node -> countChildren;
    struct node* root = node -> root;
    struct node* children1[n];
    for (int i = 0; i < n; ++i) {
        children1[i] = node -> children[i];
    }
    removeNodeAndChildren(node);
    free(node);
    for (int i = 0; i < n; ++i) {
        addNode(root, children1[i]);
    }
}

void clearTrie(struct node* root) {
    unsigned size = getSizeChildren(root);
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            removeNodeAndChildren(root->children[0]);
        }
    }
    free(root);
}

void printConsole(struct node* node, int level) {
    unsigned n = node->countChildren;
    if (level == 1) {
        printf("level %d(root): %d\n", level, node->value);
        level++;
    }
    printf("level %d(root = %d): ", level, node->value);
    for (int i = 0; i < n; i++) {
        printf(" %d ", node->children[i]->value);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if ((node->children[i])->countChildren > 0)
            printConsole(node->children[i], level + 1);
    }
}

void printFile(struct node *node, int level, FILE *out) {
    unsigned n = node->countChildren;
    if (level == 1) {
        fprintf(out,"level %d(root): %d\n", level, node->value);
            level++;
    }
    fprintf(out,"level %d(root = %d): ", level, node->value);
    for (int i = 0; i < n; i++) {
        fprintf(out," %d ", node->children[i]->value);
    }
    fprintf(out,"\n");
    for (int i = 0; i < n; i++) {
        if ((node->children[i])->countChildren > 0)
            printFile(node->children[i], level + 1, out);
    }
}

