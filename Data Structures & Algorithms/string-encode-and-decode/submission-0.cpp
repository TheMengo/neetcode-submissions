class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string word: strs){
            res.append(to_string(word.length()));
            res.append("#");
            res.append(word);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            string str_length;
            while(s[i] != '#'){
                str_length += s[i];
                i++;
            }
            int int_length = stoi(str_length);
            i++;
            res.push_back(s.substr(i, int_length));
            i += int_length;
        }
        return res;
    }
};
