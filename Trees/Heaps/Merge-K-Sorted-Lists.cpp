// Leetcode 23

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
class Compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Compare> minheap;
        for(int i=0; i<k; i++){
            ListNode* t = lists[i];
            if(t){
                minheap.push(t);
            }
        }
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* ans = dummy;
        while(!minheap.empty()){
            auto t = minheap.top(); minheap.pop();
            dummy->next = t;
            dummy = dummy->next;
            ListNode* next = t->next;
            t->next = NULL;
            if(next){
                minheap.push(next);
            }
        }
        return ans->next;
    }
};