#include <bits/stdc++.h>

using namespace std;

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
	values = new int[size];
	for(int i = 0 ; i < size ; i++){
		values[i] = -1;
		prioritys[i].p = -1;
		prioritys[i].v = -1;
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

void bubbleup(){//errado
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
			auxv[i] = values[i];
		}else{
			auxp[i].p = -1;
			auxp[i].v = -1;
			auxv[i] = -1; 
		}
	}
	delete[] prioritys;
	delete[] values;
	prioritys = auxp;
	values = auxv;
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
		heap_node aux = prioritys[i];
		prioritys[i] = prioritys[m];
		prioritys[m] = aux;
		values[prioritys[i].v] = m;
		values[prioritys[m].v] = i;
		heapify(m);
	}
}


heap_node extract(){
	heap_node r;
	if(heap_size != 0){
		r = prioritys[0];
		prioritys[0] = prioritys[heap_size-1];
		values[heap_size-1] = -1;
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
	for(int i=0 ; i < array_size; i++ ){
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
	mh->insert(1, 5);
	mh->insert(2, 4);
	mh->insert(3,6);

	mh->heap_update(3,1);

	mh->print();

	return 0;
}