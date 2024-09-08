class Solution {
public:
// T.C.=O(N*(M+L)) S.C.=O(1) (N is no of words in dict, M is length of s, L is length of largest word in dict)
    bool isSub(string s, string word){
        int i=0, j=0;
        while(i<s.size() && j<word.size()){
            if(s[i]==word[j]){
                j++;
            }
            i++;
        }
        if(j==word.size()) return true;
        return false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(string word:dictionary){
            if(isSub(s, word)){
                if(word.size()>ans.size() || (word.size()==ans.size() && word<ans)) ans=word;
            }
        }
        return ans;
    }
};
