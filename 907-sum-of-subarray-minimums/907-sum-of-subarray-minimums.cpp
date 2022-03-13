class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            else
                left[i]=-1;
            st.push(i);
        }
//         cout<<"left: ";
//         for(int i:left)
//             cout<<i<<" ";
//         cout<<"\n";
        
        vector<int> right(n, -1);
        stack<int> st1;
        for(int i=n-1;i>-1;i--)
        {
            while(!st1.empty() && arr[st1.top()]>arr[i])
                st1.pop();
            if(!st1.empty())
                right[i] = st1.top();
            else
                right[i] = n;
            st1.push(i);
        }
//         cout<<"right: ";
//         for(int i:right)
//             cout<<i<<" ";
//         cout<<"\n";
        
        long long int sum=0, mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            sum = (sum+(long long)arr[i]*(long long)(i-left[i])*(long long)(right[i]-i))%mod;
        }
        
        return sum;
        
    }
};