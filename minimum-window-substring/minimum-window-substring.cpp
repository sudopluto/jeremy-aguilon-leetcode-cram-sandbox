class Solution {
public:
    string minWindow(string s, string t) {
        string ret = "";
        if (t.size() > s.size())
        {
            return ret;
        }
        for (const char c : t)
        {
            t_hist[c]++;
            s_hist[c] = 0;
        }

        // idea: sliding window
        // head and tail form a slice of s.
        // increment tail until all letters are found
        // then increment peek until all letters are not found
        // if the slice of head-1 to tail is smaller than the
        // current ret, set the current ret to that slice

        // end when
        // 1) tail reaches one past end
        int head = 0;
        int tail = 0;

        int to_sat = t_hist.size();
        // end when tail is one past end
        while (tail < s.size())
        {
            
            // see if we have a match
            if(t_hist.find(s[tail]) != t_hist.end())
            {
                if (++s_hist[s[tail]] == t_hist[s[tail]])
                {
                    --to_sat;
                    // all satisfied
                    //cout << "to_sat " << to_sat << endl;
                    if (to_sat == 0)
                    {
                        //cout << "all sat" << endl;
                        // easy control
                        while(to_sat == 0)
                        {

                            //cout << "head: " << head << " tail: " << tail << endl;
                            // time to move head, check to see if head is match
                            if (t_hist.find(s[head]) != t_hist.end())
                            {
                                // if we invalidate with our move
                                if (--s_hist[s[head]] < t_hist[s[head]])
                                {
                                    ++to_sat;
                                    if (ret.empty() || ret.size() > (tail - head) + 1 )
                                    {
                                        ret = s.substr(head, (tail - head) + 1);
                                        //cout << ret << endl;
                                    }
                                }
                            }
                            ++head;
                        }
                        //cout << "set unsat" << endl;
                    }
                }
            }
            ++tail;
        }
        return ret;
    }

private:
    unordered_map<char,int> t_hist;
    unordered_map<char,int> s_hist;
};