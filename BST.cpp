#include <iostream>


using namespace std;


struct node
{
	int val;
	node* left;

	node* right;
};

node* insert(node* root, int v);
node* search(node* root ,int  v);
void preorder_print(node* root);

int main(){
	node* root = NULL;

    insert(root,1);
    insert(root,2);
    insert(root,10);
    insert(root,5);
    insert(root,9);
    insert(root,7);


    node* find;

    find =  search(root,10);

    cout << find->val << endl;

    preorder_print(root);

	return 0;
}

node* insert(node* root, int v){
	if(root == NULL){
		node* n = new node();
		n->val = v;
		n->left = NULL;
		n->right = NULL;
		return n;
	}else if (root->val >= v){
		root->left = insert(root->left,v);
		return root;
	}else{
		root->right = insert(root->right,v);
		return root;
	}

}

node* search(node* root , int v){
	if(root == NULL){
		return NULL;
	}else if (v == root->val){
		return root;
	}else if (v < root->val){
		return search(root->left,v);
	}else{
		return search(root->right,v);
	}
}

void preorder_print(node* root){
	if(root == NULL){
		return;
	}
	preorder_print(root->left);
	cout << root->val << endl;
	preorder_print(root->right);


}