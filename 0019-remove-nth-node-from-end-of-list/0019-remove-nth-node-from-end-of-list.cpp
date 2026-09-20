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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(n==1 && head->next==NULL) return NULL;
        ListNode* temp = head;
        int len = 0;

        while(temp){
            temp = temp->next;
            len++;
        }

        temp = head;
        int pos = 1;

        while(temp && pos!=len-n){
            temp = temp->next;
            pos++;
        }
        if(n==len) head = head->next;
        else temp->next = temp->next->next;
        return head;
    }
};