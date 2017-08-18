#include <iostream>

using namespace std;
	struct Node
	{
		int val;
		Node* next;
	};

class Stack{
private:

	Node* top;

public:
	Stack(){
		this->top = new Node;
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
			cout<<curr->val<<" ";
			curr = curr->next;
		}
	}

};

class Queue{
private:

	Node* front;
	Node* rear;

public:
	Queue(){
		this->front = new Node;
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
			cout<<curr->val<<" ";
			curr = curr->next;
		}
	}


};

int main(){
	Stack *memsec = new Stack();
	Queue *buffer = new Queue();

	string func;
	int q,p,K,current=0,bf=0,cont=1,qtdnamem=0;

	cin>>q;
	cin>>p;

	while(cin>>func>>K){
		
		if(func == "RECV"){
			for (int i= 0; i < K;i++){
				if( bf < q ){
					buffer->enqueue(current);
					bf++;
				}else{
					memsec->push(current);
					qtdnamem++;
				}
				current++;
			}
		}else{
			    int aux = bf;
				for(int i=0;i< K && i < aux; i++){
					cout << buffer->getFrontVal() <<" ";
					buffer->dequeue();
					bf--;
				}
				cout<<endl;
		}
		
		
		
		if( cont % p == 0){
			int qtdrealocada=0;
			for(int i= 0 ; i < (q - bf) && i < qtdnamem ; i ++){
				qtdrealocada++;
				int x = memsec->getTopVal();
				buffer->enqueue(x);
				memsec->pop();
			}
			bf+=qtdrealocada;
			qtdnamem -= qtdrealocada;
		}
		
		
		cont++;

	}
	
	buffer->print();
	cout<<endl;
	memsec->print();
	
	return 0;
};