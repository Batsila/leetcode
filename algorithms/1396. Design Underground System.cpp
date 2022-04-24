class UndergroundSystem
{
    unordered_map<int, string> checkInStations;
    unordered_map<int, int> checkInTimes;
    unordered_map<string, int> routeTimeSum;
    unordered_map<string, int> routeCount;
public:  
    void checkIn(int id, string stationName, int t)
    {
        checkInStations[id] = stationName;
        checkInTimes[id] = t;
    }
    
    void checkOut(int id, string stationName, int t)
    {
        string route = checkInStations[id] + "_" + stationName;
        routeTimeSum[route] += t - checkInTimes[id];
        ++routeCount[route];
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + "_" + endStation;
        
        return (double)routeTimeSum[route] / routeCount[route];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */