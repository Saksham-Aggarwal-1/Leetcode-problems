class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char c: num)
        {
            while(k>0 && !s.empty() && s.top()>c)
            {
                s.pop();
                k--;
            }
            if(c == '0' && s.empty())
                continue;
            s.push(c);
        }
        
        while(k>0 && !s.empty())
        {
            s.pop();
            k--;
        }
        if(s.empty())
            return "0";
        int n = num.length();
        while(!s.empty())
        {
            num[n-1] = s.top();
            n--;
            s.pop();
        }
        
        return num.substr(n);
    }
};