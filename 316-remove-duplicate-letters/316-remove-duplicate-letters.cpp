class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<bool> seen(26,false);
        vector<int> last(26,0);
        for(int i=0;i<s.length();i++)
        {
            last[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(seen[s[i]-'a'])
                continue;
            while(!ans.empty() && ans.back()>s[i] && i<last[ans.back()-'a'])
            {
                
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;
        }
        
        return ans;

    }
};