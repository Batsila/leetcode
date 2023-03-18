class BrowserHistory
{
    vector<string> his;
    int curInd = 0;
    int lastInd = 0;
public:
    BrowserHistory(string homepage)
    {
        his.push_back(homepage);
    }
    
    void visit(string url)
    {
        ++curInd;

        if (his.size() > curInd)
        {
            his[curInd] = url;
        }
        else
        {
            his.push_back(url);
        }

        lastInd = curInd;
    }
    
    string back(int steps)
    {
        curInd = max(0, curInd - steps);

        return his[curInd];
    }
    
    string forward(int steps)
    {
        curInd = min(lastInd, curInd + steps);

        return his[curInd];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */