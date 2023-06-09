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
    ListNode* solve(ListNode* num1, ListNode* num2, int carry){
        if(num1==NULL && num2==NULL && carry == 0) return NULL;
        int first = (num1 != NULL) ? num1->val : 0;
        int second = (num2 != NULL) ? num2->val : 0;
        int sum = first + second + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode* new_node = new ListNode(sum);
        new_node->next = solve((num1 != NULL) ? num1->next : NULL, (num2 != NULL) ? num2->next : NULL, carry);
        return new_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};