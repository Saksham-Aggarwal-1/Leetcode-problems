class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        return a[1]<b[1];
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i: arr)
            mp[i]++;
        vector<vector<int>> temp;
        for(auto x: mp)
        {
            temp.push_back({x.first, x.second});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        int i;
        for(i=0;i<temp.size();i++)
        {
            k-=temp[i][1];
            if(k<=0)
                break;
        }
        if(k==0)
            return temp.size()-i-1;
        else if(k<0)
            return temp.size()-i;
        else
            return 0;
        
        // return 0;
    }
};