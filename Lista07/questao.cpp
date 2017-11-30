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
	int xa = 0;
	int ya = 0;
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
		if(x+1 >= size){
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


direction checkSides(int x,int y,int max){
	int i,j;
	string d;
	i = x;
	j = y;
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

	direction r;
	r.h = max;
	r.x = i;
	r.y = j;
	r.path = d;

	return r;
}

void greedy(int x, int y){
	int max = 0;
	while(true){
		int i,j;
		i = x;
		j = y;
		char d;
		max = get(x,y);

		direction r = checkSides(x,y,max);

		max = r.h;

		if(get(x,y) == max){
			break;
		}

		cout << r.path;
		x = r.x;
		y = r.y;
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

direction greedy2(int x,int y,int r,direction max,int xa,int ya,string path){
	if(r < 0){
		return max;
	}else{
		if(get(x,y) > max.h){
			max.h = get(x,y);
			max.x = x;
			max.y = y;
			max.xa = xa;
			max.ya = ya;
			max.path = path;
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

direction greedyDfs(int x,int y,int r){
	direction max;
	max.h = 0;
	max.xa = x;
	max.ya = x;
	int i , j;
	while(true){
		i = max.xa;
		j = max.ya;
		max = greedy2(x,y,r,max,i,j,"");
		if(max.h == get(x,y)){
			break;
		}
		cout << max.path;
		x = max.x;
		y = max.y;
	cout << "=" << max.h<<endl;
	}
	return max;
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

	direction max ;
	max.h = -1;
	int x,y;
	m->print();
	while(true){
		scanf("%d %d",&x,&y);
		m->greedyDfs(x,y,4);
	}
	return 0;
}