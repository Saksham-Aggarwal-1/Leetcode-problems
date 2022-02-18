class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = INT_MIN;
        for(int i: piles)
            hi=max(hi, i);
        int ans=hi;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            int sum=0;
            for(int i: piles)
            {
                if(i%mid == 0)
                    sum+=(i/mid);
                else
                    sum+=(i/mid+1);
            }
            if(sum<=h)
            {
                ans=mid;
                hi=mid;
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
    }
};