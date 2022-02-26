class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "+")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(tokens[i] == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            }
            else if(tokens[i] == "*")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(tokens[i] == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            }
            else
            {
                stringstream temp(tokens[i]);
                int x = 0;
                temp >> x;
                st.push(x);
            }
        }
        
        return st.top();
    }
};