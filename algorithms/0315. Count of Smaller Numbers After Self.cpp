class Solution
{
    int bit[100001];
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> ans(nums.size());
        
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            ans[i] = query(nums[i] + 10000);
            update(nums[i] + 10001);
        }
        
        return ans;
    }
    
    void update(int ind)
    {
        while (ind <= 100000)
        {
            ++bit[ind];
            ind += ind & (-ind);
        }
            
    }
    
    int query(int ind)
    {
        int c = 0;
        
        while (ind > 0)
        {
            c += bit[ind];
            ind -= ind & (-ind);
        }
        
        return c;
    }
};