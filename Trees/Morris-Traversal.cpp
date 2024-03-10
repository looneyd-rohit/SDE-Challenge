// https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1

class Solution {
public:
  vector<int> inOrder(Node *root) {
    vector<int> order;
    while (root != NULL) {
      if (root->left == NULL) {
        order.push_back(root->data);
        root = root->right;
      } else {
        Node *temp = root->left;
        while (temp->right && temp->right != root)
          temp = temp->right;

        if (temp->right == NULL) {
          // first time traversal
          temp->right = root;
          root = root->left;
        } else if (temp->right == root) {
          // second time traversal
          order.push_back(root->data);
          temp->right = NULL;
          root = root->right;
        }
      }
    }
    return order;
  }
};

// https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1

class Solution {
public:
  vector<int> preOrder(Node *root) {
    vector<int> order;
    while (root != NULL) {
      if (root->left == NULL) {
        order.push_back(root->data);
        root = root->right;
      } else {
        Node *temp = root->left;
        while (temp->right && temp->right != root)
          temp = temp->right;

        if (temp->right == NULL) {
          // first time traversal
          order.push_back(root->data);
          temp->right = root;
          root = root->left;
        } else if (temp->right == root) {
          // second time traversal
          temp->right = NULL;
          root = root->right;
        }
      }
    }
    return order;
  }
};