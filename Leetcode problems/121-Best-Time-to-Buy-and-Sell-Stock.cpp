class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int buy_price = prices[0];
        int profit = 0;
        for(int sell = 1; sell < prices.size(); sell++){
            if(prices[sell] < buy_price){
                buy_price = prices[sell];
            }
            else{
                profit = max(profit, prices[sell] - buy_price);
            }
        }
        return profit;
    }
};