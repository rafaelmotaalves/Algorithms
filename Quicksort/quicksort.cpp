#include <iostream>
#include <cstdlib>
#include <ctime>


void quickSort(int v[] , int size);
void qSort(int v[] , int l , int r);
int partition(int v[] , int l , int r);

int main(){

	int array[50];
	int size = sizeof(array)/sizeof(array[0]);

	for(int i = 0; i < size ; i++){
		array[i] = rand() % 100;
	}
	
	quickSort(array,size);

	std::cout << std::endl << std::endl;

	for(int i = 0; i< size; i++){
		std::cout << array[i] << " ";
	}

	return 0;
}

void quickSort(int v[] ,int  size){
	qSort(v, 0 , size - 1);
} 

void qSort(int v[] , int l , int r){
	if(l<r){
		int p = partition(v,l,r);
		qSort(v,l,p-1);
		qSort(v,p+1,r);
	}
}

int partition(int v[] , int l , int r){
	int p = (l+r)/2;
	int aux = v[l];
	v[l] = v[p];
	v[p] = v[l];
	int i = l;
	int j = r;
	while(i < j){
		while(i<=r && v[i] <= v[l]){
			i++;
		}
		while(v[j] > v[l]){
			j--;
		}
		if(i<j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}
	aux = v[l];
	v[l] = v[j];
	v[j] = aux;
	return j;
} 