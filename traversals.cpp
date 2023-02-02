#include <iostream>
#include "node.h"
#include <fstream>
#include <queue>
using namespace std;

void printInOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	printInOrder(node->left, level + 1, fileName);
	ofstream f(fileName + ".inorder", fstream::app);
	f << string(level * 4, ' ') << level << " " << node->data << " " << node->word << endl;	
	f.close();
	printInOrder(node->right, level + 1, fileName);
}

void printPreOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	ofstream f(fileName + ".preorder", fstream::app);
	f << string(level * 4, ' ') << level << " " << node->data << " " << node->word << endl;
	f.close();
	printPreOrder(node->left, level + 1, fileName);
	printPreOrder(node->right, level + 1, fileName);
}

void printLevelOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	queue<struct node*> lOrderQueue;
	queue<int> levelQueue;

	lOrderQueue.push(node);
	levelQueue.push(level);
	
	ofstream f(fileName + ".levelorder", fstream::app);
	while(lOrderQueue.empty() == false) {
		f << string(levelQueue.front() * 4, ' ') << levelQueue.front() << " " << lOrderQueue.front()->data << " " << lOrderQueue.front()->word << endl;
		if (lOrderQueue.front()->left != NULL) {
			lOrderQueue.push(lOrderQueue.front()->left);
			levelQueue.push(levelQueue.front() + 1);
		}
		if (lOrderQueue.front()->right != NULL) {
			lOrderQueue.push(lOrderQueue.front()->right);
			levelQueue.push(levelQueue.front() + 1);
		}
		lOrderQueue.pop();
		levelQueue.pop();
	}
	//change f to fout or something similar
	f.close(); 
}



