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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return nullptr;
        ListNode* f = head;
        ListNode* s = head;
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        f = head;
        while(f->next!= s)f=f->next;
        f->next = s->next;
        s->next = nullptr;
        return head;
        
    }
};