#include <iostream>
#include "minHeap.h"
#include "linkedList.h"

using namespace std;

#ifndef GRAPH
#define GRAPH

class Grafo{
private:
	node **e;
	int size;
public:
	Grafo(int size){
		this->size = size;
		e = new node*[size];
		for(int i = 0 ; i< size; i++){
			e[i] = new node;
		}
	}

	void inserirAresta(int a,int b,int peso){
		insert(e[a],b,peso);
		insert(e[b],a,peso);

	}

	void dijkstra(int s,int cidades[], int tarifas[],int destino){
		int *d = new int[size];
		for(int i = 0 ; i < size ; i++){
			d[i] = 0x3f3f3f3f;
		}
		d[s] = 0;
		Min_heap *h = new Min_heap(size);
		h->insert(s,0);
		for(int i = 0 ; i < size ; i++){
			heap_node a = h->extract();
			int u = a.v;
			node *curr = e[u]->next;
			while( curr != NULL){
				if( d[u] + curr->peso <= d[curr->v]){
					d[curr->v] = (d[u] + curr->peso);
					h->heap_update(curr->v,d[curr->v]);
				}
				curr = curr->next;
			}
		}

		delete h;
		cout << d[destino];
		delete[] d;

	}

};

#endif