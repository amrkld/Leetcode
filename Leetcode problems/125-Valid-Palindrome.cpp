class Solution {
public:
    bool isPalindrome(string s) {
        // alphanumeric contains numbers
        string alphaS = \\;
          for (auto ch : s) {
            if (std::isalnum(ch)) {
                alphaS += std::tolower(ch);
            }
        }


        // two pointers , start & end
        int start = 0;
        int end = alphaS.size() - 1;

        while (start <= end) {
            if (alphaS[start] == alphaS[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};