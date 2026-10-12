class Solution {

public:
    int maxProfit(vector<int>& prices) {

        int currBuy = prices[0];
        int m = prices.size();
        int profit = 0;
        
        for(int i=1;i<m;i++){
            if(prices[i]<currBuy) currBuy = prices[i];
            else{
                profit+= prices[i]-currBuy;
                currBuy = prices[i];
            }
        }

        return profit;
    }
};