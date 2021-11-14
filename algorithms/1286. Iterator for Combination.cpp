class CombinationIterator
{
    set<string> combinations;
    set<string>::iterator cur;
public:
    CombinationIterator(string characters, int combinationLength)
    { 
        for (int i = 0; i < 1 << characters.size(); ++i)
        {
            string t = "";
            
            for (int j = 0; j < characters.size(); ++j)
            {
                if (i & (1 << j))
                {
                    t += characters[j];
                }
            }
            
            if (t.size() == combinationLength)
            {
                combinations.insert(t);
            }
        }
        
        cur = combinations.begin();
    }
    
    string next()
    {
        return *cur++;
    }
    
    bool hasNext()
    {
        return cur != combinations.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */