#include <iostream>
#include <cstdlib>
#include "Sort.h"

using namespace std;

int binarySearch(int v,int array[],int size);

int main(){
	int array[] = {359,
					966,
					105,
					115,
					81,
					255,
					74,
					236,
					809,
					205,
					186,
					939,
					498,
					763,
					483,
					326,
					124,
					706,
					84,
					1016};

	Sort s;

	int size = sizeof(array)/sizeof(array[0]);


	s.mergeSort(array,size);

	for(int i = 0; i <  size; i++){
		cout << array[i] << " ";
	}
	cout<<endl;

	return 0;
}


int binarySearch(int v,int array[],int size){
	int l = 0;
	int r = size-1;
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