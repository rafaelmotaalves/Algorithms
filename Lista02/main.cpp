#include <bits/stdc++.h>
#include "hashTableB.h"
#include "hashTableA.h"

#define endl '\n';

using namespace std;

int main(){
	HashTableB *htb = new HashTableB(2);

	htb->insert(9);
	htb->insert(0);
	htb->insert(4);


	int *contB = new int() ;


	htb->find(5 , contB);
	htb->find(0 , contB);

	cout << *contB;







	return 0;
}