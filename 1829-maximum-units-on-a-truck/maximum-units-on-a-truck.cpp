class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int totalUnits=0;
        int cnt=0;int i=0;
        while(i<boxTypes.size()){
            //if truckSize is greater than boxTypes[i][0]
            if(truckSize>=boxTypes[i][0]){
                totalUnits+=(boxTypes[i][0])*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
                }

            //if truckSize has become less than 0
            else{
                totalUnits+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
            i++;
        }
        return totalUnits;
    }
};