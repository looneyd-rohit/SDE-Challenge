// Leetcode 445

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
    ListNode* solve(ListNode* l1, ListNode* l2, int carry){
        // base case
        if(!l1 && !l2 && carry==0) return NULL;
        int first = l1 ? l1->val : 0, second = l2 ? l2->val : 0;
        int sum = (first + second + carry);
        int rem = sum % 10;
        carry = sum / 10;
        ListNode* head = new ListNode(rem);
        head->next = solve(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry);
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1rev = reverse(l1);
        ListNode* l2rev = reverse(l2);
        ListNode* sumrev = solve(l1rev, l2rev, 0);
        return reverse(sumrev);
    }
};