class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // idea: keep a running list of start & end time pairs
        // when looking at an interval, check the end time list.

        // if the start time of the new entry is less than an end time,
        //  check the two overlaps:
        //      new start <= existing end < new end
        //          update with new end
        //      new start < existing start <= new end
        //          update with new start

        // else: add

        vector<vector<int>> result;

        if (intervals.empty())
        {
            return result;
        }

        result.push_back(intervals[0]);

        for (int ii = 1; ii < intervals.size(); ++ii)
        {
            bool set = false;

            // search for a spot:x

            int new_L = intervals[ii][0];
            int new_R = intervals[ii][1];
            for (int jj = 0; jj < result.size(); ++jj)
            {
                int exist_L = result[jj][0];
                int exist_R = result[jj][1];

                // note: both can trigger if new interval is superset of existing

                // what happens if we get [1 2] [3 4] [0 10] -> need to constantly check exisitng?

                // handle setting new start
                if (new_L <= exist_R && exist_R < new_R)
                {
                    set = true;
                    result[jj][1] = new_R
                }
                // handle setting new end
                if (new_L < exist_L && exist_L <= new_R && new_R < exist_R)
            }

            if (!set)
            {
                result.push_back(intervals[ii]);
            }
        }
    }
};