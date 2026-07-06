class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mem;
        for(string c : tokens){
            if(c == "+"){
                int a = mem.top(); mem.pop();
                int b = mem.top(); mem.pop();
                mem.push(a + b);
            }
            else if(c == "-"){
                int a = mem.top(); mem.pop();
                int b = mem.top(); mem.pop();
                mem.push(b - a);
            }
            else if(c == "*"){
                int a = mem.top(); mem.pop();
                int b = mem.top(); mem.pop();
                mem.push(a * b);
            }
            else if( c == "/"){
                int a = mem.top(); mem.pop();
                int b = mem.top(); mem.pop();
                mem.push(b / a);
            }
            else{
                mem.push(stoi(c));
            }
        }
        return mem.top();
    }
};
