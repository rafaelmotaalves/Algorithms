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
	if(x1 == x2){
		lab[x1][y1].l = 0;
		lab[x2][y2].o = 0;
	}else if(y1 == y2){
		lab[x1][y1].n = 0;
		lab[x2][y2].s = 0;
	}
}

void greedy(int x, int y){
	int max = 0;
	cout << lab[x][y].h;
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

int get(int x,int y){
	return (lab[abs(y-size+1)][x].h);
}


void print(){
	for(int i = size-1; i >= 0 ; i--){
		cout << i << "=";
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

	cout << m->get(5,9);
	cout << m->get(7,5);
	return 0;
}