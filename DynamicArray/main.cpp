#include <iostream>
#include "Darray.h"

using namespace std;

int main(){
	DynamicArray *ad = new DynamicArray();

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