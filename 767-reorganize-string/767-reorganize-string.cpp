class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        
        map<char, int> mp;
        for(char x: s)
            mp[x]++;
        
        int max_freq = 0;
        char letter;
        
        for(auto x: mp)
        {
            if(x.second>max_freq)
            {
                max_freq = x.second;
                letter = x.first;
            }
        }
        
        if(max_freq>(n+1)/2)
            return "";
        
        string ans = "";
        ans.resize(n);
        
        int idx = 0;
        while(mp[letter]>0)
        {
            ans[idx] = letter;
            //cout<<letter<<" inserted at position "<<idx<<"\n";
            mp[letter]--;
            idx+=2;
        }
        
        //cout<<"idx is "<<idx<<"\n";
        //cout<<"current string is "<<ans<<"\n";
        cout<<"mp has : \n";
        if(idx>=n)
            idx=1;
        
        for(auto x: mp)
        {
            //cout<<x.first<<" -> "<<x.second<<"\n";
            while(x.second>0)
            {
                ans[idx] = x.first;
                x.second--;
                idx+=2;
                if(idx>=n)
                    idx=1;
            }
        }
        
        return ans;
    }
};