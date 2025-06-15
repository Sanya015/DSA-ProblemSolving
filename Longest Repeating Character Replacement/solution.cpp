//BRUTE FORCE T.C.=O(N^2) S.C.=O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            vector<int> freq(26, 0);
            int maxf=0;
            for(int j=i; j<s.length(); j++){
                freq[s[j]-'A']++;
                maxf=max(maxf, freq[s[j]-'A']);
                int change=j-i+1-maxf;
                if(change<=k) ans=max(ans, j-i+1);
                else break;
            }
        }
        return ans;
    }
};

//SLIDING WINDOW T.C.=O(N*26) S.C.=O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        vector<int> hash(26, 0);
        int maxf=0;
        int maxlen=0;
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxf=max(maxf, hash[s[r]-'A']);
            if((r-l+1-maxf)<=k) maxlen=max(maxlen, r-l+1);
            else{
                hash[s[l]-'A']--;
                for(int i=0; i<26; i++){
                    maxf=max(maxf, hash[i]);
                }
                l++;
            }
            r++;
        }
        return maxlen;
    }
};

//OPTIMISED TC FURTHER AS NO NEED OF UPDATING MAXF ON MOVING L 
//T.C.=O(N) S.C.=O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        vector<int> hash(26, 0);
        int maxf=0;
        int maxlen=0;
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxf=max(maxf, hash[s[r]-'A']);
            if((r-l+1-maxf)<=k) maxlen=max(maxlen, r-l+1);
            else{
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};
