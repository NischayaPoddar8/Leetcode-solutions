class Solution {


    int dfs(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int match = 0;
        if(text1[i]==text2[j]) match = 1+dfs(text1,text2,i-1,j-1,dp);

        int notMatch = 0;
        notMatch = max(dfs(text1,text2,i-1,j,dp),dfs(text1,text2,i,j-1,dp));

        return dp[i][j] = max(match,notMatch);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {

        int s = text1.size();
        int i = s-1;
        int t = text2.size();
        int j = t-1;

        vector<vector<int>>dp(s,vector<int>(t,-1));
        return dfs(text1,text2,i,j,dp);


    }
};