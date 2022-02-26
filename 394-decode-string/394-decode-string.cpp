class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ']')
            {
                string temp;
                while(st.top() != '[')
                {
                    temp += st.top();
                    st.pop();
                }
                
                st.pop();
                int base = 1;
                int k = 0;
                while(!st.empty() && isdigit(st.top()))
                {
                    k += (st.top()-'0')*base;
                    st.pop();
                    base *= 10;
                }
                while(k)
                {
                    for(int j=temp.size()-1;j>-1;j--)
                        st.push(temp[j]);
                    k--;
                }
            }
            
            else
            {
                st.push(s[i]);
            }
        }
        
        string ans;
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};