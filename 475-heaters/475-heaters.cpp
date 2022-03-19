class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = -1;
        for(int x: houses)
        {
            cout<<"entering for loop\n";
            if(binary_search(heaters.begin(), heaters.end(), x)){
                ans=max(ans, 0);
                continue;
            }
            int idx=lower_bound(heaters.begin(), heaters.end(), x)-heaters.begin();
            cout<<"idx found "<<idx<<"\n";
            if(idx>=heaters.size())
                ans=max(ans, x-heaters[heaters.size()-1]);
            else if(idx>0)
                ans=max(ans, min(x-heaters[idx-1], heaters[idx]-x));
            else
                ans=max(ans, heaters[idx]-x);
            cout<<"ans is "<<ans<<"\n";
        }
        
        cout<<"case ends\n";
        return ans;
    }
};