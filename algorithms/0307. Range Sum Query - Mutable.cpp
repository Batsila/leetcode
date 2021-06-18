class NumArray
{
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums)
    {
        n = nums.size();
        tree = vector<int>(n * 2);
        
        for (int i = 0; i < n; ++i)
        {
            tree[n + i] = nums[i];
        }
        
        for (int i = n - 1; i > 0; --i)
        {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
        
    }
    
    void update(int index, int val)
    {
        index += n;
        int d = val - tree[index];
        
        while (index > 0)
        {
            tree[index] += d;
            
            index /= 2;
        }
    }
    
    int sumRange(int left, int right)
    {
        left += n;
        right += n;
        int sum = 0;
        
        while (left <= right)
        {
            if (left % 2)
            {
                sum += tree[left];
                ++left;
            }
            
            if (not (right % 2))
            {
                sum += tree[right];
                --right;
            }
            
            left /= 2;
            right /= 2;
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */