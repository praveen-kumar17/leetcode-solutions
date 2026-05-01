class Solution {
public:
        int firstUniqueFreq(vector<int>& A) {
        unordered_map<int, int> c1, c2;
        for (int x : A)
            c1[x]++;
        for (auto const& p : c1)
            c2[p.second]++;
        for (int x : A) {
            if (c2[c1[x]] == 1)
                return x;
        }
        return -1;
    }
};