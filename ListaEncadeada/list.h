#ifndef LIST_H
#define LIST_H
#include <iostream>

 class List{
 private:

 	struct node
 	{
 		int val;
 		node* next;
 	};

 	node* head;

public:
 	List(){
 		this->head = new node;
 		this->head->next = NULL;
 	}

 	node* getHead(){
 		return this->head;
 	}

 	node* insert(node* curr,int v){
 		node* n = new node;
		n->val = v;
		n->next = curr->next;
		curr->next = n;
		return curr;
 	}
 	void print(){
 		node* curr = head->next;
		while(curr != NULL){
			std::cout<<curr->val<<std::endl;
			curr = curr->next;
		}
	}
 };

#endif
