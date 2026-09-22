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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* temp = head;
        vector<int>sorted;
        while(temp){
            sorted.push_back(temp->val);
            temp = temp->next;
        }
        sort(sorted.begin(),sorted.end());
        temp = head;
        int ptr = 0;
        while(temp){
            temp->val = sorted[ptr++];
            temp = temp->next;
        }
        return head;
    }
};