#include <iostream>
#include <cstdlib>
#include "Sort.h"
#include <math.h>

using namespace std;

int binarySearch(int v,int array[],int i,int j,int size);

int main(){
	int array[] = {1,
		2,
		3,
		6,
		5,
		10,
		12,
		25};

	Sort s;

	int size = sizeof(array)/sizeof(array[0]);


	s.mergeSort(array,size);

	for(int i = 0; i <  size; i++){
		cout << array[i] << " ";
	}
	cout<<endl;

	cout << binarySearch(2,array,0,size,size);

	return 0;
}

int binarySearch(int v, int array[],int i ,int j,int size){
	
	int p = (j+i)/2;

	if(j - i == 1 && array[p] != v){
		return -1;
	}else if(v > array[p]){
		return binarySearch(v,array,p+1,j,size);
	}else if(v < array[p]){
		return binarySearch(v,array,i,p,size);
	}else{
		return p;
	}

}

//0 1 2 3 4