class Solution {

    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j){

        if(i==matrix.size()-1 && (j>=0 && j<matrix[0].size())) return dp[i][j] = matrix[i][j];

        if(j<0 || j>=matrix[0].size()) return INT_MAX;

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int downLeft = dfs(matrix,dp,i+1,j-1);
        int down = dfs(matrix,dp,i+1,j);
        int downRight = dfs(matrix,dp,i+1,j+1); 

        return dp[i][j] = matrix[i][j] + min({downLeft,down,downRight});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int ans = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){

                int upLeft = INT_MAX;
                if(j-1>=0) upLeft = dp[i-1][j-1];

                int up = dp[i-1][j];

                int upRight = INT_MAX;
                if(j+1<n) upRight = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min({upLeft,up,upRight});
            } 
        }

        for(int j=0;j<m;j++){
            ans = min(ans,dp[n-1][j]);
        }

        return ans;
    }
};