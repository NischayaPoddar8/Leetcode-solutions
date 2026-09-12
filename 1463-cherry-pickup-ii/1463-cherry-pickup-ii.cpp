class Solution {

    int dfs(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){

        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e9;

        if(i==grid.size()-1){
            if(j1!=j2) return grid[i][j1] + grid[i][j2];
            else return grid[i][j1]; // When both equal
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxStep = -1e9;
        int cherries = (j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]; // At current index
        for(int r1=-1;r1<=1;r1++){
            for(int r2=-1;r2<=1;r2++){
                maxStep = max(maxStep,dfs(i+1,j1+r1,j2+r2,grid,dp));
            }
        }

        return dp[i][j1][j2] = maxStep + cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = dfs(0,0,n-1,grid,dp);
        return ans;
    }
};