class Solution
{
private:
    unordered_set<int> hull;
    vector<vector<int>> ans;
    
    int get_orientation(vector<int>& p, vector<int>& q, vector<int>& r)
    {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    
    bool is_between(vector<int>& p, vector<int>& i, vector<int>& q)
    {
        bool a = i[0] >= p[0] and i[0] <= q[0] or i[0] <= p[0] and i[0] >= q[0];
        bool b = i[1] >= p[1] and i[1] <= q[1] or i[1] <= p[1] and i[1] >= q[1];
        
        return a and b;
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        if (trees.size() < 4)
        {
            for (int i = 0; i < trees.size(); ++i)
            {
                hull.insert(i);
            }
        }
        else
        {
            int min_x_ind = 0;
            
            for (int i = 0; i < trees.size(); ++i)
            {
                if (trees[i][0] < trees[min_x_ind][0])
                {
                    min_x_ind = i;
                }
            }
            
            int p = min_x_ind;
            
            do
            {
                int q = (p + 1) % trees.size();
                
                for (int i = 0; i < trees.size(); ++i)
                {
                    if (get_orientation(trees[p], trees[i], trees[q]) < 0)
                    {
                        q = i;
                    }
                }
                
                for (int i = 0; i < trees.size(); ++i)
                {
                    if (i != p 
                        and i != q 
                        and get_orientation(trees[p], trees[i], trees[q]) == 0
                        and is_between(trees[p], trees[i], trees[q]))
                    {
                        hull.insert(i);
                    }
                }
                
                hull.insert(q);
                p = q;
            }
            while (p != min_x_ind);
        }
        
        for (int i : hull)
        {
            ans.push_back(trees[i]);
        }
        
        return ans;
    }
};