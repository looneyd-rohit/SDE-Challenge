// Leetcode 86

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallest = new ListNode(-1);
        ListNode* largest = new ListNode(-1);
        ListNode* dummy1 = smallest;
        ListNode* dummy2 = largest;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                dummy1->next = temp;
                dummy1 = dummy1->next;
            }else{
                dummy2->next = temp;
                dummy2 = dummy2->next;
            }
            temp = temp->next;
        }
        dummy2->next = NULL;
        dummy1->next = largest->next;
        return smallest->next;
    }
};