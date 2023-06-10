// CodeStudio solution:
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* reverse(Node* head, int k){
	Node* prev = NULL;
	while(head && k--){
		Node* temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	return prev;
}
Node* solve(Node* head, int i, int n, int b[]){
	// base case
	if(head == NULL) return NULL;
	if(i == n) return head;

	int t = b[i];
	if(t == 0) return solve(head, i+1, n, b);
	t--;
	Node* temp = head;
	Node* prev = NULL;
	while(temp && t--){
		prev = temp;
		temp=temp->next;
	}

	if(temp){
		Node* next_part = temp->next;
		Node* new_head = reverse(head, b[i]);
		head->next = solve(next_part, i+1, n, b);
		return new_head;
	}else{
		Node* next_part = prev->next;
		Node* new_head = reverse(head, b[i]);
		head->next = solve(next_part, i+1, n, b);
		return new_head;
	}
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return solve(head, 0, n, b);
}

// Leetcode solution:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        while(head && k--){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* solve(ListNode* head, int k){
        // base case
        if(head == NULL) return NULL;

        int len = 0;
        int t = k-1;
        ListNode* temp = head;
        while(temp && t--){
            temp=temp->next;
        }

        if(temp){
            ListNode* next_part = temp->next;
            ListNode* new_head = reverse(head, k);
            head->next = solve(next_part, k);
            return new_head;
        }else{
            return head;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};