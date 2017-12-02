class DisjointSet{
private:
	int* d;
public:


	DisjointSet(int n){
		d = new int[n];
		for(int i = 0; i < n; i++) {
        	d[i] = i;
    	}
	}

	void union_set(int a,int b){
		d[a] = b;
	}


	int find(int a) {
    	if(a != d[a]) {
        	d[a] = find(d[a]);
    	}
        return d[a];
	}

};



struct aresta
{
	int u;
	int v;
	int peso;

};

int partition(aresta* arr, int p, int r) {
    aresta x = arr[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++) {
        if(arr[j].peso <= x.peso) {
            i += 1;
            aresta aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    aresta aux = arr[i+1];
    arr[i+1] = arr[r];
   	arr[r] = aux;
    return i+1;
}

void qsort(aresta* A, int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        qsort(A, p, q-1);
        qsort(A, q+1, r);
    }
}


void quickSort(aresta* arr,int size){
	qsort(arr,0,size-1);
}


int kruskal(aresta* arr,int n, int m) {
	quickSort(arr,m);
    DisjointSet *ds = new DisjointSet(n);
    int cost = 0;
    for(int i = 0; i < m; i++) {
       int peso = arr[i].peso;
       int x = ds->find(arr[i].u);
       int y = ds->find(arr[i].v);
       if(x != y) {
            ds->union_set(x, y);
            cost = cost + peso;
        }
    }
    return cost;
}

int main(){

    return 0;
}