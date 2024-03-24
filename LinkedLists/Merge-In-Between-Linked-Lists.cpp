// Leetcode 1669

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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *first = list1, *second = list1;
    int k = a - 1;
    while (k-- && first)
      first = first->next;
    k = b;
    while (k-- && second)
      second = second->next;
    first->next = list2;
    while (first->next)
      first = first->next;
    first->next = second->next;
    return list1;
  }
};