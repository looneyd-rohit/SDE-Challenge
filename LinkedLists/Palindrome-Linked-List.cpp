// Leetcode 234

// Approach 1: reversing second half
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
  ListNode *reverse(ListNode *head) {
    ListNode *prev = NULL;
    while (head != NULL) {
      ListNode *t = head->next;
      head->next = prev;
      prev = head;
      head = t;
    }
    return prev;
  }
  bool isPalindrome(ListNode *head) {
    if (head == NULL or head->next == NULL)
      return true;
    ListNode *slow = head, *fast = head;
    ListNode *prev = NULL;
    while (fast != NULL and fast->next != NULL) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast == NULL) {
      fast = prev->next;
      prev->next = NULL;
    } else if (fast->next == NULL) {
      fast = slow->next;
      prev->next = NULL;
    }
    slow = head;
    fast = reverse(fast);

    while (slow != NULL) {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }
    return true;
  }
};

// Approach 2: using stack data structure
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
  bool isPalindrome(ListNode *head) {
    // let's use a stack based approach
    stack<ListNode *> st1, st2;
    ListNode *temp = head;
    while (temp) {
      st1.push(temp);
      temp = temp->next;
    }
    int sz = st1.size();
    int h = sz / 2;
    while (h--) {
      st2.push(st1.top());
      st1.pop();
    }
    if (st2.size() < st1.size())
      st1.pop();
    while (!st1.empty() && !st2.empty()) {
      if (st1.top()->val != st2.top()->val)
        return false;
      st1.pop();
      st2.pop();
    }
    return true;
  }
};

// Approach 3: using only recursion (only auxillary stack space)
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
  ListNode *curr;
  bool solve(ListNode *root) {
    if (root == NULL) {
      return true;
    }

    bool next = solve(root->next);
    bool current = curr->val == root->val;
    curr = curr->next;
    return (current && next);
  }
  bool isPalindrome(ListNode *head) {
    curr = head;
    return solve(head);
  }
};