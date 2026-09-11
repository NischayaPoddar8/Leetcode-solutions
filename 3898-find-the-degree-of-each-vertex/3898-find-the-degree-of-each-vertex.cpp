class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>degree;
        int count = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    count++;
                }
            }
            degree.push_back(count);
            count = 0;
        }
        return degree;
    }
};