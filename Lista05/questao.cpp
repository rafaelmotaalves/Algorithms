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

struct aresta
{
	int v;
	int peso;
};
 
class DynamicArray{
private:
	int index;
	int size;
	aresta *array;
public:
	DynamicArray(){
		index = 0;
		size = 1;
		array = new aresta[size];
	}

	void doubleSize(){
		size = size*2;
		aresta *aux = new aresta[size];
		for(int i=0 ; i < size ; i++){
			aux[i] = array[i];
		}
		delete[] array;
		array = aux;
	}

	void insert(aresta v,int pos){
		if(index < pos){
			std::cout<<"invalid index\n";
		}else{
			if(index == size){
				doubleSize();
			}
			aresta *a = new aresta[index];
			for(int i = 0; i < index ; i++){
				a[i] = array[i];
			}
			for(int i = pos ; i < index ; i++){
				array[i+1] = a[i];
			}
			delete[] a;
			array[pos] = v;
			index++;
		}
	}


	void insertSorted(aresta v){
		if(index == size){
			doubleSize();
		}
		for(int i = 0; i < index ; i++){
			if(array[i].peso > v.peso){
				insert(v,i);
				return;			
			}
		}
		array[index] = v;
		index++;

	}

	void print(){
		for(int i = 0 ; i < index ; i++){
			std::cout << array[i].v << " " << array[i].peso << " | ";
		}
		std::cout << std::endl;
	}


};

class Grafo{
private:
	DynamicArray *e;
	int size;
public:
	Grafo(int size){
		this->size = size;
		e = new DynamicArray[size];
	}

	void inserirVertice(int a,int b,int peso){
		aresta ar;
		ar.v = b;
		ar.peso = peso;
		e[a].insertSorted(ar);

	}

	void print(){
		for(int i=0 ; i < size ; i++){
			std::cout << i << ": " ;
			e[i].print();
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
	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		gr->inserirVertice(x,y,z);
		gr->inserirVertice(y,x,z);
	}

	string func;

	while(cin >> func){
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
			}
		}

	}


	return 0;
}