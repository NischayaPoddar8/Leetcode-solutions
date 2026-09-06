class Solution {

    int dfs(int idx1,int idx2,string &text1,string &text2,vector<vector<int>>&dp){

        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int match = 0;
        if(text1[idx1]==text2[idx2]){
            match = 1+dfs(idx1-1,idx2-1,text1,text2,dp);
            return dp[idx1][idx2] = match;
        }

        int notMatch = max(dfs(idx1-1,idx2,text1,text2,dp),dfs(idx1,idx2-1,text1,text2,dp));
        return dp[idx1][idx2] = notMatch;

    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int idx1=1;idx1<=m;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(text1[idx1-1]==text2[idx2-1]) dp[idx1][idx2] = 1+dp[idx1-1][idx2-1];
                else dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[m][n];
    }
};