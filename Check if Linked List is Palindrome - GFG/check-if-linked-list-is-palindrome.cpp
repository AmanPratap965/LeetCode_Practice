//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  Node*reverse(Node*head){
      Node*curr=head;
      Node*prev=NULL;
      while(curr!=NULL){
          Node*forward=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forward;
          
      }
      return prev;
  }
  Node*getMid(Node*head){
     Node*s=head;
     Node*f=head->next;
     while(f!=NULL && f->next!=NULL){
         s=s->next;
         f=f->next->next;
         
     }return s;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {Node*temp=head;
        Node*mid=getMid(temp);
        Node*x=reverse(mid->next);
        while(x!=NULL){
            if(temp->data!=x->data){
                return false;
            }
            temp=temp->next;
            x=x->next;
        }
        
        return true;
    }
};




//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends