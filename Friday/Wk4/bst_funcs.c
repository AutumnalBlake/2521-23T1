#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    BSTree t = readBSTree(0);
    printBSTree(t);
    freeBSTree(t);
}