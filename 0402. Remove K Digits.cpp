class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
        {
            return "0";
        }
        
        deque<int> new_num;
        new_num.push_back(num[0]);
        
        for (int i = 1; i < num.size(); ++i)
        {
            while (k > 0
                and not new_num.empty()
                and new_num.back() > num[i])
            {
                new_num.pop_back();
                --k;
            }

            new_num.push_back(num[i]);
        }

        while (k > 0 and not new_num.empty())
        {
            new_num.pop_back();
            --k;
        }

        string ans = "";

        while (not new_num.empty())
        {
            if (ans.size() != 0 or new_num.front() != '0')
            {
                ans += new_num.front();
            }
            
            new_num.pop_front();
        }

        return ans == "" ? "0" : ans;
    }
};