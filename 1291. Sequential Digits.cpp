class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        set<int> ans;
        
        for (int i = 1; i < 10; ++i)
        {
            int num = i;
            
            for (int j = i + 1; j < 10; ++j)
            {
                num *= 10;
                num += j;
                
                if (num >= low and num <= high)
                {
                    ans.insert(num);
                }
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};