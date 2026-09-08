class Solution {

    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0 && j>=0) return 0;
        if(j<0 && i>=0) return 1;
        if(j==0 && i==0) if(s1[i]==s2[j]) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            // take or notTake
            int take = lcs(s1,s2,i-1,j-1,dp);
            int notTake = lcs(s1,s2,i-1,j,dp);
            return dp[i][j] = take+notTake;
        }

        // If not equal
        int notTake = lcs(s1,s2,i-1,j,dp);
        return dp[i][j] = notTake;
        
    }

public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return lcs(s,t,m-1,n-1,dp);
    }
};