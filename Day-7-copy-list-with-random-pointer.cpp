// With Hashing approach:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        // hashing based approach:
        unordered_map<Node*, Node*> umap;
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            Node* copy = new Node(temp->val);
            umap[temp] = copy;
            if(prev){
                prev->next = copy;
            }
            prev = copy;
            temp = temp->next;
        }
        prev->next = NULL;
        // make connections of random pointer:
        temp = head;
        while(temp){
            Node* random = temp->random;
            Node* copy_of_random = umap[random];
            Node* copy = umap[temp];
            copy->random = copy_of_random;
            temp = temp->next;
        }
        return umap[head];
    }
};

// Without Hashing, only reconnections:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        // without using extra space:
        // making and breaking connections:
        // 1. copy the list with only next pointers set, and make reconnections
        Node* temp = head;
        Node* copy_head = NULL;
        while(temp){
            Node* t = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = t;
            temp = t;
        }
        // now make and break connections:
        // 2. make
        temp = head;
        while(temp){
            Node* temp2 = temp->next;
            Node* random = temp->random;
            if(random){
                Node* copy_of_random = random->next;
                temp2->random = copy_of_random;
            }
            temp = temp->next->next;
        }
        // 3. break
        temp = head;
        while(temp){
            Node* temp2 = temp->next;
            if(temp == head){
                copy_head = temp2;
            }
            Node* t = temp2->next;
            temp->next = t;
            if(t){
                temp2->next = t->next;
            }
            temp = temp->next;
        }
        return copy_head;
    }
};