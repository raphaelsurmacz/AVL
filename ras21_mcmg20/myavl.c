#include <stdio.h>
#include <stdlib.h>

struct node{
	int valor;
	struct node *left, *right;
	int height;
};

//----------------------------------------------------------------
struct node *createNode(int x){
	struct node *new_node = malloc(sizeof(struct node));

	if (new_node){
		new_node->valor = x;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->height = 0;
	}else
		printf("\n ERRO ao alocar um no...\n");

	return new_node;
}

//----------------------------------------------------------------
int returnHeighest(int a, int b){
	return (a > b)? a: b;
}

//----------------------------------------------------------------
int nodeHeight(struct node *no){
	if (no == NULL)
		return -1;

	else
		return no->height;
}

//----------------------------------------------------------------
int balanceFactor(struct node *no){
	if(no)
		return (nodeHeight(no->left) - nodeHeight(no->right));

	return 0;
}

//----------------------------------------------------------------
struct node *leftRotation(struct node *nroot){
	struct node *x, *leftson;

	x = nroot->right;
	leftson = x->left;

	x->left = nroot;
	nroot->right = leftson;

	nroot->height = returnHeighest(nodeHeight(nroot->left), nodeHeight(nroot->right)) + 1;
	x->height = returnHeighest(nodeHeight(x->left), nodeHeight(x->right)) + 1;

	return x;
}

//----------------------------------------------------------------
struct node *rightRotation(struct node *nroot){
	struct node *x, *rightson;

	x = nroot->left;
	rightson = x->right;

	x->right = nroot;
	nroot->left = rightson;

	nroot->height = returnHeighest(nodeHeight(nroot->left), nodeHeight(nroot->right)) + 1;
	x->height = returnHeighest(nodeHeight(x->left), nodeHeight(x->right)) + 1;

	return x;
}

//----------------------------------------------------------------
struct node *leftRightRotation(struct node *nroot){
	nroot->left = leftRotation(nroot->left);
	return rightRotation(nroot);
}

//----------------------------------------------------------------
struct node *rightLeftRotation(struct node *nroot){
	nroot->right = rightRotation(nroot->right);
	return leftRotation(nroot);
}

//----------------------------------------------------------------
struct node *treeBalancer(struct node *root){
	int factor = balanceFactor(root);

	if (factor < -1 && balanceFactor(root->right) <= 0)
		root = leftRotation(root);
	
	else if (factor > 1 && balanceFactor(root->left) >= 0)
		root = rightRotation(root);

	else if (factor > 1 && balanceFactor(root->left) < 0)
		root = leftRightRotation(root);

	else if (factor < -1 && balanceFactor(root->right) > 0)
		root = rightLeftRotation(root);

	return root;
}

//----------------------------------------------------------------
struct node *insert(struct node *root, int x){
	if (root == NULL)
		return createNode(x);
	else{
		if (x < root->valor)
			root->left = insert(root->left, x);

		else if (x > root->valor)
			root->right = insert(root->right, x);

		else
			printf("\n Insercao não realizada... Elemento %d ja existe!\n", x);
	}

	root->height = returnHeighest(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	root = treeBalancer(root);

	return root;
}

//----------------------------------------------------------------
struct node *nodeRemove(struct node *root, int key){
	if (root == NULL){
		printf("\nValor nao encontrado!\n");

		return NULL;
	}else{ 
		if (root->valor == key){ 						//caso I - nodeRemove da folha
			if (root->left == NULL && root->right ==NULL){
				free(root);
				printf("\n%d foi removido!\n", key);

				return NULL;
			}
			else{										//caso II - no com dois fihos
				if (root->left != NULL && root->right != NULL){
					struct node *temp = root->left;

					while(temp->right != NULL)
						temp = temp->right;

					root->valor = temp->valor;
					temp->valor = key;

					printf("\nTroca feita: %d!\n", key);
					root->left = nodeRemove(root->left, key);

					return root;
				}
				else{									//caso III - no com um filho
					struct node *temp;

					if (root->left == NULL)
						temp = root->left;
					else
						temp = root->right;

					free(root);
					printf("\nElemento %d removido!\n", key);

					return temp;
				}
			}
		}else{
			if (key < root->valor)
				root->left = nodeRemove(root->left, key);
			else
				root->right = nodeRemove(root->right, key);
		}
		//recaucula a altura
		root->height = returnHeighest(nodeHeight(root->left), nodeHeight(root->right)) + 1;
		root = treeBalancer(root);

		return root;
	}

}

//----------------------------------------------------------------
void inOrder(struct node *tree, int height){
	if (tree != NULL){
		inOrder(tree->left, height +1);
		printf("%d, %d \n", tree->valor, height);
		inOrder(tree->right, height + 1);
	}
}

//----------------------------------------------------------------
void printAVL(struct node *root, int level){
	int i;
	if (root){
		printAVL(root->right, level + 1);
		printf("\n\n");

		for (i = 0; i < level; ++i)
			printf("\t");

		printf("%d", root->valor);
		printAVL(root->left, level + 1);
	}
	return;
}