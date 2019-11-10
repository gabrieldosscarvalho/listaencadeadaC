#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Nodo {
	int codigo;
	char descricao[50];
	char data[8];
	struct Nodo *prox;
};

struct Nodo *gerarNodo() {
	struct Nodo *_temp = (struct Nodo*) malloc( sizeof (struct Nodo) );
	_temp->prox = NULL;

	return _temp;
}

void incluir( struct Nodo *novoNodo, struct Nodo *lista ) {
	struct Nodo *_aux = lista;

	while( _aux->prox != NULL ){
		_aux = _aux->prox;
	}
	
	_aux->prox = novoNodo;
}

void remover( int codigo, struct Nodo *lista ) {
	struct Nodo *_aux = lista;

	while( _aux->prox != NULL ){
		if( _aux->prox->codigo == codigo ) {
			_aux->prox = _aux->prox->prox;
			return;
		}

		_aux = _aux->prox;
	}
}

struct Nodo *buscar( int codigo, struct Nodo *lista ) {
	struct Nodo *_aux = lista;

	while( _aux->prox != NULL ){
		if( _aux->prox->codigo == codigo ) {
			return _aux->prox;
		}

		_aux = _aux->prox;
	}
	
	return NULL;
}

void listar( struct Nodo *lista ) {
	printf("\n\n--- LISTAR ---");

	if( lista->prox == NULL ) {
		printf("\nLista vazia");
		return;
	}
	
	struct Nodo *_aux = lista->prox;

	do{
		printf("\nItem: %d", _aux->codigo);
		printf("\nDescrição: %s", _aux->descricao);
		printf("\nData: %.8s", _aux->data);
		
		_aux = _aux->prox;
	} while( _aux != NULL );
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");

	struct Nodo *_raiz = gerarNodo();

	struct Nodo *_item = gerarNodo();
	struct Nodo *_item2 = gerarNodo();
	
	_item->codigo = 1;
	strcpy( _item->descricao, "Teste 1" );
	strcpy( _item->data, "19920502" );
	
	_item2->codigo = 2;
	strcpy( _item2->descricao, "Teste 2" );
	strcpy( _item2->data, "19920510" );
	
	incluir(_item, _raiz);
	incluir(_item2, _raiz);

	// Listar	
	listar(_raiz);

	// Remover
	remover(2, _raiz);

	// Listar
	listar(_raiz);	

	// Buscar Item 1
	struct Nodo *_item1Busca = buscar(1, _raiz);
	printf("\n\n--- Buscar Item 1 ---");
	if( _item1Busca != NULL ) {
		printf("\nCódigo %d", _item1Busca->codigo);	
	} else {
		printf("\nItem não encontrado");
	}

	// Buscar Item 2
	struct Nodo *_item2Busca = buscar(2, _raiz);
	printf("\n\n--- Buscar Item 2 ---");
	if( _item2Busca != NULL ) {
		printf("\nCódigo %d", _item2Busca->codigo);	
	} else {
		printf("\nItem não encontrado");
	}

	return 0;
}
