#include <bits/stdc++.h>
#define endl '\n';

using namespace std;

static int contA = 0;
static int contB = 0;
static int contC = 0;

class DynamicArray{
private:
	int index;
	int size;
	int *array;
public:
	DynamicArray(){
		index = 0;
		size = 3;
		array = new int[size];
	}
 	~DynamicArray(){
 		delete[] array;
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
		for(int i = 0; i < index ; i++){
			if(array[i] > v){
				insert(v,i);
				return;			
			}
		}
		array[index] = v;
		index++;

	}



	int binarySearch(int v){
		int l = 0;
		int r = index-1;
		do{
			int a = (l + r)/2;
			contB++;
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

	int search(int v ){
		for(int i = 0 ; i < this->index ; i++){
			contA++;
			if(array[i] == v){
				return i;
			}
		}
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

class HashTableA{

private:
	int size;
	double ocupation;
	DynamicArray *table;
public:
	HashTableA(int m){
		this->size = m;
		this->ocupation = 0;
		this->table = new DynamicArray[size];
	}

	~HashTableA(){
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
		table[i].append(key);
		this->ocupation++;
	}

	int find(int key){
		int i = hash(key);
		if(table[i].getIndex() == 0){
			return -1;
		}
		return table[i].search(key);
	}

	void reHash(){
		this->size = this->size * 2;
		DynamicArray *aux = new DynamicArray[this->size];
		for(int i = 0 ; i < this->size/2 ; i++){
			int index = table[i].getIndex();
			for(int j = 0; j< index ; j++){
				int a = table[i].get(j);
				aux[hash(a)].append(a);
			}
		}
		delete[] table;
		table = aux;
	}

};

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

	int find(int key){
		int i = hash(key);
		if(table[i].getIndex() == 0){
			return -1;
		}else{
			return table[i].binarySearch(key); 
		}
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

};

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
		for(int i = 0; i < this->size ; i++){
			auxTable[i] = false;
		}
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

	int find(int key){
		int hashV = hash0(key);
		int hash1V = hash1(key);
		while(auxTable[hashV]){
			contC++;
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
		for(int i = 0; i < this->size ; i++){
			aux2[i] = false;
		}
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

int main(){
	int k , m, n ,q,contloop = 0 ;
	int penetras; 

	while(cin >> k >> m >> n >> q){

		contA = 0;
		contB = 0;
		contC = 0;
		penetras = 0;
		
		HashTableA *hta = new HashTableA(m);
		HashTableB *htb = new HashTableB(m);
		HashTableC *htc = new HashTableC(m);
		
		int entry;

		for(int i = 0 ; i < n ; i++){
			cin >> entry;

			hta->insert(entry);
			htb->insert(entry);
			htc->insert(entry);
		}


		for(int i = 0; i < q ; i++){
			cin >> entry;


			int a = hta->find(entry);
			int b = htb->find(entry);
			int c = htc->find(entry);

			if(a == -1){
				penetras++;
			}
		}

		cout << "caso " << contloop << ": "<< penetras << " " << contA << " " << contB << " " << contC << endl;

		contloop++;

		delete hta;
		delete htb;
		delete htc;

	}

	return 0;
}