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
	}

	int hash0(int key){
		return key % this->size;
	}

	int hash1(int key){
		return (2 * (key % (this->size/2))) + 1;
	}

	int doubleHash(int key){
		int hashV = hash0(key);
		int hash1V = hash1(key);
		while(auxTable[hashV]){
			hashV = hashV + hash1V;
			hashV = hashV % this->size;
	
		}
		return hashV;
	}

	void insert(int key){
		if((ocupation/size) >= 0.75){
			reHash();
		}
		int i = doubleHash(key);
		table[i] = key;
		auxTable[i] = true;
		ocupation++;

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
	void printTable(){
		for(int i = 0 ; i < size ; i++){
			std::cout << "INDEX: " << i << std::endl;
			if(auxTable[i]){
				std::cout << table[i] << std::endl;
			}
		}
	}


};

#endif