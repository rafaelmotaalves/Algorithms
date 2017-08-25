#include <iostream>
#include "ArrayD.h"
using namespace std;

int main(){
	ArrayD *ad = new ArrayD();
	for(int i = 0 ; i < 20; i++){
		ad->append(i);
	}

	return 0;
}