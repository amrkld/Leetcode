class Solution {
public:
    double helper(int val1, int val2, char ch) {
        if (ch == '+') {
            return val2 + val1; 
        } else if (ch == '-') {
            return val2 - val1;
        } else if (ch == '*') {
            return val2 * val1;
        } else if (ch == '/') {
            return val2 / (double)val1; 
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == \+\ || tokens[i] == \-\ || tokens[i] == \*\ || tokens[i] == \/\) {
                char ch = tokens[i][0];
                int val1 = mystack.top();
                mystack.pop();
                int val2 = mystack.top();
                mystack.pop();
                double result = helper(val1, val2, ch); 
                mystack.push((int)result);
            } else {
                mystack.push(stoi(tokens[i])); // Convert string to integer and push onto stack
            }
        }
        return mystack.top();
    }
};