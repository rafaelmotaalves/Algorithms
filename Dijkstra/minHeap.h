#include <bits/stdc++.h>

#ifndef MINHEAP
#define MINHEAP 

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
	for(int i = 0 ; i < size; i++){
		values[i] = -1;
	}
}


~Min_heap(){
	delete[] values;
	delete[] prioritys;
}

void insert(int v, int p){
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

void heap_update(int v , int p ){
	if(values[v] == -1){
		insert(v,p);
	}else{
		prioritys[values[v]].p = p;
		bubbleup();
	}
}

};
#endif