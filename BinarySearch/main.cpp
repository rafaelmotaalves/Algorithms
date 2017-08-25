#include <iostream>
#include <cstdlib>

using namespace std;

void bubbleSort(int array[],int size);
int binarySearch(int v,int array[],int size);

int main(){
	int array[50];

	for(int i = 0 ; i < 50 ; i++){
		array[i] = rand() % 100;
	}

	int size = sizeof(array)/sizeof(array[0]);

	bubbleSort(array,size);

	for(int i = 0; i < 50; i++){
		cout << array[i] << " ";
	}
	cout<<endl;

	cout << binarySearch(98,array,size);
	return 0;
}

void bubbleSort(int array[] ,int size){
	for(int i = 0;i < size; i++){
		for(int j=0;j < size; j++ ){
			if(array[i] < array[j]){
				int aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
}

int binarySearch(int v,int array[],int size){
	int l = 0;
	int r = 49;
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