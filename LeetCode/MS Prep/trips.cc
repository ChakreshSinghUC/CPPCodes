#include <iostream>
#include <map>
#include <vector>

using namespace std;

class UndergroundSystem {
  //<user id, time>
  map<int, pair<string, int>> user_card_swipes; // user id->station & time
  map<pair<string, string>, vector<int>>
      trips; // station A, station B --> delta times
public:
  UndergroundSystem() {
    user_card_swipes.clear();
    trips.clear();
  }

  void checkIn(int id, string stationName, int t) {
    user_card_swipes[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    trips[{user_card_swipes[id].first, stationName}].push_back(
        t - user_card_swipes[id].second);
    user_card_swipes.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    double trip_sums = 0;
    for (auto d : trips[{startStation, endStation}]) {
      trip_sums += d;
    }
    return (double)trip_sums / trips[{startStation, endStation}].size();
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

