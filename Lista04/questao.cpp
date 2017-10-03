#include<bits/stdc++.h>


using namespace std;

struct task
{
	int priorityO;
	int priority;
	int id;

};


struct CPU
{
	task process;
	char status;
	int use;

	CPU(){
		status = 'O';
	}

	void assignTask(task t){
		process = t;
		status = 'A';
		use += (20 - t.priority);
	}

};


class Max_heap
{
private:
	int heap_size;
	int array_size;
	task* array;
public:
	Max_heap();
	~Max_heap();
	void insert(task t);
	void bubbleup();
	void doubleSize();
	void heapify(int i);
	task extract();
	void print();
	int getHeap_size();
};

int Max_heap::getHeap_size(){
	return heap_size;
}

Max_heap::Max_heap(){
	heap_size = 0;
	array_size = 2;
	array = new task[2];
}

Max_heap::~Max_heap(){
	delete[] array;
}

void Max_heap::insert(task t){
	if(heap_size == array_size){
		doubleSize();
	}
	array[heap_size] = t;
	heap_size++;
	bubbleup();

}

void Max_heap::bubbleup(){
	int i = heap_size - 1;
	while(i>0 && array[i].priority < array[(int)floor((i-1)/2)].priority ){
			task aux = array[i];
			array[i] = array[(int)floor((i-1)/2)];
			array[(int)floor((i-1)/2)] = aux;
			i = floor((i-1)/2);
	}
	if(array[i].priority == array[(int)floor((i-1)/2)].priority && array[i].id < array[(int)floor((i-1)/2)].id ){
			task aux = array[i];
			array[i] = array[(int)floor((i-1)/2)];
			array[(int)floor((i-1)/2)] = aux;
			i = floor((i-1)/2);
	}

}

void Max_heap::doubleSize(){
	array_size*=2;
	task *aux = new task[array_size];
	for(int i = 0 ; i < heap_size ; i++)
		aux[i] = array[i];
	delete[] array;
	array = aux;
}

void Max_heap::heapify(int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int m = i;
	if(l < heap_size && array[l].priority <= array[m].priority){
		m = l;
	}
	if(r < heap_size && array[r].priority < array[m].priority){
		m = r;
	}else if(r < heap_size && array[r].priority == array[m].priority){
		if(array[r].id < array[m].id ){
			m = r;
		}
	}
	if(m != i){
		task aux = array[i];
		array[i] = array[m];
		array[m] = aux;
		heapify(m);
	}
}


task Max_heap::extract(){
	task r;
	if(heap_size != 0){
		r = array[0];
		array[0] = array[heap_size-1];
		array[heap_size-1] = r;
		heap_size--;
		heapify(0);
	}else{
		r.id = -1;
		r.priority = -1;
	}
	return r;

}

void Max_heap::print(){
	for(int i = 0 ; i < heap_size; i++)
		std::cout << array[i].id << " " << array[i].priority << std::endl;
	std::cout << "\n";
}


int main(){
	Max_heap *heap = new Max_heap();
	int n;

	cin >> n;



	int contproc[10] ;//qtd de processos
	int conttemp[10] ;//tempo por processo
	int controd[10] ;//quantidade de rodadas por process

	for(int i =0 ; i < 10 ; i++ ){
		contproc[i] = 0;
		conttemp[i] = 0;
		controd[i] = 0;
	}

	CPU *cpu = new CPU[n];


	string command;

	while(true){
		
		cin >> command;

		if(command == "END"){
			break;
		}else if(command == "NEW"){
			task t;
			int p, id;
			cin >> id;
			cin >> p;
			t.priority = p;
			t.priorityO = p;
			t.id = id;
			contproc[p] = contproc[p] + 1;
			heap->insert(t);
		}else if (command ==  "STA"){
			int id;
			char st;
			cin >>id;
			cin >>st;
			if(st == 'A'){
				if(cpu[id].process.priority != 9){
					cpu[id].process.priority = cpu[id].process.priority + 1;
				}
				controd[cpu[id].process.priorityO]++;
				heap->insert(cpu[id].process);

			}
			cpu[id].status = 'O';

		}

	
	for(int i = 0 ; i < 9; i++){
		if(cpu[i].status == 'O' && heap->getHeap_size() > 0){
			task a = heap->extract();
			conttemp[a.priorityO] += (20 - a.priority);
			cpu[i].assignTask(a);
		}
	}
	
	}

	cout << "STATS BY PRIORITY" << endl <<endl;

	for(int i = 0; i < 10; i++){
		cout << i << ": " << contproc[i] << " "  << conttemp[n] << " " << controd[n] << endl; 
	}

	cout << endl;


	cout << "STATS BY CPU" << endl << endl;
	for(int i = 0; i < n ; i++){
		cout << i << ": " << cpu[i].use << endl;
	}


	return 0;
}