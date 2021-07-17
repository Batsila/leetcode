class Solution
{
public:
    vector<int> threeEqualParts(vector<int>& arr)
    {
        int n = arr.size();
        
        int sum = 0;
        
        for (int num : arr)
        {
            sum += num;
        }
        
        if (sum % 3 != 0)
        {
            return { -1, -1 };
        }
        
        int psum = sum / 3;
        
        if (psum == 0)
        {
            return { 0, n - 1 };
        }
        
        int i1 = -1;
        int j1 = -1;
        int i2 = -1;
        int j2 = -1;
        int i3 = -1;
        int j3 = -1;
        
        int csum = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (arr[i])
            {
                csum += 1;
                
                if (csum == 1)
                {
                    i1 = i;
                }
                
                if (csum == psum)
                {
                    j1 = i;
                }
                
                if (csum == psum + 1)
                {
                    i2 = i;
                }
                
                if (csum == psum * 2)
                {
                    j2 = i;
                }
                
                if (csum == psum * 2 + 1)
                {
                    i3 = i;
                }
                
                if (csum == psum * 3)
                {
                    j3 = i;
                }
            }
        }
        
        vector<int> p1 = get_part(arr, i1, j1);
        vector<int> p2 = get_part(arr, i2, j2);
        vector<int> p3 = get_part(arr, i3, j3);
        
        if (p1 != p2 or p2 != p3)
        {
            return { -1, -1 };
        }
        
        int z1 = i2 - j1 - 1;
        int z2 = i3 - j2 - 1;
        int z3 = n - j3 - 1;
        
        if (z1 < z3 or z2 < z3)
        {
            return { -1, -1 };
        }
        
        return { j1 + z3, j2 + z3 + 1 };
    }
    
    vector<int> get_part(vector<int> v, int s, int e)
    {
        vector<int> p;
        
        for (int i = s; i <= e; ++i)
        {
            p.push_back(v[i]);
        }
        
        return p;
    }
};