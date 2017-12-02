#include <bits/stdc++.h>

using namespace std;


struct cell
{
	int h;
	bool n,l,s,o;

	cell(){
		h = 0;
		n = true;
		l = true;
		s = true;
		o = true;	
	}
};


struct direction
{
	int h;
	int x;
	int y;
	string path;
};

class Mapa{

private:
	cell **lab;
	int size;
public:

Mapa(int s){
	size = s;
	lab = new cell*[s];
	for(int i = 0 ; i < s ; i++){
		lab[i] = new cell[s];
	}
}

void insertHeight(int x, int y, int h){
	lab[x][y].h = h;
}

void insertWall(int x1,int y1, int x2, int y2){

	if(y1-size+1 == y2-size+1){
		lab[abs(y1-size+1)][x1].l = 0;
		lab[abs(y2-size+1)][x2].o = 0;
	}else if(x1 == x2){
		lab[abs(y1-size+1)][x1].n = 0;
		lab[abs(y2-size+1)][x2].s = 0;
	}
}
int get(int x,int y){
	if(y >= 0 && y < size && x >= 0 && x < size){
		return (lab[abs(y-size+1)][x].h);		
	}else{
		return -1;
	}
}

bool getWall(int x, int y, int p){
	if(p == 0){
		if(y+1 >= size){
			return false;
		}
		return (lab[abs(y-size+1)][x].n);		
	}else if(p == 1){
		if(x+1 >= size ){
			return false;
		}
		return (lab[abs(y-size+1)][x].l);
	}else if(p == 2){
		if(y-1 < 0 ){
			return false;
		}
		return (lab[abs(y-size+1)][x].s);
	}else{
		if(x-1 < 0){
			return false;
		}
		return (lab[abs(y-size+1)][x].o);
	}
}

void greedy(int x, int y){
	int max = 0;
	while(true){
		int i,j;
		i = x;
		j = y;
		max = get(x,y);
		string d;
		if(get(x,y+1) > max && getWall(x,y,0)){
			i = x;
			j = y+1;
			d = "N";
			max = get(x,y+1);
			//N
		}
		if(get(x+1,y) > max && getWall(x,y,1)){
			i = x+1;
			j = y;
			d = "L";
			max = get(x+1,y);
			//L
		}
		if(get(x,y-1) > max && getWall(x,y,2)){
			i = x;
			j = y-1;
			d = "S";
			max = get(x,y-1);
			//S
		}
		if(get(x-1,y) > max && getWall(x,y,3)){
			i = x-1;
			j = y;
			d = "O";
			max = get(x-1,y);
			//O
		}

		if(get(x,y) == max){
			break;
		}

		cout << d;
		x = i;
		y = j;
	}
	cout <<"="<<max << endl;
}



void print(){
	for(int i = 0; i <size ; i++){
		for(int j =0 ; j < size ; j++){
			cout << lab[i][j].h;
			if(!lab[i][j].l){
				cout << "l";
			}
			if(!lab[i][j].n){
				cout << "n";
			}
			if(!lab[i][j].s){
				cout << "s";
			}
			if(!lab[i][j].o){
				cout << "o";
			}
			cout << " ";
		}

		cout << endl;
	}
}

direction greedy3(int x, int y, direction max,string path,bool **p){
	p[abs(y-size+1)][x] = 1;
	if(get(x,y) > max.h){
		max.h = get(x,y);
		max.x = x;
		max.y = y;
		max.path = path;
	}
	if(getWall(x,y,0) && !p[abs(y-size+2)][x] ){
		max = greedy3(x,y+1,max,path+"N",p);
	}
	if(getWall(x,y,1) && !p[abs(y-size+1)][x+1] ){
		max = greedy3(x+1,y,max,path+"L",p);
	}
	if(getWall(x,y,2) && !p[abs(y-size)][x] ){
		max = greedy3(x,y-1,max,path+"S",p);
	}
	if(getWall(x,y,3) && !p[abs(y-size+1)][x-1] ){
		max = greedy3(x-1,y,max,path+"O",p);
	}

	return max;

}

direction* greedy2(int x,int y,int r,direction* max,int xa,int ya,string path){
	if(r < 0){
		return max;
	}else{
		if(get(x,y) > max->h){
			max->h = get(x,y);
			max->x = x;
			max->y = y;
			max->path = path;
		}
		if(getWall(x,y,0) &&  y+1 != ya){
			max = greedy2(x,y+1,r-1,max,x,y,path+"N");
		}
		if(getWall(x,y,1) && (x+1!= xa) ){
			max = greedy2(x+1,y,r-1,max,x,y,path+"L");
		}
		if(getWall(x,y,2) && y-1 != ya){  
			max = greedy2(x,y-1,r-1,max,x,y,path+"S");
		}
		if(getWall(x,y,3) && x-1!= xa ){
			max = greedy2(x-1,y,r-1,max,x,y,path+"O");
		}
		return max;
	}
}

void greedyDfs(int x,int y,int r){
	direction *max = new direction();
	max->h = 0;
	int i , j;
	while(true){
		max = greedy2(x,y,r,max,-1,-1,"");
		if(x == max->x && y == max->y){
			break;
		}
		x = max->x;
		y = max->y;
		cout << max->path;
	}
	cout << "=" << max->h<<endl;
	delete max;
}



};


int main(){

	int size;
	scanf("%d",&size);

	Mapa *m = new Mapa(size);
	int h;
	for(int i = size-1; i >= 0 ; i--){
		for(int j = 0 ; j < size ; j++){
			scanf("%d",&h);
			m->insertHeight(i,j,h);
		}
	}

	int w;
	scanf("%d",&w);


	int x1,y1,x2,y2;

	for(int i = 0 ; i < w; i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		m->insertWall(x1,y1,x2,y2);
	}


	int r;
	scanf("%d",&r);


	int x,y,z;

	bool **p = new bool*[size];
	for (int i = 0; i < size; i++){
		p[i] = new bool[size];
	}

	scanf("%d",&z);
	for(int i= 0 ; i < z; i++){
		direction max ;
		max.h = -1;
		scanf("%d %d",&x,&y);
		cout << "caso " << i << ":" << endl;
		m->greedy(x,y);
		m->greedyDfs(x,y,r);
		max = m->greedy3(x,y,max,"",p);
		cout << max.path <<"=" << max.h << endl << endl;
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; j++){
				p[i][j] = 0;
			}
		}
	 }
	return 0;
}