class Solution {
public:
    int candy(vector<int>& ratings) {
        int peak=1,down=1;
        int sum=1,i=1;
        int n=ratings.size();
        while(i<n){
            //for static graph
            if(ratings[i]==ratings[i-1]){
                    sum+=1;
                    i++;
                    continue;
            }
            peak=1;
            //for increased graph slope
            while(i<n && ratings[i]>ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            down=1;
            //for decreaseing slope
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down+=1;
                i++;
            }
            //checking the case where down > up (that means the top most value must be different)
            if(down>peak){
                sum+=down-peak;
            }
            
        }
        
            return sum;
    }
};