// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

// RECURSIVE:
// Function to insert a node in a BST.
void solve(Node* root, int key){
    if(!root) return;
    
    if(root->data < key){
        if(root->right){
            solve(root->right, key);
        }else{
            root->right = new Node(key);
        }
    }else if(root->data > key){
        if(root->left){
            solve(root->left, key);
        }else{
            root->left = new Node(key);
        }
    }
}
Node* insert(Node* root, int Key) {
    solve(root, Key);
    return root;
}

// ITERATIVE:
Node* insert(Node* root, int Key) {
    Node* head = root;
    while(head){
        if(head->data == Key) break;
        else if(head->data > Key){
            if(head->left){
                // element at left already exists
                head = head->left;
            }else{
                // no element at left, insertion to be done
                head->left = new Node(Key);
                break;
            }
        }else{
            if(head->right){
                // element at right already exists
                head = head->right;
            }else{
                // no element at right, insertion to be done
                head->right = new Node(Key);
                break;
            }
        }
    }
    return root;
}