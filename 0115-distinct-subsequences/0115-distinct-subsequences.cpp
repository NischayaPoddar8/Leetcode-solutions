class Solution {

    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(j<0) return 1; // j reached before i
        if(i<0) return 0;

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
        vector<double>prev(n+1,0);

        prev[0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--){

                double pick = 0;
                double notPick = prev[j];

                if(s[i-1]==t[j-1]) pick = prev[j-1];
                prev[j] = pick+notPick;
            }
        }
        return prev[n];
    }
};