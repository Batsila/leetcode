class Solution 
{
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
    {
        vector<vector<int>> bs;
        
        for (int i = 0; i < B.size(); ++i)
        {
            vector<int> b(26, 0);
            
            for (int j = 0; j < B[i].size(); ++j)
            {
                ++b[B[i][j] - 'a'];
            }
            
            bs.push_back(b);
        }
        
        vector<int> bmax(26, 0);
        
        for (int i = 0; i < bs.size(); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                bmax[j] = max(bmax[j], bs[i][j]);
            }
        }
        
        vector<string> ans;
        
        for (int i = 0; i < A.size(); ++i)
        {
            vector<int> a(26, 0);
            
            for (int j = 0; j < A[i].size(); ++j)
            {
                ++a[A[i][j] - 'a'];
            }
            
            bool c = true;
            
            for (int j = 0; j < 26; ++j)
            {
                if (bmax[j] > a[j])
                {
                    c = false;
                }
            }
            
            if (c)
            {
                ans.push_back(A[i]);
            }
        }
        
        return ans;
    }
};