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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len = 1;
        ListNode* temp = head;
        while(temp && temp->next){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        temp = head;
        k = k % len;
        len = len - k;
        while(k--){
            temp = temp->next;
        }
        ListNode* prev = NULL;
        ListNode* temp2 = head;
        while(len--){
            temp = temp->next;
            prev = temp2;
            temp2 = temp2->next;
        }
        prev->next = NULL;
        return temp2;
    }
};