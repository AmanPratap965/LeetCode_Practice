//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int>adjList[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adjList[node]){
            if(!vis[it]){
                dfs(it,adjList,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjList[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int>vis(V+1,0);
        int cnt=0;
        
        //traversing all the components/provinces in the graph
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjList,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends