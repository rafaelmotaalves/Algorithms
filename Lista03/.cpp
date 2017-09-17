#include <bits/stdc++.h>

using namespace std;


struct node
{
	string val;
	string type;
	node* root;
	node* left;
	node* right;

};

node* bst_insert(node* root, string v,string t);
node* bst_search(node* root , string v);
void bst_preorder_print(node* root);
node** bst_remove_min(node* root, string v);
node* bst_remove(node* root, string v);
node* bst_remove_all(node* root);
void bst_inorder_print(node* root);
void bst_postorder_print(node* root);

int main(){


	return 0;
}



node* bst_remove_all(node* root){
	if(root == NULL){
		return root;
	}
	bst_remove_all(root->left);
	bst_remove(root,root->val);
	bst_remove_all(root->right);

}


node* bst_insert(node* root, string v,string t){
	if(root == NULL){
		node* n = new node();
		n->val = v;
		n->type = t;
		n->left = NULL;
		n->right = NULL;
		return n;
	}else if ( root->val > v ){
		root->left = bst_insert(root->left,v,t);
		return root;
	}else if ( root->val < v){
		root->right = bst_insert(root->right,v,t);
		return root;
	}else{
		cout << "File exists\n";
		return root;
	}

}

node* bst_search(node* root , string v){
	if(root == NULL){
		return NULL;
	}else if ( v == root->val){
		return root;
	}else if (v < root->val){
		return bst_search(root->left,v);
	}else{
		return bst_search(root->right,v);
	}
}


node** bst_remove_min(node* root, string v){
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


node* bst_remove(node* root, string v){
	if(root == NULL){
		cout << "No such file or directory\n";
		return NULL;
	}else if ((v) < root->val){
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
			node** aux = bst_remove_min(root->right,v);
			root->right = aux[0];
			root->val = aux[1]->val;
			delete[] aux;
			return root;
		}
	}
}

void bst_inorder_print(node* root){
	if(root == NULL){
		return;
	}
	bst_inorder_print(root->left);
	cout << root->val << endl;
	bst_inorder_print(root->right);

}

void bst_preorder_print(node* root){
	if(root == NULL){
		return;
	}
	cout << root->val << endl;
	bst_inorder_print(root->left);
	bst_inorder_print(root->right);

}

void bst_postorder_print(node* root){
	if(root == NULL){
		return;
	}
	bst_inorder_print(root->left);
	bst_inorder_print(root->right);
	cout << root->val << endl;

}