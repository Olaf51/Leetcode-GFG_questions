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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* curr = temp;
        int carry = 0;
        while(l1 || l2){
            int sum = 0;
            sum += carry;
            if(l1)sum += l1->val;
            if(l2)sum+= l2->val;
            ListNode* nn = new ListNode(sum%10);
            carry = sum/10;
            curr->next = nn;
            curr = curr->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(carry)curr->next = new ListNode(carry);
        return temp->next;
        
    }
};