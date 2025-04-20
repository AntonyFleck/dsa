class Solution {
public:
    vector<int> get_candidates(int n, vector<int> state) {
        vector<int> candidates;
        for (int i = 0; i < n; i++)
            candidates.push_back(i);
        if (state.size() == 0)
            return candidates;

        for (int i = 0; i < state.size(); i++) {
            auto it = find(candidates.begin(), candidates.end(), state[i]);
            if (it != candidates.end())
                candidates.erase(it);
            it = find(candidates.begin(), candidates.end(),
                      state[i] + (state.size() - i));
            if (it != candidates.end())
                candidates.erase(it);
            it = find(candidates.begin(), candidates.end(),
                      state[i] - (state.size() - i));
            if (it != candidates.end())
                candidates.erase(it);
        }
        return candidates;
    }

    void search(int n, vector<int> state, int& solution) {
        if (state.size() == n) {
            solution++;
            return;
        }
        vector<int> options = get_candidates(n, state);
        for (int i = 0; i < options.size(); i++) {
            state.push_back(options[i]);
            search(n, state, solution);
            state.pop_back();
        }
    }

    int totalNQueens(int n) {
        vector<int> state;
        int solution = 0;
        search(n, state, solution);
        return solution;
    }
};