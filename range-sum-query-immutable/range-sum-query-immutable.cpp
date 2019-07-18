class NumArray {
    public:
        NumArray(vector<int>& nums) 
        {
            if (nums.empty())
            {
                return;
            }


            int running_total = 0;
            for (int ii = 0; ii < nums.size(); ++ii)
            {   
                running_total += nums[ii];
                sums[0][ii] = running_total;
            }

        }   

        int sumRange(int i, int j) {
            return sums[0][j] - ((i == 0) ? 0 : sums[0][i-1]);
        }   
    private:
        unordered_map<int, unordered_map<int, int>> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

