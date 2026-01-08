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
    void createduplicates(Node* head){
        Node* temp=head;
        while(temp!=NULL){
        Node* duplicate=new Node(temp->val);
        duplicate->next=temp->next;
        temp->next=duplicate;
        temp=duplicate->next;
        }
    }
    void pointpointers(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copynode=temp->next;
            if(temp->random!=NULL){
                copynode->random=temp->random->next;
            } else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }

    }
    Node* copyList(Node* head){
        Node* curr=head;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(curr!=NULL){
            temp->next=curr->next;
            temp=temp->next;
            curr->next=curr->next->next;
            curr=curr->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        createduplicates(head);
        pointpointers(head);
        return copyList(head);
    }
};