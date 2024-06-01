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
    ListNode* merge(ListNode* head1, ListNode* head2){
       
        // ListNode* d = new ListNode(-1);
        // ListNode* m = d;
        // while(head1 && head2){
        //     if(head1->val <=head2->val){
        //         m->next = head1;
        //         m = m->next;
        //         head1 = head1->next;
        //     }
        //     else{
        //         m->next = head2;
        //         m = m->next;
        //         head2 = head2->next;
        //     }
        // }
        // if(head1)m->next = head1;
        // if(head2)m->next = head2;
        // return d->next;
      if(!head1)return head2;
        if(!head2)return head1;
        if(head1->val <= head2->val){
            head1->next = merge(head1->next, head2);
            return head1;
        }
        else{
            head2->next = merge(head1, head2->next);
            return head2;
        }
        return 0;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
       ListNode* head = lists[0];
       for(int i=1;i<lists.size();i++){
        head =  merge(head,lists[i]);
    
       }
      

       return head;
    }
};