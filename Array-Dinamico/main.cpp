#include <iostream>
#include "ArrayD.h"
using namespace std;

int main(){
	ArrayD *ad = new ArrayD();
	for(int i = 20 ; i > 0 ; i--){
		ad->append(i);
	}

	ad->bubbleSort();
	
	return 0;
}