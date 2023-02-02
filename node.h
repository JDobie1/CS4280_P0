#ifndef NODE_H
#define NODE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
struct node {
        int data;
	std::string word;
        //char* key;
        struct node* left;
        struct node* right;
};
#endif
