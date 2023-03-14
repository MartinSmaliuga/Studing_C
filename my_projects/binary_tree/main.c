#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	long value;
	struct node* left;
	struct node* right;
}node;

int find(node root, int value)
{
	if (root.value == value)
		return 1;
	if (root.value > value && root.left != NULL)
		return find(*(root.left), value);
	else if (root.right != NULL)
		return find(*(root.right), value);
	else
		return 0;
}

int add(node root, int value)
{
	if (root.value == value)
		return 0;
	if (root.value > value)
	{
		if (root.left == NULL)
		{
			node* leaf = malloc(sizeof(node));
			(*leaf).value = value;
			root.left = leaf;
			return 1;
		}
		else
			return add(*(root.left), value);
	}
	else if (root.right == NULL)
	{
		node* leaf = malloc(sizeof(node));
		(*leaf).value = value;
		root.right = leaf;
		return 1;
	}
	else
		return add(*(root.right), value);
}

node* findToRemove(node root, int value)
{
	if (root.left != NULL && root.value > value)
	{
		node left = *(root.left);
		if (left.value == value)
			return &root;
		else
			return findToRemove(left, value);
	}
	if (root.right != NULL && root.value < value)
	{
		node right = *(root.right);
		if (right.value == value)
			return &root;
		else
			return findToRemove(right, value);
	}
	return NULL;
}

void mergeRightIsNull(node left, node right)
{
	left.right = &right;
}
void mergeLeftIsNull(node left, node right)
{
	right.left = &left;
}

node merge(node left, node right)
{
	node* potentialConnectionPoints[2] = { left.right, right.left };
	int i = 0;
	while (i < 2)
	{
		if (potentialConnectionPoints[i] == NULL)
		{
			*potentialConnectionPoints[i] = right;
			return left;
		}
		i++;
		if (potentialConnectionPoints[i] == NULL)
		{
			*potentialConnectionPoints[i] = left;
			return right;
		}
		potentialConnectionPoints[i] = *(potentialConnectionPoints[i])->left;
		i--;
		potentialConnectionPoints[i] = *(potentialConnectionPoints[i])->right;
	}
}

node remove(node root, int value)
{
	if (root.value == value)
	{
		root = merge(*(root.left), *(root.right));
	}
	else
	{
		node* preseizable = findToRemove(root, value);
		if (preseizable != NULL)
		{
			if ((*(*preseizable).left).value == value)
				mergeLeftIsNull(merge((*(*(*preseizable).left).left), (*(*(*preseizable).left).right)), *preseizable);
			else
				mergeRightIsNull(*preseizable, merge((*(*(*preseizable).right).left), (*(*(*preseizable).right).right)));
		}
	}
	return root;
}

int main(void)
{
	node root = { rand() % 101, NULL, NULL };
	for (int i = 0; i < 17; i++)
	{
		add(root, rand() % 101);
	}
	return 0;
}