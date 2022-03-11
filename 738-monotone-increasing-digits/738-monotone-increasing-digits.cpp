class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int temp;
        
        for(int i=num.length()-1;i>0;i--)
        {
            if(num[i]<num[i-1])
            {
                temp = i;
                num[i-1]--;
            }
        }
        
        for(int i=temp;i<num.length();i++)
            num[i] = '9';
        
        return stoi(num);
    }
};