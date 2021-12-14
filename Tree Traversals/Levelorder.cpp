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

void levelorder(node *root){
	if(root == NULL) return;
    
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *tmp = q.front();
		q.pop();
		cout<<tmp->key<<" ";
		if(tmp->left!=NULL)
			q.push(tmp->left);
		if(tmp->right!=NULL)
			q.push(tmp->right);
	}
}

int main(){
    node *root = newNode();
	root->left = newNode(); 
	root->right = newNode();
	root->left->left = newNode();
	root->left->right = newNode(); 
	root->right->left = newNode(); 
	root->right->right = newNode();

	levelorder(root);	 
	cout<<"\n";
 return 0;
}
