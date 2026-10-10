class Solution {

public:
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        dp[0][0] = 1; // If both are empty they can match

        for(int j=1;j<=n;j++){ // Can pattern p match empty string s
            if(p[j-1]=='*'){
                dp[0][j] = dp[0][j-1]; // If something else is before *
            }
            else dp[0][j] = 0;
        }
        
        for(int i=1;i<=m;i++){ // Empty pattern cant match string s
            dp[i][0] = 0;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    bool take = dp[i-1][j];
                    bool skip = dp[i][j-1];
                    dp[i][j] = (take||skip);
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = 0;
                }
            }
        }

        return dp[m][n];
    }
};