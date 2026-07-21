class TimeMap {
public:
    // Key: person Value: map of key: timestamp value: emotion
    unordered_map<string, map<int, string>> time_table;
    
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        time_table[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Upper bound is a build in feature of std::map, it return the exact, or anything less than
        // Lower bound on the otherhand functions as the opposite
        auto it = time_table[key].upper_bound(timestamp);
        // If there are no smaller elements than the given timestamp, uppder bound will point to begin
        return it == time_table[key].begin() ? "" : prev(it)->second;
    }
};
