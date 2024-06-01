class Solution {
public:
    int partition(vector<int>&arr,int l,int h){
        int pivot=arr[l];
        int i=l;
        int j=h;
        while(i<j){
            while(arr[i]<=pivot && i<=h-1){
                i++;
            }
            while(arr[j]>pivot && j>=l+1)j--;
            if(i<j)swap(arr[i],arr[j]);
        }
        swap(arr[l],arr[j]);
        return j;
    }
    void qs(vector<int>&arr,int l,int h){
        //sorting it only when the array has more then one element 
        if(l<h){
            swap(arr[l+rand()%(h-l+1)],arr[l]);
            int pIndex=partition(arr,l,h);
            qs(arr,l,pIndex-1);
            qs(arr,pIndex+1,h);
        }

    }
    vector<int> sortArray(vector<int>& nums) {
      qs(nums,0,nums.size()-1);
      return nums;  
    }
};