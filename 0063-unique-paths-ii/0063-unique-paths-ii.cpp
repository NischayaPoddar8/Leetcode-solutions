class Solution {

    int dfs(vector<vector<int>>obstacleGrid,vector<vector<long long>>&dp,int i,int j){

        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = dfs(obstacleGrid,dp,i-1,j);
        int left = dfs(obstacleGrid,dp,i,j-1);

        dp[i][j] = up+left;
        return dp[i][j];

    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,-1));

        int count = dfs(obstacleGrid,dp,m-1,n-1);
        return count;
    }
};