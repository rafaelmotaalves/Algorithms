#include <bits/stdc++.h>

using namespace std;


struct heap_node
{
	int v;
	int priority;

};

class Min_heap
{
private:
	int heap_size;
	int array_size;
	heap_node* array;
public:
	Min_heap();
	~Min_heap();
	void insert(int v , int p);
	void bubbleup();
	void doubleSize();
	void heapify(int i);
	heap_node extract();
	void print();
	int getHeap_size();
};


Min_heap::Min_heap(){
	heap_size = 0;
	array_size = 2;
	array = new heap_node[2];
}

Min_heap::~Min_heap(){
	delete[] array;
}

void Min_heap::insert(int v, int p){
	if(heap_size == array_size){
		doubleSize();
	}
	heap_node t;
	t.v = v;
	t.priority = p;

	array[heap_size] = t;
	heap_size++;
	bubbleup();

}

void Min_heap::bubbleup(){
	int i = heap_size - 1;
	while(i>0 && array[i].priority <= array[(int)floor((i-1)/2)].priority ){
			heap_node aux = array[i];
			array[i] = array[(int)floor((i-1)/2)];
			array[(int)floor((i-1)/2)] = aux;
			i = floor((i-1)/2);
	}

}

void Min_heap::doubleSize(){
	array_size*=2;
	heap_node *aux = new heap_node[array_size];
	for(int i = 0 ; i < heap_size ; i++)
		aux[i] = array[i];
	delete[] array;
	array = aux;
}

void Min_heap::heapify(int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int m = i;
	if(l < heap_size && array[l].priority <= array[m].priority){
		m = l;
	}
	if(r < heap_size && array[r].priority <= array[m].priority){
		m = r;
	}
	if(m != i){
		heap_node aux = array[i];
		array[i] = array[m];
		array[m] = aux;
		heapify(m);
	}
}


heap_node Min_heap::extract(){
	heap_node r;
	if(heap_size != 0){
		r = array[0];
		array[0] = array[heap_size-1];
		array[heap_size-1] = r;
		heap_size--;
		heapify(0);
	}else{
		r.v = -1;
		r.priority = -1;
	}
	return r;
}

void Min_heap::print(){
	for(int i=0 ; i < heap_size ; i++){
		std::cout << array[i].priority << " " << array[i].v <<  std::endl;


	}
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

node* append(node* head,int v,int p){
	node* curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	return insert(curr,v,p);
}


void printl(node* head){
	node* curr = head->next;
	while(curr != NULL){
		std::cout<<curr->v<<" "<<curr->peso << " | ";
		curr = curr->next;
	}
}


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
		append(e[a],b,peso);
		

	}

	node* get(int i){
		return e[i];

	}

	void print(){
		for(int i=0 ; i < size ; i++){
			std::cout << i << ": ";
			printl(e[i]);
			cout<<endl;
		}
	}
};


int main(){
	int m;//numero de cidades
	cin >> m;
	int tarifas[m];
	for(int i = 0 ; i < m ; i++){
		cin >>tarifas[i];//tarifa por cidade; 
	}
	int n;//quantidade de pontos(tamanho do grafo)
	cin >> n;
	Grafo *gr = new Grafo(n);
	int cidades[n];
	for(int i = 0; i < n ; i++){
		cin >> cidades[i];
	}
	int w;
	cin >> w;
	for(int i = 0 ; i < w ; i++){
		int a,b,p;
		cin >> a;
		cin >> b;
		cin >> p;
		gr->inserirAresta(a,b,p);
		gr->inserirAresta(b,a,p);
	}
	string func;
	while(cin>>func){
		if(func == "UPDA"){
			int j , r;
			cin >> j;
			cin >> r;
			tarifas[j] = r;
		}else if(func == "RIDE"){
			int c , d;
			char o;
			cin >> c;
			cin >> d;
			cin >> o;
			if(o == 'S'){
				//curta
			}else if(o == 'E'){
				//economica
			}else{
				break;
			}
		}

	}

	gr->print();
	
	return 0;
 }