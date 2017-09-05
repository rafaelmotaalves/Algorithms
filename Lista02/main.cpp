#include <bits/stdc++.h>
#include "hashTableB.h"
#include "hashTableA.h"
#include "hashTableC.h"

#define endl '\n';

using namespace std;

int main(){
	HashTableC *htc = new HashTableC(4);

	htc->insert(10);
	htc->insert(20);
	htc->insert(43);
	htc->insert(70);


	htc->printTable();
	return 0;
}