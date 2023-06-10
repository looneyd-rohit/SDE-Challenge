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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        while(a && b){
            if(a->val < b->val){
                dummy->next = a;
                dummy = dummy->next;
                a = a->next;
            }else{
                dummy->next = b;
                dummy = dummy->next;
                b = b->next;
            }
        }
        if(a){
            dummy->next = a;
        }else if(b){
            dummy->next = b;
        }
        return ans->next;
    }
};