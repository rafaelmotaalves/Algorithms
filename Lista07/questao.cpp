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
	if(abs(y-size+1) >= 0 && abs(y-size+1) < size && x >= 0 && x < size){
		return (lab[abs(y-size+1)][x].h);		
	}else{
		return -1;
	}
}

bool getWall(int x, int y, int p){
	if(abs(y-size+1) >= 0 && abs(y-size+1) < size && x >= 0 && x < size){
		if(p == 0){
			return (lab[abs(y-size+1)][x].n);		
		}else if(p == 1){
			return (lab[abs(y-size+1)][x].l);
		}else if(p == 2){
			return (lab[abs(y-size+1)][x].s);
		}else{
			return (lab[abs(y-size+1)][x].o);
		}
	}else{
		return 0;
	}
}

void greedy(int x, int y){
	int max = 0;
	while(true){
		int i,j;
		i = x;
		j = y;
		char d;
		max = get(x,y);
		if(get(x,y+1) > max && getWall(x,y,0)){
			i = x;
			j = y+1;
			d = 'N';
			max = get(x,y+1);
			//N
		}
		if(get(x+1,y) > max && getWall(x,y,1)){
			i = x+1;
			j = y;
			d = 'L';
			max = get(x+1,y);
			//L
		}
		if(get(x,y-1) > max && getWall(x,y,2)){
			i = x;
			j = y-1;
			d = 'S';
			max = get(x,y-1);
			//S
		}
		if(get(x-1,y) > max && getWall(x,y,3)){
			i = x-1;
			j = y;
			d = 'O';
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

	m->print();
	int x,y;

	while(true){
		scanf("%d %d",&x,&y);
		m->greedy(x,y);
	}
	return 0;
}