class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> cur;
        backtrack(s, wordSet, 0, cur, res);
        return res;
    }

private:
    void backtrack(const string& s, const unordered_set<string>& wordSet, int start, vector<string>& cur, vector<string>& res) {
        if (start == s.size()) {
            string sentence;
            for (int i = 0; i < cur.size(); ++i) {
                if (i > 0) sentence += \ \;
                sentence += cur[i];
            }
            res.push_back(sentence);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            string word = s.substr(start, end - start + 1);  // substr(start, len to take)
            if (wordSet.find(word) != wordSet.end()) {
                cur.push_back(word);
                backtrack(s, wordSet, end + 1, cur, res);
                cur.pop_back();
            }
        }
    }
};