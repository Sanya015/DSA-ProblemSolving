#include <bits/stdc++.h> 

// MY SOLUTION
// T.C.=O(N.2^N)+O(2^N) S.C.=O(N)+O(N.2^N)+O(N)
void solve(int index, vector<int>& temp, vector<vector<int>>& ans){
    if(index<0){
        ans.push_back(temp);
        return;
    }
    temp.push_back(0);
    solve(index-1, temp, ans);
    temp.pop_back();
    temp.push_back(1);
    solve(index-1, temp, ans);
    temp.pop_back();

}

vector<string> binaryStrings(string &str) {
    int n=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='?') n++;
    }
    vector<int> temp;
    vector<vector<int>> ans;
    solve(n-1, temp, ans);
    vector<string> s;
    for(int i=0; i<ans.size(); i++){
        string tstr=str;
        for(int j=0; j<n; j++){
            int pos = tstr.find("?");
            if (pos != std::string::npos) {
                tstr.replace(pos, 1, to_string(ans[i][j]));
            }
        }
        s.push_back(tstr);
    }
    return s;
    
}

// T.C. AND S.C. SAME ONLY BUT BETTER AS WE NEED LESSER DATA STRUCTURES FOR THIS
#include <bits/stdc++.h> 

void solve(string str, vector<string>& ans, int index){
    if(index>=str.size()) {
        ans.push_back(str);
        return;
    }
    if(str[index]=='?'){
        str[index]='0';
        solve(str, ans, index+1);
        str[index]='1';
        solve(str, ans, index+1);
        str[index]='?';

    }

    else solve(str, ans, index+1);
    
}

vector<string> binaryStrings(string &str) {
    int n=str.size();
    vector<string> ans;
    solve(str, ans, 0);
    return ans;
}
