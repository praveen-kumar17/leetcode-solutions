class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left_sum = 0;
        for (int i = 0; i < k; i++) {
            left_sum += cardPoints[i];
        }

        int max_sum = left_sum;
        int right_sum = 0;

        for (int i = 0; i < k; i++) {
            left_sum -= cardPoints[k - 1 - i];
            right_sum += cardPoints[n - 1 - i];
            max_sum = max(max_sum, left_sum + right_sum);
        }

        return max_sum;
    }
};