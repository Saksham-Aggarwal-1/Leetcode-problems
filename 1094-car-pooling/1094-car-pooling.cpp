class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> total(1001, 0);
        for(auto v: trips)
        {
            for(int i=v[1];i<v[2];i++)
                total[i] += v[0];
        }
        
        for(int i:total)
        {
            if(i>capacity)
                return false;
        }
        
        return true;
    }
};