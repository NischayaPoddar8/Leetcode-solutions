class Solution {

    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = 1+lcs(s1,s2,i-1,j-1,dp);

        return dp[i][j] = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));

    }


public:
    int longestPalindromeSubseq(string s) {

        int sz = s.size();
        string s2 = "";

        for(char &c : s){
            s2+= c;
        }
        reverse(s2.begin(),s2.end());

        vector<vector<int>>dp(sz+1,vector<int>(sz+1,0));
        
        for(int i=1;i<=sz;i++){
            for(int j=1;j<=sz;j++){
                if(s[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[sz][sz];
    }
};