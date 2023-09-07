/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1) copy the next pointers of the linked list
        Node*temp=head;
        Node*newHead=NULL;
        Node*newTail=NULL;
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
                if(newHead==NULL){
                        newHead=newNode;
                        newTail=newNode;
                }else{
                    newTail->next=newNode;
                    newTail=newNode;
                }
                temp=temp->next;
        }
        
        //2)create a map----old to new
        unordered_map<Node*,Node*>mp;
        temp=head;
        Node*temp2=newHead;
        while(temp!=NULL){
            mp[temp]=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }

        //3) join random pointers
        temp=head;
        temp2=newHead;
        while(temp!=NULL){
            temp2->random=mp[temp->random];

            temp=temp->next;
            temp2=temp2->next;
        }
        return newHead;
    }
};