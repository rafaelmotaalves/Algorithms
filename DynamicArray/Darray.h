#include <iostream>

#ifndef DARRAY_H
#define DARRAY_H 
class DynamicArray{
private:
	int index;
	int size;
	int *array;
public:
	DynamicArray(){
		index = 0;
		size = 1;
		array = new int[size];
	}

	void doubleSize(){
		size = size*2;
		int *aux = new int[size];
		for(int i=0 ; i < size ; i++){
			aux[i] = array[i];
		}
		delete[] array;
		array = aux;
	}

	void append(int value){
		if(index  == size ){
			doubleSize();
		}
		array[index] = value;
		index++;

	}

	void insert(int v,int pos){
		if(index < pos){
			std::cout<<"invalid index\n";
		}else{
			if(index == size){
				doubleSize();
			}
			int *a = new int[index];
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


	void insertSorted(int v){
		if(index == size){
			doubleSize();
		}
		if(index == 0){
			array[0] = v;
			index++;
			return;
		}
		int aux = index;
		for(int i = 0; i < aux ; i++){
			if(array[i] > v){
				insert(v,i);
				return;			
			}
		}
		array[index] = v;
		index++;

	}

	void remove(int v){
		int pos = binarySearch(v);
		if(pos == -1){
			std::cout << "Value doesnt exist in the array\n";
			return;
		}else{
			for (int i = pos + 1 ; i < index ; i++ ){
				array[i-1] = array[i];
			}
			index--;
			array[index] = 0;

		}
	}

	int binarySearch(int v){
		int l = 0;
		int r = index-1;

		do{
			int a = (l + r)/2;
			if(array[a] == v){
				return a;
			}else if(array[a] > v){
				r = a-1;
			}else{
				l = a+1;
			}
		}while(l <= r);

		return -1;
	}


	int getSize(){
		return size;
	}

	int getIndex(){
		return index;
	}

	int get(int i){
		return array[i];
	}

};

#endif