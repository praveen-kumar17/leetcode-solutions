class Solution {
public:
        int minLength(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        int i = 0, n = A.size(), res = n + 1;
        for (int j = 0; j < A.size(); ++j) {
            int a = A[j];
            if (++cnt[a] == 1)
                k -= a;
            while (k <= 0) {
                res = min(res, j - i + 1);
                if (--cnt[A[i]] == 0)
                    k += A[i];
                i++;
            }
        }
        return res > n ? -1 : res;
    }
};