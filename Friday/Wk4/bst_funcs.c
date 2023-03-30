#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int BSTNumNodes(BSTree t) {
    if (t == NULL) return 0;
    return BSTNumNodes(t->left) + BSTNumNodes(t->right) + 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int BSTHeight(BSTree t) {
    if (t == NULL) return -1;
    return max(BSTHeight(t->left), BSTHeight(t->right)) + 1;
}

int BSTNodeLevel(BSTree t, int key) {
    if (t == NULL) return -1;
    if (t->value == key) return 0;
    int level;
    if (key < t->value) {
        level = BSTNodeLevel(t->left, key);
    } else {
        level = BSTNodeLevel(t->right, key);
    }
    
    if (level == -1) return -1;
    return level + 1;
}

int BSTCountGreater(BSTree t, int key) {
    if (t == NULL) return 0;
    if (t->value <= key) return BSTCountGreater(t->right, key);
    return 1 + BSTCountGreater(t->left, key) + BSTCountGreater(t->right, key);
}

int main() {
    BSTree t = readBSTree(0);
    printBSTree(t);
    printf("%d\n", BSTCountGreater(t, 6));
    freeBSTree(t);
}