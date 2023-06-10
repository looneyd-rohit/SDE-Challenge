/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* l1, Node* l2){
	Node *a = l1, *b = l2, *dummy = new Node(-1);
	Node* ans = dummy;
	while(a && b){
		if(a->data < b->data){
			dummy->child = a;
			dummy = dummy->child;
			a = a->child;
		}else{
			dummy->child = b;
			dummy = dummy->child;
			b = b->child;
		}
	}
	if(a){
		dummy->child = a;
	}else{
		dummy->child = b;
	}
	return ans->child;
}

Node* solve(Node* head){
	if(head==NULL) return NULL;

	if(head->next){
		// next is present --> requires new connection arrangements

		// get the next_node
		Node* next_node = head->next;

		// get the flattened_next list
		Node* flattened_next = solve(next_node);


		// make connections of current list with flattened_next
		head->next = NULL;
		// basically merge two sorted lists
		return merge(head, flattened_next);
	}
	
	return head;
}

Node* flattenLinkedList(Node* head) 
{
	// assuming solve() --> returns a flattened list provided we pass it a head pointer
	return solve(head);
}
