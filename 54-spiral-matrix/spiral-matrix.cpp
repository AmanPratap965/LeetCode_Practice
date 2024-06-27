class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        int top=0,left=0,right=m-1,bottom=n-1;


        while(left<=right && top<=bottom){
                //left-right
                    for(int i=left;i<=right;i++){
                            ans.push_back(matrix[top][i]);
                    }
                            top++;
                    //top-bottom
                                    for(int i=top;i<=bottom;i++){
                                    ans.push_back(matrix[i][right]);
                                }
                                    right--;
                    if(top<=bottom){
                        //right-left
                    for(int i=right;i>=left;i--){
                        ans.push_back(matrix[bottom][i]);
                    }
                        bottom--;
                    }
                    
                    if(left<=right){
                            //bottom-up
                            for(int i=bottom;i>=top;i--){
                                ans.push_back(matrix[i][left]);
                            }
                                left++;
                    }
                    
        }
        

        return ans;
    }
};