class Solution {

    int dfs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = 1+dfs(s1,s2,i-1,j-1,dp);

        return dp[i][j] = max(dfs(s1,s2,i-1,j,dp),dfs(s1,s2,i,j-1,dp));
    }

public:
    int minInsertions(string s) {
        
        int m = s.size();
        string rev = "";
        for(int i=m-1;i>=0;i--){
            rev+= s[i];
        }
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==rev[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lenPalindromicSub = dp[m][m];
        return m-lenPalindromicSub;
    }
};