class Solution {
public:
    int minSteps(int n) {
        // This can be done by prime factorisation
        int ans=0, factor=2;
        while(n>1)
        {
            while(n%factor == 0)
            {
                n /= factor;
                ans += factor;
            }
            factor++;
        }
        
        return ans;
    }
};