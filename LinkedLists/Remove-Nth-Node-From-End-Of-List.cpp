// Leetcode 19

// Approach 1: 2 Pass solution
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
  int calculateLength(ListNode *head) {
    int l = 0;
    while (head) {
      head = head->next;
      l++;
    }
    return l;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // calculate the length of the list first
    // then remove l-n th node from first
    int len = calculateLength(head);
    int k = len - n;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *temp = dummy;
    while (temp && k--) {
      temp = temp->next;
    }
    if (temp->next)
      temp->next = temp->next->next;
    return dummy->next;
  }
};


// Approach 2: 1 pass solution
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 1 pass solution
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *first = dummy;
    int temp = n;
    while (temp--)
      first = first->next;
    ListNode *second = dummy;
    while (first->next) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
  }
};