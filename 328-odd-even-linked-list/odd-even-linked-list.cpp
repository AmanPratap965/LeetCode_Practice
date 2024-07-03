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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*odd=head->next;
        ListNode*x=odd;
        ListNode*even=head;
        int cnt=0;
        while(odd!=NULL && odd->next!=NULL){
                even->next=even->next->next;
                odd->next=odd->next->next;
                even=even->next;
                odd=odd->next;
        }
        even->next=x;
        return head;
    }
};