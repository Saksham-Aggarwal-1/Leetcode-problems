class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        vector<int> sumtillnow;
        sumtillnow.push_back(cardPoints[0]);
        for(int i=1;i<n;i++)
            sumtillnow.push_back(sumtillnow.back()+cardPoints[i]);
        if(n == k)
            return sumtillnow.back();
        int k1 = n-k-1;
        int i=0, j=k1+1;
        int ans = sumtillnow[k1];
        while(j<n)
        {
            ans = min(sumtillnow[j]-sumtillnow[i], ans);
            i++;
            j++;
        }
        return sumtillnow.back()-ans;
    }
};