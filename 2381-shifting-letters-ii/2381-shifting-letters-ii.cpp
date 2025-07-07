class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length() + 1;
        vector<int> line(n, 0);
        for (const auto& shift : shifts) {
            if (shift[2] == 1) {
                line[shift[0]]++;
                line[shift[1] + 1]--;
            } else {
                line[shift[0]]--;
                line[shift[1] + 1]++;
            }
        }
        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            curr += line[i];
            curr %= 26; // keep in [-25..25]
            if (curr < 0)
                curr += 26; // now in [0..25]

            int base = s[i] - 'a';
            int shifted = (base + curr) % 26;
            s[i] = char('a' + shifted);
        }
        return s;
    }
};