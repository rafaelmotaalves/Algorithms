#ifndef DisjointSet
#define DisjointSet 
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

#endif