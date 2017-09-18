#include <bits/stdc++.h>

using namespace std;


struct node
{
	string val;
	string type;
	node* root;
	node* left;
	node* right;

	node(string v , string t){
		val = v;
		type =t;
		root = NULL;
		left = NULL;
		right =NULL;
	}

};


struct Stacknode{
	node* curr;
	Stacknode* next;

	Stacknode(node* c,Stacknode* n){
		curr = c;
		next = n;
	}	
};

class Stack{
private:

	Stacknode* top;

public:
	Stack(){
		this->top = new Stacknode(NULL,NULL);//sentinela
	}

	node* get(){
		return top->next->curr;
	}

	Stacknode* push(node* curr){
		Stacknode* newStacknode = new Stacknode(curr,this->top->next);
		this->top->next = newStacknode;
		return top;
	}

	Stacknode* pop(){
		Stacknode* pointer = top->next;
		top->next = pointer->next;
		return top;

	}


};


node* bst_insert(node* root, string v,string t);
node* bst_search(node* root , string v);
node** bst_remove_min(node* root, string v);
node* bst_remove(node* root, string v);
void bst_ls_print(node* root);
void bst_tree_inorder(node* ,int n);
node* bst_remove_all(node* root);


int main(){
	Stack current;

	node* dirprincipal = new node("/","dirprincipal");

 	current.push(dirprincipal);

 	string func;
 	string v;


 	while(cin >> func){


	 	if(func == "cd"){
	 		cin >> v;
	 		if(v != ".."){
	 			node* aux = bst_search(current.get()->root,v);
	 			if(aux == NULL){
	 				cout << "No such file or directory\n";
	 			}else if(aux->type != "dir"){
	 				cout << "Not a directory\n";
	 			}else{
	 				current.push(aux);
	 			}
	 		}else if(current.get()->val != "/"){
	 			current.pop();
	 		}
	 	}else if(func == "mkdir"){
	 		cin >> v;
	 		current.get()->root = bst_insert(current.get()->root, v,"dir");
	 	}else if(func == "touch"){
	 		cin >> v;
	 		current.get()->root = bst_insert(current.get()->root,v,"file");
	 	}else if(func == "ls"){
	 		bst_ls_print(current.get()->root);
	 	}else if(func == "pwd"){
	 		cout << current.get()->val << endl;
	 	}else if(func == "rm"){//possivelmente errado
	 		cin >> v;
	 		node* aux = bst_search(current.get()->root,v);
	 		if(aux != NULL){
	 			if(aux->type == "file"){
	 				current.get()->root = bst_remove(current.get()->root,v);
	 			}else{
	 				aux->root = bst_remove_all(aux->root);
	 				current.get()->root =bst_remove(current.get()->root,v);
	 			}
	 		}else{
	 			cout << "No such file or directory\n";
	 		}
	 	}else if(func == "tree"){
	 		cin >> v;
	 		if(v ==  "--in-order"){
	 			bst_tree_inorder(current.get()->root,0);
	 		}
	 	}else{
	 		cout << "Command not found\n";
	 	}

 	}

	return 0;
}

node* bst_remove_all(node* root){
	if(root == NULL){
		return NULL;
	}
	bst_remove_all(root->left);
	bst_remove(root,root->val);
	bst_remove_all(root->right);

}


void bst_tree_inorder(node* root,int n){
	if(root == NULL){
		return;
	}else if(root->type == "dir"){
		for(int i = 0; i<n; i++){
			cout << "    ";
		}
		bst_tree_inorder(root->left,n);
		n++;
		cout << root->val << endl;
		bst_tree_inorder(root->root,n);
		n--;
		bst_tree_inorder(root->right,n);

	}else{
		bst_tree_inorder(root->left,n);
		for(int i = 0 ; i < n ; i++){
			cout << "    ";
		}
		cout << root->val << endl;
		bst_tree_inorder(root->right,n);
	}

}

void bst_tree_preorder(node* root,int n){
	if(root == NULL){
		return;
	}else if(root->type == "dir"){
		for(int i = 0; i<n; i++){
			cout << "    ";
		}
		bst_tree_inorder(root->left,n);
		cout << root->val << endl;
		n++;
		bst_tree_inorder(root->root,n);
		n--;
		bst_tree_inorder(root->right,n);

	}else{
		bst_tree_inorder(root->left,n);
		for(int i = 0 ; i < n ; i++){
			cout << "    ";
		}
		cout << root->val << endl;
		bst_tree_inorder(root->right,n);
	}

}



node* bst_insert(node* root, string v,string t){
	if(root == NULL){
		node* n = new node(v,t);
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
		return NULL;
	}else if ((v) < root->val){
		root->left = bst_remove(root->left,v);
		return root;
	}else if (v > root->val){
		root->right = bst_remove(root->right,v);
		return root;
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


void bst_ls_print(node* root){
	if(root == NULL){
		return;
	}
	bst_ls_print(root->left);
	cout << root->val << endl;
	bst_ls_print(root->right);

}
