class Solution {
public:
    bool solve(int mid,vector<int>&piles,int h){
        long total=0;
        for(auto it:piles){
            total+=it/mid;
            if(it%mid !=0)total++;
        }
        return total<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //find max element in array
        int r=0;
        for(int i=0;i<piles.size();i++)r=max(r,piles[i]);
        cout<<r;
        //applying binary Search
        int l=1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
             if(solve(mid,piles,h)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};