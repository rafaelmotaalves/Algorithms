#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct Node{
	int val;
	Node* next;
};

class Queue{
private:

	Node* front;
	Node* rear;

public:
	Queue(){
		this->front = new Node;//sentinela
		this->front->next = NULL;
		this->rear = this->front;
	}

	int getFrontVal(){
		return this->front->next->val;
	}

	Node* enqueue(int v){
		Node* newNode = new Node;
		newNode->val = v;
		newNode->next = NULL;
		this->rear->next = newNode;
		rear = newNode;
		return rear;
	}

	Node* dequeue(){
		Node* pointer = front->next;
		front->next = pointer->next;
		delete pointer;
		if(front->next == NULL){
			rear = front;
		}
		return front;
	}

	void print(){
		Node* curr = front->next;
		while(curr != NULL){
			std::cout<<curr->val<<" ";
			curr = curr->next;
		}
	}


};
#endif