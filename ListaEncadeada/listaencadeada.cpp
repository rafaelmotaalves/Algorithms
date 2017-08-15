#include <iostream>

using namespace std;

struct node
{
	int val;
	node* next;
};

node* insert(node*,int);
node* pos(node*,int);
node* find(node*,int);
node* remove(node*,node*);
void print(node*);

int main(){
	node* head = new node;//sentinela
	head->next = NULL;
	insert(head,10);
	insert(head,20);
	insert(head,30);
	insert(head,40);
	print(head);
	return 0;
}

node* insert(node* curr,int v){
	node* n = new node;
	n->val = v;
	n->next = curr->next;
	curr->next = n;
	return curr;
}

node* pos(node* head,int pos){
	node* curr = head;
	int i=0;
	while(i<pos && curr!= NULL){
		curr = curr->next;
		i++;
	}
	return curr;
}
node* find(node* head,int v){
	node* curr = head;
	while(curr->next != NULL && curr->next->val != v){
		curr = curr->next;
	}
	return curr;
}

node* remove(node* head,node* curr){
	node* pointer = curr->next;
	curr->next = pointer->next;
	delete pointer;
	return curr;
}

void print(node* head){
	node* curr = head->next;
	while(curr != NULL){
		cout<<curr->val<<endl;
		curr = curr->next;
	}
}