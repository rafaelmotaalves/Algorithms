#include<bits/stdc++.h>


struct task
{
	int priority;
	int id;

};


struct CPU
{
	task process;
	char status;
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
	void insert(int id,int priority);
	void bubbleup();
	void doubleSize();
	void heapify(int i);
	task extract();
	void print();
};

Max_heap::Max_heap(){
	heap_size = 0;
	array_size = 2;
	array = new task[2];
}

Max_heap::~Max_heap(){
	delete[] array;
}

void Max_heap::insert(int id,int priority){
	if(heap_size == array_size){
		doubleSize();
	}
	task t;
	t.id = id;
	t.priority = priority;
	array[heap_size] = t;
	heap_size++;
	bubbleup();

}

void Max_heap::bubbleup(){
	int i = heap_size - 1;
	while(i>0 && array[i].priority > array[(int)floor((i-1)/2)].priority ){
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
	if(l < heap_size && array[l].priority >= array[m].priority){
		m = l;
	}
	if(r < heap_size && array[r].priority > array[m].priority){
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
	Max_heap *test = new Max_heap();

	test->insert(0,5);
	test->insert(1,6);
	test->insert(2,9);
	test->insert(3,0);
	test->insert(4,9);
	test->insert(5,5);
	test->insert(6,9);


	test->print();







	return 0;
}