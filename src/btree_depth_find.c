
struct node {
	int val;
	unsigned int count;
	struct node *left;
	struct node *right;
};

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

	return max(n_left, n_right);
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
		return btree_find_node(root->left);
	}

	return btree_find_node(root->right);
}

struct node *
btree_rebalance(struct node *root)
{
	/* STUPID NAIVE SOLUTION */
	unsgined int n_left = btree_depth_find(root->left);
	unsigned int n_right = btree_depth_find(root->right);

	if (n_left > n_right) {
	} else {
	}
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
		btree_node_Add(root, input[i]);
	}
}

int
main(int argc, char **argv)
{
	int x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

}
