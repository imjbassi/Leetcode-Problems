class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }
    
private:
    bool isMatchHelper(const string& s, const string& p, int sIndex, int pIndex) {
        // Base case: both s and p are empty
        if (sIndex == s.length() && pIndex == p.length()) {
            return true;
        }
        
        // Case when p is empty but s is not
        if (pIndex == p.length()) {
            return false;
        }
        
        bool match = (sIndex < s.length() && (s[sIndex] == p[pIndex] || p[pIndex] == '.'));

        // Check for '*' case and move pIndex accordingly
        if (pIndex + 1 < p.length() && p[pIndex + 1] == '*') {
            return (isMatchHelper(s, p, sIndex, pIndex + 2) || (match && isMatchHelper(s, p, sIndex + 1, pIndex)));
        }
        
        // Move both sIndex and pIndex for normal matching
        return match && isMatchHelper(s, p, sIndex + 1, pIndex + 1);
    }
};