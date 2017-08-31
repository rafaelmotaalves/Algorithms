#include <bits/stdc++.h>
#define endl '\n'


#ifndef LINKED_H
#define LINKED_H

struct node{
	int val;
	node* next;
};


class List{
private:
	node* head;
public:
	List(){
		head = new node;
		head->next = NULL;
	}

	node* insert(node* curr,int v){
		node* n = new node;
		n->val = v;
		n->next = curr->next;
		curr->next = n;
		return curr;
	}

	node* append(int v){
		node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		return insert(curr,v);
	}

	node* pos(int pos){
		node* curr = head;
		int i=0;
		while(i<pos && curr!= NULL){
			curr = curr->next;
			i++;
		}
		return curr;
	}

	node* find(int v){
		node* curr = head;
		while(curr->next != NULL && curr->next->val != v){
			curr = curr->next;
		}
		return curr;
	}

	node* remove(node* curr){
		node* pointer = curr->next;
		curr->next = pointer->next;
		delete pointer;
		return curr;
	}

	void print(){
		node* curr = head->next;
		while(curr != NULL){
			std::cout<<curr->val<<"\n";
			curr = curr->next;
		}
	}


};

#endif