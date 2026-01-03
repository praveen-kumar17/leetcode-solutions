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
    ListNode* mergesorted(ListNode* left,ListNode* right){
        ListNode dummy(-1);
        ListNode* temp=&dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        while(left!=NULL){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        while(right!=NULL){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return dummy.next;
    }
    ListNode* sortinglist(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left=head;
        left=sortinglist(left);
        right=sortinglist(right);
        return mergesorted(left,right);
    }
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode*right=middle->next;
        middle->next=nullptr;
        ListNode* left=head;
        left=sortinglist(left);
        right=sortinglist(right);
        return mergesorted(left,right);
    }
};