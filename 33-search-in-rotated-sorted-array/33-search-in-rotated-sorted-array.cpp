class Solution {
public:
    int minindex(vector<int> arr, int n)
    {
        int l=0, h = n-1;
        while(l<h)
        {
            int mid = l+(h-l)/2;
            if(arr[mid] > arr[h])
                l = mid+1;
            else
                h = mid;
        }
        return l;
    }

    int bins(vector<int> arr, int l, int h, int target)
    {
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target)
                h = mid-1;
            else
                l = mid+1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ind = minindex(nums, n);
        int a = bins(nums, 0, ind-1, target);
        int b = bins(nums, ind, n-1, target);
        if(a == -1)
            return b;
        return a;    
    }
};
