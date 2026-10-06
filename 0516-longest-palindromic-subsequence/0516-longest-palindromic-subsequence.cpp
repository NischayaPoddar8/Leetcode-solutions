class Solution {

    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int match = 0;
        if(s1[i]==s2[j]) match = 1+lcs(s1,s2,i-1,j-1,dp);

        int notMatch = 0;
        notMatch = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));

        return dp[i][j] = max(match,notMatch);
    }


public:
    int longestPalindromeSubseq(string s) {

        int sz = s.size();
        string s2 = "";

        for(char &c : s){
            s2+= c;
        }
        reverse(s2.begin(),s2.end());

        vector<vector<int>>dp(sz,vector<int>(sz,-1));
        return lcs(s,s2,sz-1,sz-1,dp);
    }
};