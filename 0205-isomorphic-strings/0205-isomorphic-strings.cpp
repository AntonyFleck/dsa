class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        vector<bool> visited(256, false);  // to track used characters in t

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) == 0) {
                if (!visited[t[i]]) {
                    map[s[i]] = t[i];
                    visited[t[i]] = true;
                } else {
                    return false;
                }
            } else {
                if (map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
