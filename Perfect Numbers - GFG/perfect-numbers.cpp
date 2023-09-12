//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long sum=0;
        long long i=1;
          while(i*i <= N) {
        // Check if i divides x without leaving a remainder
        if(N % i == 0) {
            sum+=i;
            // Handle the case explained in the 4th
            if(N/i != i) {
                sum+=N/i;
            }
        }
        i++;
    }
    if(sum-N==N)return 1;else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends