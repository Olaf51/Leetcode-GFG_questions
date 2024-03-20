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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* x = list1;
        int i=0;
        while(i<a-1){
            x = x->next;
            i++;
        }
        ListNode* y = x->next;
        i=0;
        while(i<b-a+1){
            y = y->next;
            i++;
        }
        x->next = list2;
        while(list2->next)
        list2 = list2->next;
        list2->next = y;
        return list1;
        
    }
};