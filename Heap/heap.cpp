#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v;
	int peso;
	node *next;
};

node* insert(node* curr,int v,int p){
	node* n = new node;
	n->v = v;
	n->peso = p;
	n->next = curr->next;
	curr->next = n;
	return curr;
}

void printl(node* head){
	node* curr = head->next;
	while(curr != NULL){
		std::cout<<curr->v<<" "<<curr->peso << " | ";
		curr = curr->next;
	}
}

struct heap_node
{
	int p;
	int v;
	
};

class Min_heap
{
private:
	int heap_size;
	int array_size;
	heap_node *prioritys;
	int *values;
public:


Min_heap(int size){
	heap_size = 0;
	array_size = size;
	prioritys = new heap_node[size];
	values = new int[100];
	for(int i = 0 ; i < 100; i++){
		values[i] = -1;
	}
}


~Min_heap(){
	delete[] values;
	delete[] prioritys;
}

void insert(int v, int p){
	if(heap_size == array_size){
		doubleSize();
	}

	values[v] = heap_size;
	prioritys[heap_size].p = p;
	prioritys[heap_size].v = v;
	heap_size++;
	bubbleup();

}

void bubbleup(){
	int i = heap_size - 1;
	while(i>0 && prioritys[i].p <= prioritys[(int)floor((i-1)/2)].p){
			values[prioritys[i].v] = (int)floor((i-1)/2);
			values[prioritys[(int)floor((i-1)/2)].v] = i;
			heap_node aux = prioritys[i];
			prioritys[i] = prioritys[(int)floor((i-1)/2)];
			prioritys[(int)floor((i-1)/2)] = aux;
			i = floor((i-1)/2);
	}

}

void doubleSize(){
	array_size*=2;
	heap_node *auxp = new heap_node[array_size];
	int *auxv = new int[array_size];
	for(int i = 0 ; i < array_size ; i++){
		if(i < heap_size){
			auxp[i].p = prioritys[i].p;
			auxp[i].v = prioritys[i].v;
		}else{
			auxp[i].p = -1;
			auxp[i].v = -1;
		}
	}
	delete[] prioritys;
	prioritys = auxp;
}

void heapify(int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int m = i;
	if(l < heap_size && prioritys[l].p <= prioritys[m].p){
		m = l;
	}
	if(r < heap_size && prioritys[r].p <= prioritys[m].p){
		m = r;
	}
	if(m != i){
		values[prioritys[m].v] = i;
		values[prioritys[i].v] = m;
		heap_node aux = prioritys[i];
		prioritys[i] = prioritys[m];
		prioritys[m] = aux;
		heapify(m);
	}
}


heap_node extract(){
	heap_node r;
	if(heap_size != 0){
		r = prioritys[0];
		values[prioritys[0].v] = -1;
		values[prioritys[heap_size-1].v] = 0;
		prioritys[0] = prioritys[heap_size-1];
		heap_size--;
		heapify(0);
	}
	return r;
}

void print(){
	for(int i=0 ; i < heap_size ; i++){
		cout << prioritys[i].p <<  " ";
	}
	cout << endl;
	for(int i=0 ; i < 100; i++ ){
		cout << values[i] << " ";
	} 
}

void heap_update(int v , int p ){
	if(values[v] == -1){
		insert(v,p);
	}else{
		prioritys[values[v]].p = p;
		bubbleup();
	}
}

};

int main(){
	Min_heap * mh = new Min_heap(5);

	mh->insert(0,10);

	mh->heap_update(1,20);
	mh->heap_update(2,5);
	mh->heap_update(10,11);

	cout << mh->extract().p << endl;
	cout << mh->extract().p << endl;

	mh->print();



	return 0;
}