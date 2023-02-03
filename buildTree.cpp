#include "buildTree.h"
#include "node.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node *newNode(string word) {
    struct node* temp = new node();
    //temp->key = strdup(item);
    temp->left = NULL;
    temp->right = NULL;
	temp->word = word;
    temp->data = word.length();
    return temp;
};

void addWordToNode(struct node* root, string word) {
	root->word += " " +  word;	
}
/* Adapted from https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ */
struct node* insert(struct node* root, string word, int value) {
    if (!root) {
        return newNode(word);
    }
    if (value > root->data) {
        root->right = insert(root->right,word, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left,word, value);
    }
    else {
    	addWordToNode(root, word);
    }
    return root;
}

struct node* buildTree(string filename) {
    //struct node* root = NULL;
	ifstream buildTreeFile(filename);
	string read;
	buildTreeFile >> read;
    struct node* build = insert(NULL, read, read.length());
	while(buildTreeFile >> read) {
        for (int i = 0; i < read.length(); i++) {
            if (static_cast<int>(read[i]) > 122 || static_cast<int>(read[i]) < 97) {
                cout << "Error. Invalid character detected.";
                exit(1);
            }
        }
		insert(build, read, read.length());
	}
    return build;
}
