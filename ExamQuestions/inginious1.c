#include <stdio.h>
#include <stdlib.h>
/*
 * Node has a value, @value, and two children, @left and @right.
 * All the children of @left and itself have a smaller value than the node and
 * all the children of @right and itself have a larger value than node
 */
typedef struct node {
  int value;
  struct node *left;  // to smaller values
  struct node *right; // to larger values
} node_t;

typedef struct bt {
  struct node *root;
} bt_t;

/*
 * Return 1 if there is a node containing @value in @tree and 0 otherwise.
 */
int contains(bt_t *tree, int value) {
  node_t *current = tree->root;

  while (current != NULL) {
    if (current->value == value) {
      return 1;
    }
    if (current->value > value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return 0;
}

// Helper function to create a new node
node_t *create_node(int value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Helper function to insert a value into the binary tree
node_t *insert(node_t *root, int value) {
  if (root == NULL) {
    return create_node(value);
  }

  if (value < root->value) {
    root->left = insert(root->left, value);
  } else if (value > root->value) {
    root->right = insert(root->right, value);
  }
  return root;
}

// Function to test the contains function
void test_contains() {
  bt_t tree;
  tree.root = NULL;

  // Insert some values into the tree
  tree.root = insert(tree.root, 5);
  insert(tree.root, 3);
  insert(tree.root, 8);
  insert(tree.root, 2);
  insert(tree.root, 4);
  insert(tree.root, 7);
  insert(tree.root, 9);

  // Test contains function
  printf("Contains 5: %d\n", contains(&tree, 5)); // Should print 1
  printf("Contains 3: %d\n", contains(&tree, 3)); // Should print 1
  printf("Contains 8: %d\n", contains(&tree, 8)); // Should print 1
  printf("Contains 6: %d\n", contains(&tree, 6)); // Should print 0
  printf("Contains 9: %d\n", contains(&tree, 9)); // Should print 1
  printf("Contains 1: %d\n", contains(&tree, 1)); // Should print 0
}

int main() {
  test_contains();
  return 0;
}
