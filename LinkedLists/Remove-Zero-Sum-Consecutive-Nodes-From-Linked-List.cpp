// Leetcode 1171

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
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = head;
    map<int, ListNode *> prefix;
    prefix[0] = dummy;
    int sum = 0;
    while (temp) {
      sum += temp->val;
      if (prefix.find(sum) != prefix.end()) {
        // now remove all the remaining nodes in between from map also
        ListNode *sub = prefix[sum]->next;
        int s = sum;
        while (sub != temp) {
          s += sub->val;
          prefix.erase(s);
          sub = sub->next;
        }
        prefix[sum]->next = temp->next;
        temp = temp->next;
      } else {
        prefix[sum] = temp;
        temp = temp->next;
      }
    }
    return dummy->next;
  }
};