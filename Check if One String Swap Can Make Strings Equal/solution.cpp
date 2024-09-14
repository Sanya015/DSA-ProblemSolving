class Solution {
public:

// T.C.=O(N) S.C.=O(1)
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.length();
        int pos1=-1, pos2=-1;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                if(pos1==-1){
                    pos1=i;
                    continue;
                } 
                if(pos2==-1){
                    pos2=i;
                    break;
                }  
            }

        }
        if(pos1!=-1 && pos2!=-1){
            char temp=s2[pos1];
            s2[pos1]=s2[pos2];
            s2[pos2]=temp;
            if(s1==s2) return true;
        }
        
        return false;

    }
};
