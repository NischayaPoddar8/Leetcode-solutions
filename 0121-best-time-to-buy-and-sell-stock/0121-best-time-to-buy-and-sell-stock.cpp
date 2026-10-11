class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int m = prices.size();
        int currPrice = prices[0];
        int maxi = 0;

        for(int i=1;i<m;i++){
            if(currPrice>prices[i]) currPrice = prices[i];
            else{
                maxi = max(maxi,prices[i]-currPrice);
            }
        }

        return maxi;
    }
};