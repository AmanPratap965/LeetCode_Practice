//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],long long int n , long long int k) {
            deque<long long>dq; 
            vector<long long >ans;
          //calculation first window
          for(int i=0;i<k;i++){
              if(a[i]<0)dq.push_back(i);
          }
          
          //strore answer of first k sized window
          if(dq.size()>0){
              ans.push_back(a[dq.front()]);
          }else{
              ans.push_back(0);
          }
          
          //for rest of the array
          for(int i=k;i<n;i++){
              //removing last  element
              if(!dq.empty() && i-dq.front()>=k){
                  dq.pop_front();
              }
              
              
              //addition
              if(a[i]<0)dq.push_back(i);
              //inserting in answer
              if(dq.size()>0){
                  ans.push_back(a[dq.front()]);
              }else{
                  ans.push_back(0);
              }
          }
          return ans;
 }