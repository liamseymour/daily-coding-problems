/* (MEDIUM)
 * This question was asked by BufferBox.
 * Given a binary tree where all nodes are 
 * either 0 or 1, prune the tree so that 
 * subtrees containing all 0s are removed.
 * For example, given the following tree: 
    0
   / \
  1   0
     / \
    1   0
   / \
  0   0

 * should be pruned to:
    0
   / \
  1   0
     /
    1
										*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

struct bintree {
	int val;
	struct bintree *left;
	struct bintree *right;
};

// Helper function to allocates a new binary tree
struct bintree *newBintree(int val) 
{ 
    struct bintree* t = malloc(sizeof(t)); 
    t->val = val; 
    t->left = t->right = NULL; 
    return t; 
} 

struct bintree *randtree(int size, int branchchance);
int height(struct bintree *root);
void printTree(struct bintree *root);
void printTreeUtil(struct bintree *root, int space);
struct bintree *prune(struct bintree *root);
void freeTree(struct bintree *root);

int main(void)
{
	/* Intializes random number generator */
	time_t t;
	srand((unsigned) time(&t));	

	int branchChance = 55;
	int maxHeight = 4;
	struct bintree *bt = randtree(maxHeight, branchChance);

	printf("Before: \n");
	printTree(bt);

	printf("Pruned: \n");
	for (int i = 0; i < maxHeight && bt != NULL; ++i)
		bt = prune(bt);
	printTree(bt);

	freeTree(bt);

	return 0;
}

struct bintree *prune(struct bintree *root)
{
	if (root->left == NULL && root->right == NULL && root->val == 0) {
		free(root);
		return NULL;
	}
	if (root->left != NULL)
		root->left = prune(root->left);
	if (root->right != NULL)
		root->right = prune(root->right);
	return root;
}

void freeTree(struct bintree *root)
{
	if (root == NULL)
		return;

	if (root->left != NULL)
		freeTree(root->left);

	if (root->right != NULL)
		freeTree(root->right);
	
	free(root);
	return;
}

struct bintree *randtree(int size, int branchchance)
{
	struct bintree *tree = newBintree(rand() % 2);
	if (size == 1 || branchchance < rand() % 101 ) {
		; // children are already NULL
	} else {
		tree->left = randtree(size-1, branchchance);
		tree->right = randtree(size-1, branchchance);
	}

	return tree;
}

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void printTreeUtil(struct bintree *root, int space) 
{ 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    printTreeUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->val); 
  
    // Process left child 
    printTreeUtil(root->left, space); 
} 

// Wrapper over print2DUtil() 
void printTree(struct bintree *root) 
{ 
   // Pass initial space count as 0 
   printTreeUtil(root, 0); 
} 

int height(struct bintree *root)
{
	if (root == NULL)
		return 0;
	else {
		int l = height(root->left);
		int r = height(root->right);
		return l > r ? l + 1 : r + 1;
	}
}









