class Solution {
public:
// T.C.=O(9^m) S.C.=O(m) recursion stack space (m is no of empty cells)
    bool check(vector<vector<char>>& board, int i, int j, int ele){
        for(int k=0; k<9; k++){
            if(board[i][k]==ele) return false;
            if(board[k][j]==ele) return false;
            if(board[(i/3)*3+k/3][(j/3)*3+k%3]==ele) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int ele='1'; ele<='9'; ele++){
                        if(check(board, i, j, ele)){
                            board[i][j]=ele;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

};
