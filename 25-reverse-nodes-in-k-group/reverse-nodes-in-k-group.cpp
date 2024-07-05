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
    void reverse(ListNode*head){
        if(head==NULL || head->next==NULL)return ;
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            ListNode*temp=prev;
            prev=curr;
            curr=curr->next;
            prev->next=temp;
        }
       head=prev;
    }
    ListNode*findKthNode(ListNode*temp,int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode*temp=head;
        ListNode*prevNode=NULL;
        while(temp!=NULL){
            ListNode*kthNode=findKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode)prevNode->next=temp;
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
           reverse(temp);
            if(temp==head){
                head=kthNode;
                
            }else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};