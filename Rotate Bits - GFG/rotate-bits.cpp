//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector<int>v;
            d=d%16;
            //(2^16)-1=65535;
            int left=(n<<d | (n>>(16-d)));
            int right=(n>>d | (n<<(16-d)));
            v.push_back(left&65535);
            v.push_back(right&65535);
            return v;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends