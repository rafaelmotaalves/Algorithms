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
	return (lab[abs(y-size+1)][x].h);
}

void greedy(int x, int y){
	int max = 0;
	while(true){
		int i,j;
		i = x;
		j = y;
		char d;
		max = lab[x][y].h;
		
		if(lab[x][y].h == max){
			break;
		}
		cout << d;
		x = i;
		y = j;
	}
	cout <<"="<<max;
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
	return 0;
}