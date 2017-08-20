#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Node{
	int val;
	Node* next;
};

class Stack{
private:

	Node* top;

public:
	Stack(){
		this->top = new Node;//sentinela
		this->top->next = NULL;
	}

	int getTopVal(){
		return this->top->next->val;
	}

	Node* push(int v){
		Node* newNode = new Node;
		newNode->val = v;
		newNode->next = this->top->next;
		this->top->next = newNode;
		return top;
	}

	Node* pop(){
		Node* pointer = top->next;
		top->next = pointer->next;
		delete pointer;
		return top;

	}

	void print(){
		Node* curr = top->next;
		while(curr != NULL){
			std::cout<<curr->val<<" ";
			curr = curr->next;
		}
	}

};

#endif