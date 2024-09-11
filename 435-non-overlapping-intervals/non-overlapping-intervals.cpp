class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //greeedy because we are taking the maximum at that point (sorting on the basis of finishing time so that we take oout the min no. of elements from the intervals])
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>res;
        int cnt=0;
        res.push_back({intervals[0]});
        for(int i=1;i<intervals.size();i++){
            if(res.back()[1]>intervals[i][0]){
                cnt++;
            }else res.push_back({intervals[i]});
        }
        return cnt;
    }
};