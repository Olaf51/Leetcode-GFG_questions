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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesshead = new ListNode(0);
        ListNode* lesstail = lesshead;
          ListNode* morehead = new ListNode(0);
        ListNode* moretail = morehead;
        ListNode* temp = head;
        while(temp){
           if(temp->val < x){
               lesstail->next = new ListNode(temp->val);
               lesstail = lesstail->next;
           }
           else{
               moretail->next = new ListNode(temp->val);
               moretail = moretail->next;
           }
           temp = temp->next;
        }
        lesstail->next = morehead->next;
        return lesshead->next;
       
    }
};