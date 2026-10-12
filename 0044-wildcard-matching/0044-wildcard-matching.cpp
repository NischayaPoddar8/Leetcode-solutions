class Solution {

    bool solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0){
            while(j>=0){
                if(s2[j]!='*') return false;
                j--;
            }
            return true;
        }

        if(j<0) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s2[j]=='*'){

            bool take = solve(s1,s2,i-1,j,dp);
            bool skip = solve(s1,s2,i,j-1,dp);

            return dp[i][j] = (take||skip);
        }

        if(s1[i]==s2[j] || s2[j]=='?') return dp[i][j] = true && solve(s1,s2,i-1,j-1,dp);

        return false;
    }

public:
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(s,p,m-1,n-1,dp);
    }
};