class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1.length() == 0 || word2.length() == 0)
            return word1+word2;
        if(word1 >= word2)
            return word1[0]+largestMerge(word1.substr(1),word2);
        
        else
            return word2[0]+largestMerge(word1,word2.substr(1));
    }
};