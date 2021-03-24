class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            unordered_set<int> us;
            us.insert(s[i]);
            int temp_ans = 1;
            
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (us.find(s[j]) == us.end())
                {
                    us.insert(s[j]);
                    ++temp_ans;
                }
                else
                {
                    break;
                }
            }
            
            if (temp_ans > ans)
            {
                ans = temp_ans;
            }
        }
        
        return ans;
    }
};