#include <iostream>
#include "list.h"

using namespace std;

int main(){
	List* lista = new List();
	lista->insert(lista->getHead(),10);
	lista->print();
	return 0;
}