#include<bits/stdc++.h>
using namespace std;

struct node{
	node *left,*right;
	int key;
};

node* newNode(){
	static int k = 0;
	k++;
	node *n = new node();
	n->left = NULL;
	n->right = NULL;
	n->key = k;
	return n;
}
// 		 (1)
// 		/	\
// 	 (2)    (3)
// 	/  \     /  \
// (4)  (5) (6) (7)

void preorder(node *root){
	if(root == NULL) return;
    
	cout<<root->key<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
    node *root = newNode();
	root->left = newNode(); 
	root->right = newNode();
	root->left->left = newNode();
	root->left->right = newNode(); 
	root->right->left = newNode(); 
	root->right->right = newNode();

	preorder(root);	 
	cout<<"\n";
 return 0;
}
