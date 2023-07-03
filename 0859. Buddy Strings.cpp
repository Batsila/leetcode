class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        vector<char> da;
        vector<char> db;

        if (A.length() == B.length() and A.length() > 0)
        {
            for (int i = 0; i < A.length(); ++i)
            {
                if (A[i] != B[i])
                {
                    da.push_back(A[i]);
                    db.push_back(B[i]);
                }
            }
            
            if (da.size() == 2)
            {
                return da[1] == db[0] and da[0] == db[1];
            }
            else if (da.size() == 0)
            {
                for (int i = 0; i < A.size() - 1; ++i)
                {
                    for (int j = i + 1; j < A.size(); ++j)
                    {
                        if (A[i] == A[j])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    
        return false;
    }
};