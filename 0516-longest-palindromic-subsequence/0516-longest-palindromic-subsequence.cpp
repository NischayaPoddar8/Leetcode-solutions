class Solution {

    int dfs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = 1+dfs(s1,s2,i-1,j-1,dp);

        return dp[i][j] =  max(dfs(s1,s2,i-1,j,dp),dfs(s1,s2,i,j-1,dp));
    }

public:

    int longestPalindromeSubseq(string s) {

        string s2 = "";
        int m = s.size();
        for(int i=m-1;i>=0;i--){
            s2+= s[i];
        }
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return dfs(s,s2,m-1,m-1,dp);
    }
};