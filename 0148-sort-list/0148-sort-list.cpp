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
    ListNode* findMid(ListNode*head){
        // if(head==NULL || head->next)return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
                
        }
        return slow;
    }
    ListNode*merge(ListNode*left,ListNode*right){
        if(left==NULL)return right;
        if(right==NULL)return left;
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(left!=NULL && right!=NULL){
           
            if(left->val<=right->val){
                
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }else{
                
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
         
        }

        //if left!=NULL, then join complete left linked list to the temp list
        if(left!=NULL){
           
                temp->next=left;
                // left=left->next;
        }

        //if right!=NULL, then join complete right linked list to the temp list
        if(right!=NULL){
            
                temp->next=right;
                // right=right->next;
        }
        return dummy->next;

    }
    ListNode* sortList(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*left=head;
        ListNode*mid=findMid(head);//first list
        ListNode*right=mid->next;//second list
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};