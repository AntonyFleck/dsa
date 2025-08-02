class Solution {
public:
    string decodeString(string s) {
        vector<int> counts;
        vector<string> frags;
        string curr;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push_back(num);
                frags.push_back(curr);
                num = 0;
                curr.clear();
            } else if (c == ']') {
                int k = counts.back(); counts.pop_back();
                string temp;
                temp.reserve(curr.size() * k);
                while (k--) temp += curr;
                curr = frags.back() + temp;
                frags.pop_back();
            } else {
                curr.push_back(c);
            }
        }
        return curr;
    }
};