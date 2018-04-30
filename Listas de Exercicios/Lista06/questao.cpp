#include <bits/stdc++.h>


using namespace std;


class DisjointSet{
private:
	int* d;
public:


	DisjointSet(int n){
		d = new int[n];
		for(int i = 0; i < n; i++) {
        	d[i] = i;
    	}
	}

	void union_set(int a,int b){
		d[a] = b;
	}


	int find(int a) {
    	if(a != d[a]) {
        	d[a] = find(d[a]);
    	}
        return d[a];
	}

};



struct aresta
{
	int u;
	int v;
	int peso;

};

int partition(aresta* arr, int p, int r) {
    aresta x = arr[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(arr[j].peso <= x.peso) {
            i += 1;
            aresta aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    aresta aux = arr[i+1];
    arr[i+1] = arr[r];
   	arr[r] = aux;
    return i+1;
}

void qsort(aresta* A, int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        qsort(A, p, q-1);
        qsort(A, q+1, r);
    }
}


void quickSort(aresta* arr,int size){
	qsort(arr,0,size-1);
}


int kruskal(aresta* arr,int n, int m) {
	quickSort(arr,m);
    DisjointSet *ds = new DisjointSet(n);
    int cost = 0;
    for(int i = 0; i < m; i++) {
       int peso = arr[i].peso;
       int x = ds->find(arr[i].u);
       int y = ds->find(arr[i].v);
       if(x != y) {
            ds->union_set(x, y);
            cost = cost + peso;
        }
    }
    return cost;
}

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



struct queue_node
{
	int v;
	queue_node * next;
	
};

class Queue{
private:

	queue_node* front;
	queue_node* rear;

public:
	Queue(){
		this->front = new queue_node;//sentinela
		this->front->next = NULL;
		this->rear = this->front;
	}

	queue_node* enqueue(int s){
		queue_node* newqueue_node = new queue_node;
		newqueue_node->v = s;
		newqueue_node->next = NULL;
		this->rear->next = newqueue_node;
		rear = newqueue_node;
		return rear;
	}

	int dequeue(){
		queue_node* pointer = front->next;
		front->next = pointer->next;
		int r = pointer->v;
		delete pointer;
		if(front->next == NULL){
			rear = front;
		}
		return r;
	}

	bool isEmpty(){
		return front == rear;
	}

};

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

	int bfs_path(int s){
		int *d = new int[size];
		for(int i=0; i < size; i++){
			d[i] = -1;
		}
		d[s] = 0;
		int cost = 0;
		Queue q;
		q.enqueue(s);
		while(!q.isEmpty()){
			int u = q.dequeue();
			node* curr = e[u];
			while(curr != NULL){
				int v = curr->v;
				if(d[v] == -1){
					d[v] = d[u] + 1;
					cost+=d[v];
					q.enqueue(v);
				}
				curr = curr->next;
			}
		}
		return cost;

	}

	void inserirAresta(int a,int b,int peso){
		insert(e[a],b,peso);
		insert(e[b],a,peso);

	}



};


int main(){
	int n, m;


    scanf("%d %d",&n,&m);

	int c, r;

    scanf("%d %d",&c,&r);

	aresta *arr = new aresta[m];
	Grafo *gr = new Grafo(n);


	int u,v,l;

	for(int i = 0 ; i < m ; i ++){
	    
        scanf("%d %d %d",&u,&v,&l);
		arr[i].u = u;
		arr[i].v = v;
		arr[i].peso = l;

		gr->inserirAresta(u,v,l);
	}

	cout << kruskal(arr,n,m) * c << " ";
	cout << gr->bfs_path(0) * r;


	return 0;
}