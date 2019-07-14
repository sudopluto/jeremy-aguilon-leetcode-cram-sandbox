class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        else if (amount < 0)
        {
            return -1;
        }

        if (memo.find(amount) == memo.end())
        {

            int min = -1;
            for (int ii = 0; ii < coins.size(); ++ii)
            {
                int coin = coins[ii];
                if (amount == coin)
                {
                    return 1;
                }
                // expensive recusion, use memo
                else
                {
                    int result = coinChange(coins, amount - coins[ii]);
                    // if valid
                    if (result != -1)
                    {
                        // no min yet or result is less then current non -1 min
                        if (min == -1 || result < min)
                        {
                            min = result;
                        }
                    }
                }
            }

            // min is now -1 (impossible), or some non trival value (should be memoized)
            memo[amount] = (min == -1) ? -1 : min + 1;
            return memo[amount];
        }
        else
        {
            return memo[amount];
        }
    }

private:
    // will contain the results of previously computed ammounts
    // will be default constructed to empty
    unordered_map<int, int> memo;
};