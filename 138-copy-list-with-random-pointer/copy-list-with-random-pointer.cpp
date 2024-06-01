/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  void inb(Node* head){
    Node* temp = head;
   
    while(temp){
        Node* ne = temp->next;
     Node* cn = new Node(temp->val);
     cn->next = ne;
     temp->next = cn;
     temp = ne;
    }
  }
  void mrn(Node* head){
    Node* temp = head;
    while(temp){
        Node* cn = temp->next;
        if(temp->random)
        cn->random = temp->random->next;
        else
        cn->random = NULL;
        temp = temp->next->next;
    }
  }
    Node* dc(Node* head){
        Node* d = new Node(-1);
        Node* temp = head;
        Node* x = d;
        while(temp){
            x->next = temp->next;
            temp->next = temp->next->next;
            x = x->next;
            temp = temp->next;
        }
        return d->next;
    }
    Node* copyRandomList(Node* head) {
        inb(head);
        mrn(head);
        return dc(head);
        
    }
};