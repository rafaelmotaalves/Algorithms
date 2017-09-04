#ifndef HASHTABLEB_H
#define HASHTABLEB_H

#include <bits/stdc++.h>

#include "Darray.h"

class HashTableB{

private:
	int size;
	double ocupation;
	DynamicArray *table;
public:
	HashTableB(int m){
		this->size = m;
		this->table = new DynamicArray[size];
	}

	~HashTableB(){
		delete[] table;
	}

	int hash(int key){
		return key % this->size;
	}

	void insert(int key){
		if((ocupation/size) >= 0.75){
			reHash();
		}
		int i = hash(key);
		table[i].insertSorted(key);
		this->ocupation++;
	}

	int find(int key,int *x){
		int i = hash(key);
		return table[i].binarySearch(key);
	}

	void reHash(){
		this->size = this->size * 2;
		DynamicArray *aux = new DynamicArray[this->size];
		for(int i = 0 ; i < this->size/2 ; i++){
			int index = table[i].getIndex();
			for(int j = 0; j< index ; j++){
				int a = table[i].get(j);
				aux[hash(a)].insertSorted(a);
			}
		}
		delete[] table;
		table = aux;
	}

	void printTable(){
		for(int i = 0 ; i < size ; i++){
			table[i].print(); 
		}
	}


};

#endif