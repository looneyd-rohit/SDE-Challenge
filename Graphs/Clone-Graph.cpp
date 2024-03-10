// Leetcode 133

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  unordered_map<Node *, Node *> ump; // <prev Node address, new Node address>
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;
    if (ump.find(node) != ump.end())
      return ump[node];
    Node *new_node = new Node(node->val);
    ump[node] = new_node;
    for (int i = 0; i < node->neighbors.size(); i++) {
      Node *child = cloneGraph(node->neighbors[i]);
      if (child != NULL) {
        new_node->neighbors.push_back(child);
      }
    }
    return ump[node] = new_node;
  }
};