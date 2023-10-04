// Leetcode 1396

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkin; // <id, <checkin station, time>>
    unordered_map<string, pair<int, int>> hash;    // <station to station, <sum of arrival, count of persons>>
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = checkin[id];
        // since p checkouts so erase him
        checkin.erase(id);
        string route = p.first + " - " + stationName;
        hash[p.first + " - " + stationName].first += t-p.second;
        hash[p.first + " - " + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p = hash[startStation + " - " + endStation];
        return (1.0 * p.first) / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */