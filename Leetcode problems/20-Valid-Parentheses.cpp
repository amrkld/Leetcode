class Solution {
public:
    bool isValid(string s) {
        stack <char> mystack;
        unordered_map<char, char> par = {
            {'[', ']'},
            {'{', '}'},
            {'(', ')'}
        };
        for(char ch : s){
            if(ch == '[' || ch == '{' || ch == '('){
                mystack.push(ch);
            }
            else{  // closed par
                if(mystack.empty() || par[mystack.top()] != ch){
                    return false;
                }
                mystack.pop();
            }
        }
        return mystack.empty();
    }
};