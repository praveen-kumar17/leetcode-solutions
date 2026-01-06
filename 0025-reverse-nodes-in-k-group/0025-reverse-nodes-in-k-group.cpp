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
    ListNode* reversed(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=reversed(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL && cnt<k){
            cnt++;
            temp=temp->next;
        }
        if(cnt<k) return head;
        temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        ListNode* newgroup=temp->next;
        temp->next=NULL;
        ListNode* newhead=reversed(head);
        head->next=reverseKGroup(newgroup,k);
        return newhead;

    }
};