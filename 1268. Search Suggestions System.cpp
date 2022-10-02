class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        
        for (int k = 0; k < searchWord.size(); ++k)
        {
            vector<string> currAns;
            
            for (int i = 0; i < products.size(); ++i)
            {
                if (currAns.size() == 3)
                {
                    break;
                }
                
                int j = 0;
                
                for (; j < k + 1; ++j)
                {
                    if (searchWord[j] != products[i][j])
                    {
                        break;
                    }
                }
                
                if (j == k + 1)
                {
                    currAns.push_back(products[i]);
                }
            }
            
            ans.push_back(currAns);
        }
        
        return ans;
    }
};