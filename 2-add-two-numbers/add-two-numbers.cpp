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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=(l1);
        ListNode*temp2=(l2);
        int carry=0;
        ListNode*ans=new ListNode(-1);
        ListNode*dummy=ans;
        while(temp1 && temp2){
            int num=temp1->val+temp2->val+carry;
            int ld=num%10;
            carry=num/10;
            ans->next=new ListNode(ld);
            ans=ans->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int num=temp1->val+carry;
            carry=num/10;
            temp1->val=num%10;
            ans->next=temp1;
            ans=ans->next;
            temp1=temp1->next;
        }
        while(temp2){
            int num=temp2->val+carry;
            carry=num/10;
            temp2->val=num%10;
            ans->next=temp2;
            ans=ans->next;
            temp2=temp2->next;
        }
        if(carry!=0){
            ans->next=new ListNode(carry);
        }
        return dummy->next;
    }
};