#include <stdio.h>
#include <stdlib.h>
#include "avlfunction.h"

struct node{
	int valor;
	struct node *left, *right;
	int height;
};

//----------------------------------------------------------------
void start(){
    printf ("\tBEM VINDO!\n");
    printf ("\tEsse programa é a implementacao de uma arvore AVL.\n");
    printf ("\tAbaixo voce tera o menu inicial:\n");
    printf (" ===========| OPCOES |===========\n");
    printf (" |                              |\n");
    printf (" |  i - Inserir			|\n");
    printf (" |  r - Remover			|\n");
    printf (" |  t - Travessia crescente	|\n");
    printf (" |  p - Imprimir Arvore		|\n");
    printf (" |  q - Sair			|\n");
    printf (" |                              |\n");
    printf (" ================================\n");

    return;
}

int main(){
	char op;
	int valor;

	struct node *root = NULL;

	start();

	do{
		scanf(" %c", &op);

		switch(op){
		
		case 'i':
			scanf("%d", &valor);
			root = insert(root, valor);
			break;

		case 'r':
			scanf("%d", &valor);
			root = nodeRemove(root, valor);
			break;

		case 't':
			inOrder(root, 0);
			break;

		case 'p':
			printAVL(root, 1);
			printf("\n");
			break;

		case 'q':
			inOrder(root, 0);
		}
		
	}while(op != 'q');

	free(root);
	return 0;
}