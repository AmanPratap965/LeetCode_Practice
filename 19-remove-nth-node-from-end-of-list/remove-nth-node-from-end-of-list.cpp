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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        cout<<len;
        int move=len-n;
        if(move==0)return head->next;
        temp=head;
        while(move){
            move--;
            if(move==0){
                temp->next=temp->next->next;
                return head;
            }
            temp=temp->next;
        }
        return head;
    }
};