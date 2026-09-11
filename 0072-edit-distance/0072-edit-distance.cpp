class Solution {

    int dfs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        int replace = 1e8;
        int del = 1e8;
        int insert = 1e8;

        if(s1[i]==s2[j]) return dp[i][j] = dfs(s1,s2,i-1,j-1,dp);
        else{
            replace = dfs(s1,s2,i-1,j-1,dp);
            del = dfs(s1,s2,i-1,j,dp);
            insert = dfs(s1,s2,i,j-1,dp);
        }

        return dp[i][j] = 1+min({replace,del,insert});
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs(word1,word2,m-1,n-1,dp);
    }
};