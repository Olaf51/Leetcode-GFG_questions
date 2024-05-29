/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int n = 0,m=0;
      ListNode* temp = headA;
      while(temp){
        n++;
        temp = temp->next;
      }
      temp = headB;
       while(temp){
        m++;
        temp = temp->next;
      }
      int t = abs(n-m);
      if(n>m){
        while(t){
            headA = headA->next;
            t--;
        }

      }
      else{
        while(t){
            headB = headB->next;
            t--;
        }

      }
      while(headA && headB){
        if(headA == headB)return headA;
        headA = headA->next;
        headB = headB->next;
      }
      return NULL;
    }
};