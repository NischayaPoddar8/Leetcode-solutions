class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int>prev(n,INT_MAX);
        prev[0] = triangle[0][0];

        for(int i=1;i<m;i++){
            vector<int>cur(n,INT_MAX);
            for(int j=0;j<triangle[i].size();j++){
                int up = 1e9;
                if(j<i) up = min(up,prev[j]);
                int upLeft = 1e9;
                if(j>0) upLeft = min(upLeft,prev[j-1]);
                cur[j] = triangle[i][j] + min(up,upLeft);
            }
            prev = cur;
        }

        int sum = INT_MAX;
        for(int j=0;j<n;j++){
            sum = min(sum,prev[j]);
        }

        return sum;
    }
};