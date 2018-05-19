#include <iostream>
#include <cstdlib>


void mergeSort(int v[], int size);
void mSort(int v[],int l,int r,int a[]);
void merge(int v[],int l,int m,int r,int a[]);

int main(){
	int array[50];
	int size = sizeof(array)/sizeof(array[0]);

	for(int i = 0; i < size ; i++){
		array[i] = rand() % 100;
	}


	for(int i = 0; i< size; i++){
		std::cout << array[i] << " ";
	}

	std::cout << std::endl << std::endl;

	mergeSort(array,size);

	for(int i = 0; i< size; i++){
		std::cout << array[i] << " ";
	}

	return 0;
}

void mergeSort(int v[], int size){
	int a[size]; //memoria auxiliar
	mSort(v,0,size-1,a);
}

void mSort(int v[], int l, int r, int a[]){
	if (l != r){
		int m = (l+r)/2;
		mSort(v,l,m,a);
		mSort(v,m+1,r,a);
		merge(v,l,m,r,a);
	}
}

void merge(int v[],int l,int m,int r,int a[]){
	int i,j;
	for(int x = l; x <= r; x++ ){
		a[x] = v[x];
	}
	i = l;
	j = m+1;
	for(int x = l; x <= r; x++){
		if(j>r){
			v[x] = a[i];
			i++;
		}else if(i>m){
			v[x] = a[j];
			j++;
		}else{
			if(a[i] <= a[j]){
				v[x] = a[i];
				i++;
			}else{
				v[x] = a[j];
				j++;
			}
		}
	}  
}
