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

	int getValor(int i){
		return this->parray[i];
	}
};

#endif