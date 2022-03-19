class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newString = "";
        int i=0;
        for(int x:spaces)
        {
            while(i<x)
            {
                newString += s[i];
                i++;
            }
            newString += " ";
        }
        
        while(i<s.length()){
            newString += s[i];
            i++;
        }
        
        return newString;
    }
};