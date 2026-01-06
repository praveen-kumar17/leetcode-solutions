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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* temp=head;
        int length=1;
        while(temp->next!=NULL){
            length++;
            temp=temp->next;
        }
        ListNode* tail=temp;
        tail->next=head;
        k=k%length;
        int rotate=length-k;
        ListNode* newtail=head;
        for(int i=1;i<rotate;i++){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        return newhead;

    }
};