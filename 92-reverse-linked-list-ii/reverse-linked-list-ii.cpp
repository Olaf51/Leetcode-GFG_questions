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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dumy = new ListNode(-1);
          ListNode* preleft = dumy;
            ListNode* currleft = head;
            preleft->next = head;
            for(int i=0;i<left-1;i++){
                preleft = preleft->next;
                currleft = currleft->next;
            }
              ListNode* stand = currleft;
                ListNode* pre = NULL;
              for(int i=0;i<=right-left;i++){
                    ListNode* nextcurr = currleft->next;
                    currleft->next = pre;
                    pre = currleft;
                    currleft = nextcurr;
              }
              preleft->next = pre;
              stand->next = currleft;
              return dumy->next;


        
    }
};