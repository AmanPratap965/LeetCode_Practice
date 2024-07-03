/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode*head){
        if(head==NULL || head->next==NULL)return head;
        ListNode*newNode=reverse(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head2=reverse(slow);
        slow->next=NULL;
        while(head!=NULL && head2!=NULL){
            if(head->val!=head2->val)return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};