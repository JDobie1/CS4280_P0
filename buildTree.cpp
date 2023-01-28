#include "buildTree.h"
#include "node.h"
#include <iostream>
#include <string>

struct node *newNode(int item) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        //temp->key = strdup(item);
        temp->left = NULL;
        temp->right = NULL;
        temp->data = item;
        return temp;
};

/* Adapted from https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ */
struct node* insert(struct node* root, int value) {
    if (!root) {
        return newNode(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}

struct node* buildTree(FILE* f) {
    struct node* root = NULL;
    //Read from the file passed in
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 6);
    insert(root, 10);
    insert(root, 1);
    insert(root, 14);

    return root;
}

static void printParseTree(struct node* root, int level) { 
    if (root == NULL) return; 
    printf("%*c%d:",level*4,' ',level); // assume some info printed as string 
    printf("\n"); 
    printParseTree(root->left,level+1); 
    printParseTree(root->right,level+1); 
} 