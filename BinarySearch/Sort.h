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
	
};
#endif