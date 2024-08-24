//My solution, different than striver's

// RECURSIVE: T.C.=O(3^N) S.C.=O(N)
int solve(vector<vector<int>> &points, int index, int inc){
    if(index<0) return 0;
    int in1=0, in2=0, in3=0;
    if(inc!=1) in1=points[index][0]+solve(points, index-1, 1);
    if(inc!=2) in2=points[index][1]+solve(points, index-1, 2);
    if(inc!=3) in3=points[index][2]+solve(points, index-1, 3);
    return max(in1, max(in2, in3));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(points, n-1, 0);
}

// MEMOIZATION: T.C.=O(12N) S.C.=O(N)+O(4N)
int solve(vector<vector<int>> &points, int index, int inc, vector<vector<int>>& dp){
    if(index<0) return 0;
    int in1=0, in2=0, in3=0;
    if(dp[index][inc]!=-1) return dp[index][inc];
    if(inc!=1) in1=points[index][0]+solve(points, index-1, 1, dp);
    if(inc!=2) in2=points[index][1]+solve(points, index-1, 2, dp);
    if(inc!=3) in3=points[index][2]+solve(points, index-1, 3, dp);
    return dp[index][inc]=max(in1, max(in2, in3));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n-1, 0, dp);
}

TABULATION: T.C.=O(N) S.C.=O(3N)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];
    for(int i=1; i<n; i++){
        dp[i][0]=points[i][0]+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1]=points[i][1]+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2]=points[i][2]+max(dp[i-1][0], dp[i-1][1]);
    }
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

// SPACE OPTIMIZATION: T.C.=O(N) S.C.=O(1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));
    vector<int> prev(3);
    prev={points[0][0], points[0][1], points[0][2]};
    int one=0, two=0, three=0;
    for(int i=1; i<n; i++){
        one=points[i][0]+max(prev[1], prev[2]);
        two=points[i][1]+max(prev[0], prev[2]);
        three=points[i][2]+max(prev[0], prev[1]);
        prev={one, two, three};
    }
    return max(one, max(two, three));
}
