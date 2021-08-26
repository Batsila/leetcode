class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        stringstream ss(preorder);
        string s;
        int n = 1;
        
        while (getline(ss, s, ','))
        {
            --n;
            
            if (n < 0)
            {
                return false;
            }
            
            if (s != "#")
            {
                n += 2;
            }
        }
        
        return n == 0;
    }
};