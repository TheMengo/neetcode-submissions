class Solution {
public:
    bool isValid(string s) {
        deque<char> s_queue;
        for(char c : s){
            if(c == ')'){
                if(!s_queue.empty() && s_queue.back() == '('){
                    s_queue.pop_back();
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(!s_queue.empty() && s_queue.back() == '{'){
                    s_queue.pop_back();
                }
                else{
                    return false;
                }
            }

            else if(c == ']'){
                if(!s_queue.empty() && s_queue.back() == '['){
                    s_queue.pop_back();
                }
                else{
                    return false;
                }
            }
            
            else{
                s_queue.push_back(c);
            }
        }
        if(s_queue.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    
};
