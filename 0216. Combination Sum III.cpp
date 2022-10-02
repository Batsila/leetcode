class Solution
{
    int nums[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k;
    vector<vector<int>> ans;
    vector<int> c;
    
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        this->k = k;
        search(0, n);
        
        return ans;
    }
    
    void search(int ind, int r)
    {
        if (r == 0 and c.size() == k)
        {
            ans.push_back(c);
            return;
        }
        
        if (r < 0 or c.size() > k or ind > 8)
        {
            return;
        }
        
        search(ind + 1, r);
        c.push_back(nums[ind]);
        search(ind + 1, r - nums[ind]);
        c.pop_back();
    }
};