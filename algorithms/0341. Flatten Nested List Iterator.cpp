/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
private:
    vector<int> v;
    int c = 0;
    
    void dfs(NestedInteger &ni)
    {
        if (ni.isInteger())
        {
            v.push_back(ni.getInteger());
        }
        else
        {
            for (auto n : ni.getList())
            {
                dfs(n);
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        for (auto n : nestedList)
        {
            dfs(n);
        }
    }
    
    int next() 
    {
        return v[c++];
    }
    
    bool hasNext() 
    {
        return c < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */