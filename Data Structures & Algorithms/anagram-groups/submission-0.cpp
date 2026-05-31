class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key sorted word, Value: the anagram
        unordered_map<string,vector<string>> res;
        for(auto& word: strs){
            string sorted_word = word;
            // Sort word
            sort(sorted_word.begin(), sorted_word.end());
            res[sorted_word].push_back(word);
        }
        vector<vector<string>> result;
        // For every key, return the vector of results
        for(auto& pair: res){
            result.push_back(pair.second);
        }
        return result;

    }
};
