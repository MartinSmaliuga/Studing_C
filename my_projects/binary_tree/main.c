#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TREESIZE 20

typedef struct {
	long value;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
}Node;

Node* node_init(long value) {
	Node* new_node = malloc(sizeof(Node));
	new_node->value = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int add_node(Node *root, Node *leaf) {
	if (leaf->value < root->value) {
		if (root->left == NULL) {
			root->left = leaf;
			leaf->parent = root;
			return 1;
		}
		else {
			return add_node(root->left, leaf);
		}
	}
	else if (leaf->value > root->value) {
		if (root->right == NULL) {
			root->right = leaf;
			leaf->parent = root;
			return 1;
		}
		else {
			return add_node(root->right, leaf);
		}
	}
	else
		return 0;
}

Node* find_node(Node* root, long value) {
	if (root->value < value) {
		if (root->right != NULL) {
			return find_node(root->right, value);
		}
		else {
			return NULL;
		}
	}
	else if (root->value > value) {
		if (root->left != NULL) {
			return find_node(root->left, value);
		}
		else {
			return NULL;
		}
	}
	else
		return root;
}

int main(void) {
	Node* leaves[TREESIZE];

	for (int i = 0; i < TREESIZE; i++) {
		leaves[i] = node_init(1 + rand() % 100);
	}

	for (int i = 0; i < TREESIZE; i++) {
		printf("Leaf %d\nValue: %d\nParent: %p\nLeft: %p\tRight: %p\n\n", i, leaves[i]->value, leaves[i]->parent, leaves[i]->parent, leaves[i]->left, leaves[i]->right);
	}

	printf("\n");

	for (int i = 1; i < TREESIZE; i++) {
		printf("Try to add a new leaf...\n");
		if (add_node(leaves[0], leaves[i])) {
			printf("Leaf #%d was successfully added to the tree\n\n", i);
		}
		else
			printf("Failed to add a leaf #%d to the tree\n\n", i);
	}
	
	char ch = 'y';

	while (ch == 'y') {
		long value = 0;
		printf("\nEnter value to search: ");
		scanf("%d", &value);
		while ((getchar()) != '\n');

		Node* result = find_node(leaves[0], value);
		if (result == NULL)
			printf("\nCan't find node with such value\n");
		else {
			printf("\nNode where founded!\nValue: %d\nParent: %p\nLeft node: %p\tRight node: %p\n", result->value, result->parent, result->left, result->right);
		}

		printf("\nWrite \'y\' to search another value: ");
		scanf("%c", &ch);
		while ((getchar()) != '\n');
		printf("\n");
	}
}