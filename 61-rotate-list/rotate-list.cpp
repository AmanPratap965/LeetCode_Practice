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
        if(head==NULL || head->next==NULL)return head;
        ListNode*tail=head;
        int cnt=1;
        while(tail && tail->next){
            tail=tail->next;
            cnt++;
        }
        tail->next=head;
        int move=cnt-(k%cnt);
        while(move){
            tail=tail->next;
            move--;
        }
        ListNode*x=tail->next;
        tail->next=NULL;
        return x;
    }
};