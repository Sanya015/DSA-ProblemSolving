class Solution {
public:
// T.C.=O(N*M*4^L) L is length of word to search
// S.C.=O(M*N)+O(L)
// SC can be improved when we not use a visited matrix but instead mark every visited node in board as !
    bool trav(vector<vector<char>>& board, string word, int i, int j, int ptr, vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        if(ptr == word.length()) return true;
        int dx[]={-1, 0, 1, 0};
        int dy[]={0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && vis[x][y]!=1 && word[ptr]==board[x][y]){
                vis[x][y]=1;
                if(ptr==word.length()-1) return true;
                if(trav(board, word, x, y, ptr+1, vis)) return true;
                vis[x][y]=0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(trav(board, word, i, j, 1, vis)) return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};
