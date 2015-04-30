#include <stdlib.h>

#include "../include/util.h"

struct node {
	int val;
	unsigned int count;
	struct node *left;
	struct node *right;
};

static struct node *
btree_rotate_right(struct node *root)
{
	struct node *new_root;
	
	if (root == NULL) {
		return root;
	}

	new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;

	return new_root;
}

static struct node *
btree_rotate_left(struct node *root)
{
	struct node *new_root;

	if (root == NULL) {
		return root;
	}

	new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;

	return new_root;
}

unsigned int
btree_depth_find(struct node *root)
{
	unsigned int n_left;
	unsigned int n_right;

	if (root == NULL) {
		return 0;
	}

	n_left = btree_depth_find(root->left);
	n_right = btree_depth_find(root->right);

	return MAX(n_left, n_right);
}

struct node *
btree_find_node(struct node *root, int value)
{

	if (root == NULL) {
		return NULL;
	}

	if (root->val == value) {
		return root;
	}

	if (value < root->val) {
		return btree_find_node(root->left, value);
	}

	return btree_find_node(root->right, value);
}

struct node *
btree_rebalance(struct node *root)
{
	/* STUPID NAIVE SOLUTION */
	unsigned int n_left = btree_depth_find(root->left);
	unsigned int n_right = btree_depth_find(root->right);
	unsigned int distance = abs(n_left - n_right);

	if (n_left > n_right) {
		for (unsigned int i = 0; i < distance; i++) {
			root = btree_rotate_right(root);
		}
	} else {
		for (unsigned int i = 0; i < distance; i++) {
			root = btree_rotate_left(root);
		}
	}

	return root;
}

struct node *
btree_node_create(int value)
{
	struct node *n = calloc(1, sizeof(struct node));

	n->val = value;
	n->count = 1;

	return n;
}

void
btree_node_add(struct node *root, int value)
{
	
	if (value == root->val) {
		root->count++;
		return;
	}

	if (value < root->val) {
		if (root->left == NULL) {
			root->left = btree_node_create(value);
		} else {
			btree_node_add(root->left, value);
		}
	}

	if (root->right == NULL) {
		root->right = btree_node_create(value);
	} else {
		btree_node_add(root->right, value);
	}
}

struct node *
btree_build_from_array(int input[], unsigned int n_items)
{
	struct node *root;

	if (n_items > 0) {
		root = btree_node_create(input[0]);
	}

	for (unsigned int i = 1; i < n_items; i++) {
		btree_node_add(root, input[i]);
	}

	root = btree_rebalance(root);

	return root;
}

int
main(int argc, char **argv)
{
	int x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

}
