/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        if(head == NULL) return NULL;


        if(head->child){
            // child present --> make new connections
            
            // store next_node
            Node* next_node = head->next;

            // get flattened_child head
            Node* flattened_child = solve(head->child);

            // make connections of current node to child node
            head->next = flattened_child;
            head->child = NULL;
            flattened_child->prev = head;

            // make connections of next node to child node
            while(flattened_child->next) flattened_child = flattened_child->next;
            flattened_child->next = next_node;
            if(next_node){
                next_node->prev = flattened_child;
            }
        }

        // call for next node in the list
        solve(head->next);
        return head;
    }
    Node* flatten(Node* head) {
        // best solution will be to do a recursive approach since child can have child and so on...
        // hypothesis: solve() --> assuming we pass the head of a node and it returns after flattening it
        return solve(head);
    }
};