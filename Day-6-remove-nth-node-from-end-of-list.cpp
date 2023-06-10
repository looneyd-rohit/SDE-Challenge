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
    int solve(ListNode* head, int n){
        if(head==NULL) return 0;
        int pos = 1 + solve(head->next, n);
        if(pos == n+1){
            head->next = head->next->next;
        }
        return pos;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // iterative approach:
        // take two pointers, advance one by n-1 position, and then take the second and advance
        // untill second reaches end
        ListNode *first = head, *second = head;
        while(n--) second = second->next;
        if(second){
            while(second && second->next) first = first->next, second = second->next;
            first->next = first->next->next;
            return head;
        }else{
            return head->next;
        }
    }
};