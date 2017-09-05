#ifndef HASHTABLEC_H
#define HASHTABLEC_H

#include <bits/stdc++.h>

#include "Darray.h"

class HashTableC{

private:
	int size;
	double ocupation;
	int *table;
	bool *auxTable;
public:
	HashTableC(int m){
		this->size = m;
		this->ocupation = 0;
		this->table = new int[size];
		this->auxTable = new bool[size];
	}

	~HashTableC(){
		delete[] table;
		delete[] auxTable;
	}

	int hash0(int key){
		return key % this->size;
	}

	int hash1(int key){
		return (2 * (key % (this->size/2))) + 1;
	}

	void insert(int key){
		if((ocupation/size) >= 0.75){
			reHash();
		}
		int hashV = hash0(key);
		int hash1V = hash1(key);
		while(auxTable[hashV]){
			hashV = hashV + hash1V;
			hashV = hashV % this->size;
		}
		table[hashV] = key;
		auxTable[hashV] = true;
		ocupation++;

	}

	int search(int key){
		int hashV = hash0(key);
		int hash1V = hash1(key);
		while(auxTable[hashV]){
			if(table[hashV] == key){
				return hashV;
			}
			hashV = hashV + hash1V;
			hashV = hashV % this->size;
		}
		return -1;
	}

	void reHash(){
		this->size = this->size * 2;
		int *aux = new int[this->size];
		bool *aux2 = new bool[this->size];
		for(int i = 0; i < this->size/2; i++){
			if(auxTable[i]){
				int key = table[i];
				int hashV = hash0(key);
				int hash1V = hash1(key);
				while(aux2[hashV]){
					hashV = hashV + hash1V;
				 	hashV = hashV % this->size;
			 	}
			 	aux[hashV] = key;
			 	aux2[hashV] = true;
		 	}
		}
		delete[] auxTable;
		delete[] table;
		table = aux;
		auxTable = aux2;
	}

};

#endif