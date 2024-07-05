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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head, *nxt = head->next->next;
        int cnt = 2,pt=0,lcnt=2,fcnt=-1;
        ListNode* temp = head->next;
        int maxi=-1,mini=INT_MAX;
        while(nxt){
            if((temp->val < prev->val && temp->val <nxt->val) || (temp->val > prev->val && temp->val > nxt->val)  ){
                pt++;
                if(pt>=2){
                mini = min(mini,cnt-lcnt);
                maxi = max(maxi,cnt-fcnt);
                }
                lcnt = cnt;
                if(fcnt==-1)fcnt = cnt;
                
                
            }
            // else if(){
            //     pt++;
            //     if(pt>=2)
                
            //         lcnt = cnt;
            //         if(fcnt==-1)fcnt = cnt;
            // }
            
            cnt++;
            prev = temp;
             temp = nxt;
            nxt = nxt->next;
        }
        if(pt<2)return {-1,-1};
        if(maxi==-1 && mini!=-1)return {mini,mini};
        if(maxi!=-1 && mini == -1)return {maxi,mini};
        return {mini,maxi};


        
    }
};