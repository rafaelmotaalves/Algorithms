#ifndef SORT_H
#define SORT_H value

class Sort{
public:

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
	
};
#endif