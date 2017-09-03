#include <bits/stdc++.h>
#define endl '\n'

#include "Darray.h"

using namespace std;

int main(){
	DynamicArray *ad = new DynamicArray();

	DynamicArray **repositorio = new DynamicArray*[10];

	for(int i=0 ; i < 10 ; i++){
		repositorio[i] = new DynamicArray();
	}

	repositorio[0]->append(10);
	repositorio[0]->append(20);


	repositorio[1]->append(30);
	repositorio[1]->append(40);


	for(int i = 0; i < repositorio[0]->getIndex();i++){
		cout << repositorio[0]->get(i) << " ";
	}
	cout<<endl;


	for(int i = 0; i < repositorio[1]->getIndex();i++){
		cout << repositorio[1]->get(i) << " ";
	}
	cout<<endl;


	delete[] repositorio;

	ad->insertSorted(50);
	ad->insertSorted(10);
	ad->insertSorted(20);
	ad->insertSorted(80);
	ad->insertSorted(10);
	
	for(int i = 0; i < ad->getIndex() ; i++){
		cout << ad->get(i) << " ";
	}
	cout << endl;
 	

	cout << endl;	

	return 0;
}