class Solution {

    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = 1+lcs(s1,s2,i-1,j-1,dp);

        return dp[i][j] = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
    }

public:
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int len = dp[m][n];
        
        int ans = 0;
        if(len<m && len<n) ans = (m-len) + (n-len);
        else if(m<=len) ans = n-len;
        else ans = m-len;

        return ans;
    }
};