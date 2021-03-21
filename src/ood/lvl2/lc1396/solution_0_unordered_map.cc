#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem
{
public:
    UndergroundSystem()
    {
    }

    void CheckIn(int id, string station_name, int t)
    {
        check_in_map[id] = {station_name, t};
    }

    void CheckOut(int id, string station_name, int t)
    {
        auto &check_in = check_in_map[id];
        string route = check_in.first + "_" + station_name;
        check_out_map[route].first += t - check_in.second;
        check_out_map[route].second += 1;
    }

    double GetAverageTime(string start_station, string end_station)
    {
        string route = start_station + "_" + end_station;
        auto &check_out = check_out_map[route];
        return (double)check_out.first / check_out.second;
    }

private:
    unordered_map<string, pair<int, int>> check_out_map;
    unordered_map<int, pair<string, int>> check_in_map;
};