class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1=m-1;
        int ind2=0;
        while(ind1>=0 && ind2<n){
            if(nums1[ind1]>nums2[ind2]){
                swap(nums1[ind1--],nums2[ind2++]);
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        // sort
    }
};