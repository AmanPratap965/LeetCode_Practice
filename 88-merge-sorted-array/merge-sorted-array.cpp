class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        int gap=(m+n)/2+(m+n)%2;
        
        while(gap>0){
                    int left=0;
                    int right=left+gap;
                while(right<m+n){
                        if(nums1[left]<nums1[right]){left++;right++;}
                        else{
                            swap(nums1[left],nums1[right]);left++;right++;
                        }
        }
            if(gap==1)break;
            gap=(gap+1)/2;
        }
        
    }
};