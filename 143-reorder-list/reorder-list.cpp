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
   ListNode* reversell(ListNode* node){
    if(!node || !node->next)return node;

    ListNode* last = reversell(node->next);
    node->next->next = node;
    node->next = NULL;
    return last;
   }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
        return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reversell(slow);
        ListNode* temp=NULL;
        ListNode* tempb=NULL, *curr = head;
        while(rev->next){
          temp = curr->next;
          tempb = rev->next;
          curr->next = rev;
          rev->next = temp;
          curr = temp;
          rev = tempb;
        }
        
    }
};