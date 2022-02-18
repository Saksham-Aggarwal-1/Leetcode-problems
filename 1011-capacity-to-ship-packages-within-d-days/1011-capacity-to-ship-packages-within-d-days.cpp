class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int h=0, l=INT_MIN;
        for(int i: weights)
        {
            h+=i;
            l=max(l, i);
        }
        int ans = h;
        
        while(l<h)
        {
            int mid=l+(h-l)/2;
            int temp_ans=0;
            int i=0;
            while(i<weights.size())
            {
                while(i<weights.size() && mid>=weights[i])
                {
                    mid -= weights[i];
                    i++;
                }
                temp_ans++;
                mid=l+(h-l)/2;
            }
            if(temp_ans<=days)
            {
                ans = mid;
                h = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
    }
};