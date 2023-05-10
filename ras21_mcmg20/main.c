#include <stdio.h>
#include <stdlib.h>
#include "avlfunction.h"

struct node{
	int valor;
	struct node *left, *right;
	int height;
};

int main(){
	char op;
	int valor;

	struct node *root = NULL;

	//start();

	while(scanf("%c\n", &op) == 1 && scanf("%d\n", &valor) == 1){

		if (op == 105)
			root = insert(root, valor);
		
		if (op == 114)
			root = nodeRemove(root, valor);
	}

	printAVL(root, 1);

	printf("\n");

	inOrder(root, 0);

	free(root);

	return 0;
}