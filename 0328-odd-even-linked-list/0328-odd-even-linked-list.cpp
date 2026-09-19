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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* dummy1 = new ListNode(0);
        ListNode* odd = dummy1;
        ListNode* dummy2 = new ListNode(0);
        ListNode* even = dummy2;
        ListNode* temp = head;
        int counter = 1;

        while(temp){
            if(counter%2!=0){
                odd->next = new ListNode(temp->val);
                odd = odd->next;
            }
            else{
                even->next = new ListNode(temp->val);
                even = even->next;
            }
            counter++;
            temp = temp->next;
        }

        odd->next = dummy2->next;
        return dummy1->next;
    }
};