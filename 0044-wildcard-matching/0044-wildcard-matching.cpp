class Solution {

public:
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();

        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);

        prev[0] = 1; // dp[0][0] = 1 as prev[0] is 0th row

        for(int j=1;j<=n;j++){ 
            if(p[j-1]=='*'){
                prev[j] = prev[j-1]; 
            }
            else prev[j] = 0;
        }

        curr[0] = 0; // dp[i][0] = 0

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    bool take = prev[j];
                    bool skip = curr[j-1];
                    curr[j] = (take||skip);
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j] = prev[j-1];
                    else curr[j] = 0;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};