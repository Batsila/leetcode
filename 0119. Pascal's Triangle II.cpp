class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> ans;
        
        for (int i = 0; i <= rowIndex; ++i)
        {   
            vector<int> t = ans;
            ans.clear();
            
            if (i == 0)
            {
                ans.push_back(1);
            }
            else if (i == 0)
            {
                ans.push_back(1);
                ans.push_back(1);
            }
            else
            {
                ans.push_back(1);
                
                for (int j = 1; j < t.size(); ++j)
                {
                    ans.push_back(t[j - 1] + t[j]);
                }
                
                ans.push_back(1);
            }
        }
        
        return ans;
    }
};