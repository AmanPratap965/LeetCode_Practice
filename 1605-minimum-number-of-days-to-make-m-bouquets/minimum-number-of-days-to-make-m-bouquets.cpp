class Solution {
public:
    int solve(vector<int>&arr,int k,int mid){
	int cnt=0;int total=0;
	for(int i=0;i<arr.size();i++){
        if(arr[i]<=mid)cnt++;
        else {
            total+=cnt/k;
            cnt=0;
        }
    }
    total+=cnt/k;
	return  total;
}
    int minDays(vector<int>& arr, int m, int k) {
        
	int l=1;
	int r=0;
	for(auto it:arr)r=max(it,r);
	if((long)k*m>arr.size())return -1;
	while(l<=r){
		int mid=l+(r-l)/2;
		int total=solve(arr,k,mid);
		 if(total>=m)r=mid-1;
		else l=mid+1;
	}
	return l;
    }
};