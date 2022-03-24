class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        if(people[0] + people[1] > limit)
            return n;
        else
        {
            int ans = 0;
            int i=0, j=n-1;
            while(i<j)
            {
                if(people[i] + people[j] <= limit)
                {
                    ans++;
                    i++;
                    j--;
                }
                else
                {
                    ans++;
                    j--;
                }
            }
            if(i == j)
                ans ++;
            return ans;
        }
    }
};