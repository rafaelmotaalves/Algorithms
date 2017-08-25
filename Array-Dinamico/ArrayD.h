#ifndef ARRAYD_H
#define ARRAYD_H value
#include <iostream>

class ArrayD{
private:
	int posicao;
	int tamanho;
	int *parray;
public:
	ArrayD(){
		this->posicao = 0;
		this->tamanho = 1;
		parray = new int[1];
	}

	void doubleSize(){
		int tamanhoNovo = 2* tamanho;
		int aux[tamanhoNovo];
		for(int i = 0 ; i < tamanho;i++){
			aux[i] = parray[i]; 
		}
		tamanho = tamanhoNovo;
		parray = aux;
	}

	void append(int v){
		if(this->tamanho < this->posicao + 1){
			doubleSize();
		}
		this->parray[this->posicao] = v;
		this->posicao++;
	}
	
	void bubbleSort(){
		for(int i = 0 ; i <= posicao ; i++){
			for(int j=0 ; j<= posicao; j++){
				if(parray[i]<parray[j]){
					int aux = parray[i];
					parray[i] = parray[j];
					parray[j] = aux;
				}
			}
		}

	}

	int binarySearch(int v){
		int l = 0;
		int r = posicao;
		do{
			int m = (l+r)/2;
			if(parray[m] == v){
				return m;
			}else if(parray[m] < v){
				l = m + 1;
			}else{
				r = m - 1;
			}
		}while(l<=r);
		return -1;
	}
};

#endif