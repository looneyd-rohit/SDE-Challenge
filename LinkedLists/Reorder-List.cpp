// Leetcode 143

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
  void reorderList(ListNode *head) {
    stack<ListNode *> st;
    ListNode *temp = head;
    int n = 0;
    while (temp) {
      n++;
      st.push(temp);
      temp = temp->next;
    }
    // go up to n/2
    int k = n / 2;
    temp = head;
    while (k--) {
      ListNode *t = st.top();
      st.pop();
      t->next = temp->next;
      temp->next = t;
      temp = temp->next->next;
    }
    temp->next = NULL;
  }
};