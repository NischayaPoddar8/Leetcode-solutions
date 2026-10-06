class Solution {

    int lcs(string &s,string &t,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j] = 1+lcs(s,t,i-1,j-1,dp);

        return dp[i][j] = max(lcs(s,t,i-1,j,dp),lcs(s,t,i,j-1,dp));
    }

public:
    int minInsertions(string s) {

        int m = s.size();
        string t = "";

        for(int i=m-1;i>=0;i--){
            t+= s[i];
        }

        vector<vector<int>>dp(m,vector<int>(m,-1));
        int commonLen = lcs(s,t,m-1,m-1,dp);

        return m-commonLen;
    }
};