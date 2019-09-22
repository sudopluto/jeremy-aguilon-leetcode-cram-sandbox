class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int min_val = -1;
        if (prices.empty())
        {
            return profit;
        }
        
        for(int ii = 0; ii < prices.size(); ++ii)
        {
            if (min_val == -1 || prices[ii] < min_val)
            {
                min_val = prices[ii];
            }
            else
            {
                profit = (profit < (prices[ii] - min_val)) ? (prices[ii] - min_val) : profit;
            }
            
        }
        
        return profit;
        
    }
};