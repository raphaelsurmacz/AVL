#ifndef AVL_FUNCTION
#define AVL_FUNCTION

struct node *createNode(int);

int returnHeighest(int , int );

int nodeHeight(struct node *);

int balanceFactor(struct node *);

struct node *leftRotation(struct node *);

struct node *rightRotation(struct node *);

struct node *leftRightRotation(struct node *);

struct node *rightLeftRotation(struct node *);

struct node *treeBalancer(struct node *);

struct node *insert(struct node *, int );

struct node *nodeRemove(struct node *, int );

void inOrder(struct node *, int );

void printAVL(struct node *, int );


#endif