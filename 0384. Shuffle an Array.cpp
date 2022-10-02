class Solution
{
    vector<int> v;
public:
    Solution(vector<int>& nums)
    {
        v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> ans(v);
        
        for (int i = 0; i < ans.size(); ++i)
        {
            swap(ans[i], ans[rand() % ans.size()]);
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */