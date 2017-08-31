#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

#define endl '\n'

int main(){
	List *l = new List();

	l->append(10);
	l->append(20);
	l->append(30);
	l->append(40);
	l->append(50);
	l->append(60);


	l->print();


	l->remove(l->find(10));

	cout << endl;

	l->print();
	
	return 0;
}s