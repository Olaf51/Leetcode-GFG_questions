// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//   ListNode* kthN(ListNode* temp, int k){
//     while(k){
//         k--;
//         temp = temp->next;
//             }
//             return temp;

//   }
//   ListNode* reverse(ListNode* temp){
//     if(!temp || !temp->next)return temp;
//     ListNode* Last = reverse(temp->next);
//     temp = temp->next->next;
//     temp->next = NULL;
//     return Last;
    
//       }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         ListNode* nxt = NULL,*kth = NULL, *prev=NULL;
//         while(temp){
//           kth = kthN(temp,k);
//           if(!kth){
//             if(prev){
//                 prev->next = temp;
//             }
//             break;
//           }
//           nxt = kth->next;
//           kth->next = NULL;
//           reverse(temp);
//           if(temp == head)
//           head = kth;
//           else
//           prev->next = kth;
//           prev = temp;
//           temp = nxt;


//         }
//         return head;
        
    
        
//     }
// };
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
        int length(ListNode* &head){
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL || length(head) < k){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next =  curr->next;
        int posi = 0;

        while(posi < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            posi++;
        }
        ListNode* ans = prev;
        if(next != NULL){
            head->next = reverseKGroup(next, k);
        }
        return ans;
    }
};