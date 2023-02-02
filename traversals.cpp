#include <iostream>
#include "node.h"
#include <fstream>
#include <queue>
using namespace std;

void traverseInOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	traverseInOrder(node->left, level + 1, fileName);
	ofstream inOrder(fileName + ".inorder", fstream::app);
	inOrder << string(level * 4, ' ') << level << " " << node->data << " " << node->word << endl;	
	inOrder.close();
	traverseInOrder(node->right, level + 1, fileName);
}

void traversePreOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	ofstream preOrder(fileName + ".preorder", fstream::app);
	preOrder << string(level * 4, ' ') << level << " " << node->data << " " << node->word << endl;
	preOrder.close();
	traversePreOrder(node->left, level + 1, fileName);
	traversePreOrder(node->right, level + 1, fileName);
}

void traverseLevelOrder(struct node* node, int level, string fileName) {
	if (node == NULL) {
		return;
	}
	queue<struct node*> lOrderQueue;
	queue<int> levelQueue;

	lOrderQueue.push(node);
	levelQueue.push(level);
	
	ofstream levelOrder(fileName + ".levelorder", fstream::app);
	while(lOrderQueue.empty() == false) {
		levelOrder << string(levelQueue.front() * 4, ' ') << levelQueue.front() << " " << lOrderQueue.front()->data << " " << lOrderQueue.front()->word << endl;
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
	levelOrder.close(); 
}



