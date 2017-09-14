#include <iostream>

using namespace std;



struct node
{
	int val;
	node* left;

	node* right;

node* bst_insert(node* root, int v){
	if(root == NULL){
		node* n = new node();
		n->val = v;
		n->left = NULL;
		n->right = NULL;
		return n;
	}else if (root->val >= v){
		root->left = bst_insert(root->left,v);
		return root;
	}else{
		root->right = bst_insert(root->right,v);
		return root;
	}

}

node* bst_search(node* root , int v){
	if(root == NULL){
		return NULL;
	}else if (v == root->val){
		return root;
	}else if (v < root->val){
		return bst_search(root->left,v);
	}else{
		return bst_search(root->right,v);
	}
}

void bst_preorder_print(node* root){
	if(root == NULL){
		return;
	}
	bst_preorder_print(root->left);
	cout << root->val << endl;
	bst_preorder_print(root->right);

}

node** bst_remove_min(node* root, int v){
	if(root->left == NULL){
		node** aux = new node*[2];
		aux[0] = root->right;
		aux[1] = root;
		return aux;
	}else{
		node** aux = bst_remove_min(root->left,v);
		root->left = aux[0];
		aux[0] = root;
		return aux;

	}
}

};

node* bst_remove(node* root, int v){
	if(root == NULL){
		cout << "value not found" << endl;
		return NULL;
	}else if (v < root->val){
		root->left = bst_remove(root->left,v);
		return root;
	}else if (v > root->val){
		root->right = bst_remove(root->right,v);
	}else{
		if(root->left == NULL){
			node* r = root->right;
			delete root;
			return r;
		}else if (root->right == NULL){
			node* l = root->left;
			delete root;
			return l;
		}else{
			node** aux = root->bst_remove_min(root->right,v);
			root->right = aux[0];
			root->val = aux[1]->val;
			delete[] aux;
			return root;
		}
	}
}

int bst_height(node* root){
	if(root == NULL){
		return 0;
	}else{
		int l = bst_height(root->left);
		int r = bst_height(root->right);
		return 1 + max(l,r);
	}
}


class BinarySearchTree{
private:
	node* root;

public:

	BinarySearchTree(){
		root = NULL;
	};

	void insert(int v){
		root = bst_insert(root,v);
	}

	node* search(int v){
		root = bst_search(root,v);
	}

	void preorder_print(){
		bst_preorder_print(root);
	}

	void remove(int v){
		root = bst_remove(root,v);
	}

	int getHeight(){
		return bst_height(root);
	}

};


int main(){
	BinarySearchTree *bst = new BinarySearchTree();

	bst->insert(4);
	bst->insert(30);
	bst->insert(7);
	bst->insert(3);
	bst->insert(1);
	bst->insert(0);
	bst->insert(50);
	bst->insert(90);
	bst->insert(100);

	cout << bst->getHeight() << endl;


	bst->preorder_print();


	return 0;
}
