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
        if(!head)return NULL;
        int l=0;
        ListNode* temp = head;
        while(temp){
            l++;
            temp = temp->next;
        }
        int rl = l-n;
        if(rl == 0){
            head = head->next;
            return head;
        }
        temp = head;
        while(rl>1){
            rl--;
          temp = temp->next;
        }
        temp->next = temp->next->next;
       
        return head;
        
    }
};