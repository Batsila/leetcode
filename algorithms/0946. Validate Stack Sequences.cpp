class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        
        int popped_ind = 0;
        
        for (int item : pushed)
        {
            st.push(item);
            
            while (not st.empty() 
                   and popped_ind < popped.size()
                   and st.top() == popped[popped_ind])
            {
                st.pop();
                ++popped_ind;
            }
        }
        
        return popped_ind == popped.size();
    }
};