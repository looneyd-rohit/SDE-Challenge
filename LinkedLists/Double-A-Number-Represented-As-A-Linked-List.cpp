// Leetcode 2816

// Approach: add two numbers using linked list approach
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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* solve(ListNode* l1, ListNode* l2, int carry=0){
        if(!l1 && !l2 && carry==0) return NULL;
        int first = l1 ? l1->val : 0, second = l2 ? l2->val : 0;
        int sum = (first + second + carry);
        int rem = sum % 10;
        carry = sum / 10;
        ListNode* head = new ListNode(rem);
        head->next = solve(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry);
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* rev_head = reverse(head);
        ListNode* double_head = solve(rev_head, rev_head);
        return reverse(double_head);
    }
};