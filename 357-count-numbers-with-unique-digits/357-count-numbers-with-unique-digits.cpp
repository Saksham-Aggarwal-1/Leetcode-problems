class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int ans = 10;
        int temp = 9, temp2 = 9; 
        while(n>1 && temp>0)
        {
            temp = temp*temp2;
            ans += temp;
            temp2--;
            n--;
        }
        return ans;
    }
};