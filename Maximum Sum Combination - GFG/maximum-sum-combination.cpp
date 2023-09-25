//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> ans;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        pq.push(make_pair(A[N-1] + B[N-1], make_pair(N-1, N-1)));
        st.insert(make_pair(N-1, N-1));
        
        // iterate upto k
        for(int cnt = 0; cnt < K; cnt++){
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            int i = temp.second.first;
            int j = temp.second.second;
            
            int sum = A[i-1] + B[j];
            pair<int ,int >tep1 = make_pair(i-1,j);
            if(st.find(tep1) ==st.end()){
                pq.push(make_pair(sum, tep1));
                st.insert(tep1);
            }
            sum = A[i] + B[j-1];
            tep1 = make_pair(i, j-1);   
            if(st.find(tep1) ==st.end()){
                pq.push(make_pair(sum, tep1));
                st.insert(tep1);
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends