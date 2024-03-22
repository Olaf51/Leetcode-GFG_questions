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
    bool isPalindrome(ListNode* head) {
       
    string str;
    while(head){
        str += head->val - '0';
        head = head->next;
    }
    int n = str.size();
   int i=0,j=n-1;
   while(i<=j){
    if(str[i++]!= str[j--])
    return false;
   }
   return true;
        
    }
};