class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> used = unordered_set<string>(deadends.begin(), deadends.end());
        queue<string> next_lvl_nums;
        int current_lvl = 0;
        
        if (used.find("0000") == used.end())
        {
            next_lvl_nums.push("0000");
        }
        
        while (not next_lvl_nums.empty())
        {
            queue<string> current_lvl_nums = next_lvl_nums;
            next_lvl_nums = queue<string>();
            
            while (not current_lvl_nums.empty())
            {
                string current_num = current_lvl_nums.front();
                current_lvl_nums.pop();
                
                if (current_num == target)
                {
                    return current_lvl;
                }
                
                for (string num : get_neighbors(current_num))
                {
                    if (used.find(num) == used.end())
                    {
                        used.insert(num);
                        next_lvl_nums.push(num);
                    }
                }
            }
            
            ++current_lvl;
        }

        return -1;
    }

    vector<string> get_neighbors(string s)
    {
        vector<string> v;
        
        for (int i = 0; i < 4; ++i)
        {
            for (int j : { 1, 9 })
            {
                string t = s;
                t[i] = '0' + (s[i] - '0' + j) % 10;
                v.push_back(t);
            }
        }
        
        return v;
    }
};