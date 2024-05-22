
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; 
        vector<string> currentPartition;
        partitionHelper(s, 0, currentPartition, result);
        return result;
    }

private:
    // Helper function to find all palindromic partitions
    void partitionHelper(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring)) {
                currentPartition.push_back(substring);
                partitionHelper(s, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s) {
        string reversed(s.rbegin(), s.rend());
        return s == reversed;
    }
};