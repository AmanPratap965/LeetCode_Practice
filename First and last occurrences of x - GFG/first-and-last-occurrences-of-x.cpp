//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
           vector<int> a;
        for (int i=0;i<n;i++){
            if (arr[i]==x && arr[i-1]!=x){
                a.push_back(i);
            }
            if (arr[i]==x && arr[i+1]!=x){
                a.push_back(i);
            }
        }
        if (a.empty()){
            a.push_back(-1);
            
            a.push_back(-1);
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends