#include <iostream>
#include<string.h>
using namespace std;



struct node
{
	string val;
	string type;
	node* root;
	node* left;
	node* right;

};

struct Stacknode{
	node* curr;
	Stacknode* next;
};

class Stack{
private:

	Stacknode* top;

public:
	Stack(){
		this->top = new Stacknode;//sentinela
		this->top->next = NULL;
	}

	node* getTop(){
		return this->top->next->curr;
	}

	Stacknode* push(node* curr){
		Stacknode* newStacknode = new Stacknode;
		newStacknode->curr = this->top->curr;
		newStacknode->next = this->top->next;
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
void bst_preorder_print(node* root);
node** bst_remove_min(node* root, string v);
node* bst_remove(node* root, string v);
node* bst_remove_all(node* root);
void bst_inorder_print(node* root);
void bst_postorder_print(node* root);



int main(){
	Stack *posicao = new Stack();

	node* dirprincipal = new node();
	dirprincipal->val = '/';
	dirprincipal->type = "dirprincipal";
	dirprincipal->root = NULL;
	dirprincipal->right = NULL;
	dirprincipal->left = NULL;


	posicao->push(dirprincipal);
	node* curr = NULL;
	string func;

	while(cin >> func){

		if(func == "mkdir"){
			string v;
			cin >> v;
			posicao->getTop()->root = bst_insert(posicao->getTop()->root,v,"dir");
		}
		else if(func == "touch"){
			string v;
			cin >>v;
			curr = bst_insert(curr,v,"dir");
		}
		else if(func == "cd"){//quebrado
			string v ;
			cin >> v;
			node* aux;
			if(v != ".."){ 
				aux = bst_search(curr,v);
				if(aux == NULL){
					cout << "No such file or directory\n";
				}else if(aux->type != "dir"){
					cout << "Not a directory\n";
				}else{
					curr = aux->root;
				}
			}else{

		}
		}
		else if(func == "ls"){
			bst_inorder_print(posicao->getTop()->root);
		}
		else if(func == "rm"){//quebrado;
			string v;
			cin >>v;
			node* aux = bst_search(curr,v);
			if(aux->type == "file"){
				bst_remove(curr,v);
			}else{
				bst_remove_all(aux->root);
				bst_remove(curr,v);
			}
		}
		else if(func == "pwd"){
		}
		else if(func == "tree"){//incompleto
			string arg;
			cin >> arg;
			cout << endl;
			if(arg == "--pre-order")
				bst_preorder_print(curr);
			else if(arg == "--in-order")
				bst_inorder_print(curr);
			else if(arg == "--post-order")
				bst_postorder_print(curr);
			else
				cout << "Illegral option\n";
		}else{
			cout << "Command not found\n";
		}
	}

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