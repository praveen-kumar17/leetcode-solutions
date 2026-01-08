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
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* temp=head;
        unordered_map<Node*,Node*> mpp;
        while(temp!=nullptr){
            mpp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            mpp[temp]->next=mpp[temp->next];
            mpp[temp]->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};