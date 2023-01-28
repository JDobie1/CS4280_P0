#ifndef NODE_H
#define NODE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        //char* key;
        struct node* left;
        struct node* right;
};
#endif
