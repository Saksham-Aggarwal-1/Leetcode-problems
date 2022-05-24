class Solution {
public:
    int maxArea(vector<int>& height) {
       int l = 0, h = height.size()-1;
        int ans = -1;
        while(l<h)
        {
            ans = max(ans, (h-l)*min(height[l], height[h]));
            if(height[l]>height[h])
                h--;
            else if(height[l]<height[h])
                l++;
            else
            {
                h--;
            }
        }
        
        return ans;
    }
};