class Solution 
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<string, vector<string>> um;
        
        for (string path : paths)
        {
            string filepath = "";
            int ind = 0;
            
            while (path[ind] != ' ' and ind < path.size())
            {
                filepath += path[ind];
                ++ind;
            }
            
            filepath += "/";
            ++ind;
            
            while (ind < path.size())
            {
                string filename = "";
                string content = "";
                
                while(ind < path.size() and path[ind] != '(')
                {
                    filename += path[ind];
                    ++ind;
                }
                
                ++ind;
                
                while(ind < path.size() && path[ind] != ')')
                {
                    content += path[ind];
                    ++ind;
                }
                
                ++ind;
                
                um[content].push_back(filepath + filename);
                ++ind;
            }
        }
        
        vector<vector<string>> ans;
        
         for (auto item : um)
         {
            if (item.second.size() > 1)
            {
                ans.push_back(item.second);
            }
         }
        
        return ans;
    }
};