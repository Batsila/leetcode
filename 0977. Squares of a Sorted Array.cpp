class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        vector<int> ans;
        vector<int> v1;
        vector<int> v2;
        
        for (int i = 0; i < A.size(); ++i)
        {
            if(A[i] < 0)
            {
                v1.push_back(pow(A[i], 2));
            }
            else
            {
                v2.push_back(pow(A[i], 2));
            }
        }
        
        reverse(v1.begin(), v1.end());
    
        auto it1 = v1.begin();
        auto it2 = v2.begin();
            
        while (it1 != v1.end() && it2 != v2.end())
        {
            if (*it1 > *it2)
            {
                ans.push_back(*it2);
                ++it2;
            }
            else
            {
                ans.push_back(*it1);
                ++it1;
            }
        }
        
        while (it1 != v1.end())
        {
             ans.push_back(*it1);
             ++it1;
        }
        
        while (it2 != v2.end())
        {
             ans.push_back(*it2);
             ++it2;
        }
        
        return ans;
    }
};