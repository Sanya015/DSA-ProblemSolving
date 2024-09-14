class Solution {
public:

// T.C.=O(MN) S.C.=O(MN)
    void fill(vector<vector<int>>& image, int i, int j, int color, int pre){
        int m=image.size();
        int n=image[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return;
        if((i-1)>=0 && image[i-1][j]==pre) {image[i-1][j]=color; fill(image, i-1, j, color, pre);}
        if((i+1)<m && image[i+1][j]==pre) {image[i+1][j]=color; fill(image, i+1, j, color, pre);}
        if((j-1)>=0 && image[i][j-1]==pre) {image[i][j-1]=color; fill(image, i, j-1, color, pre);}
        if((j+1)<n && image[i][j+1]==pre) {image[i][j+1]=color; fill(image, i, j+1, color, pre);}
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pre=image[sr][sc];
        if(pre!=color){
            image[sr][sc]=color;
            fill(image, sr, sc, color, pre);
        }
        return image;
    }
};
