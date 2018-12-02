#include<iostream>
using namespace std;
struct tree {
	int data;
	tree* left;
	tree* right;
};
tree* creatNode(int data) {
	tree* u = new tree;
	u->data = data;
	u->left = u->right = NULL;
	return u;
}
void insert(tree* &root,int data) {
	if (root != NULL) {
		if (root->data < data)insert(root->right, data);
		else if (root->data > data)insert(root->left, data);
		else return;
	}
	else { root = creatNode(data); }
}
void deltree(tree* & root) {
	if (root != NULL) {
		deltree(root->left);
		deltree(root->right);
		delete root;
	}
}
tree* findrightmin(tree* root){
	tree* u = root;
	root = root->right;
	while (root->left != NULL) {
		u = root;
		root = root->left;
	}
	if (u->left == root)u->left = root->right;
	else if (u->right == root)u->right = root->right;
	return root;
	
}
void delnode(tree*& root,int data){
	if (root != NULL) {
		if (root->data > data)delnode(root->left, data);
		else if (root->data < data)delnode(root->right, data);
		else {
			tree* u = NULL;
			if (root->left == NULL) {
				u = root;
				root = root->right;
			}
			else if (root->right == NULL) {
				u = root;
				root = root->left;
			}
			else {
				u = findrightmin(root);
				root->data = u->data;
			}
			delete u;
		}
	}
}
void LNR(tree* root){
	if (root != NULL) {
		LNR(root->left);
		cout << root->data << '\t';
		LNR(root->right);
	}
	
}
void main(){
	int a[] = { 12,54,1,2,3,0,4,5 };
	int n = sizeof(a) / sizeof(int);
	tree* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, a[i]);
	}
	LNR(root);
	cout << endl;
	for (int i = n-1; i >=0; i--) {
		delnode(root, a[i]);
		LNR(root);
		cout << endl;
	}
	LNR(root);
	deltree(root);

}