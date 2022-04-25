class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1)
            return s;
        
        for(int r=0;r<numRows;r++)
        {
            int incr = 2*(numRows-1);
            for(int i=r;i<s.length();i+=incr)
            {
                ans += s[i];
                if(r>0 && r<numRows-1 && (i+incr-2*r)<s.length())
                    ans += s[i+incr-2*r];
            }
        }
        
        return ans;
    }
};