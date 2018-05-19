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

int partition(int v[], int p, int r) {
    int x = v[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(v[j] <= x) {
            i += 1;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    int aux = v[i+1];
    v[i+1] = v[r];
   	v[r] = aux;
    return i+1;
}
