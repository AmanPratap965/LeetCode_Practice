class Solution {
public:
    // int mod=1e9+7;
    int cnt=0;
    void merge(vector<int>&arr,int l,int mid,int r){
        vector<int>temp;
        int right=mid+1;
        int left=l;
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
               
            }else{
                temp.push_back(arr[right++]);
            }
            
        }
        while(left<=mid)temp.push_back(arr[left++]);
        while(right<=r)temp.push_back(arr[right++]);
        
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
    }
    int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] >(long long) 2 * (long long)arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
    void mergeSort(int l,int r,vector<int>&arr){
      if(l>=r)return ;
      int mid=l+(r-l)/2;
     mergeSort(l,mid,arr);
     mergeSort(mid+1,r,arr);
     cnt+=countPairs(arr,l,mid,r);
       merge(arr,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return cnt;
    }
};