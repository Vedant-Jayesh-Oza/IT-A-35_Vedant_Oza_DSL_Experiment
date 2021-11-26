//IT-A-35_Vedant_Oza
// C program to convert a binary tree to its mirror
#include <stdio.h>
#include <stdlib.h>
/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.
So the tree...
	4
	/ \
	2 5
	/ \
1 3
is changed to...
	4
	/ \
	5 2
		/ \
	3 1
*/
void mirror(struct Node *node)
{
	if (node == NULL)
		return;
	else
	{
		struct Node *temp;
		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);
		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
int countnodes(struct Node *root)
{
	int count = 0;
	if (root != NULL)
	{
		countnodes(root->left);
		count++;
		countnodes(root->right);
	}
	return count;
}
/* Returns a tree which is exact copy of passed tree */
struct Node *cloneBinaryTree(struct Node *root)
{
	if (root == NULL)
		return NULL;
	/* create a copy of root node */
	struct Node *NNew = newNode(root->data);
	/* Recursively create clone of left and right sub tree */
	NNew->left = cloneBinaryTree(root->left);
	NNew->right = cloneBinaryTree(root->right);
	/* Return root of cloned tree */
	return NNew;
}
/* Helper function to print Inorder traversal.*/
void inOrder(struct Node *node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}
/* Driver program to test mirror() */
int main()
{
	struct Node *clone;
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	/* Print inorder traversal of the input tree */
	printf("Inorder traversal of the constructed tree is \n");
	inOrder(root);
	/* Convert tree to its mirror */
	mirror(root);
	/* Print inorder traversal of the mirror tree */
	printf("\nInorder traversal of the mirror tree is \n");
	inOrder(root);
	/*Clone or copy Tree*/
	clone=cloneBinaryTree(root);
	/*InOrder traversal of clone tree */
	printf("\nInorder traversal of the Clone Tree is\n");
	inOrder(clone);
	printf("\nNumber of nodes in tree = %d", countnodes(root));
	return 0;
}