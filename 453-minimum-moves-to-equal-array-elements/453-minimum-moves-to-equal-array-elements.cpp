class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minN=INT_MAX;
        for(int x: nums){
            sum+=x;
            minN=min(minN,x);
        }
        return sum - minN*nums.size();
    }
};