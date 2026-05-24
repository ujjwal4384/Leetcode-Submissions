class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cur = 0;
        for(int i=0;i<k;i++)cur += cardPoints[i];
        int i=k-1, j = n-1;
        int max_points = cur;
        while(i>=0){
            cur = cur - cardPoints[i] + cardPoints[j];
            max_points = max(max_points, cur);
            i--, j--;
        }
        return max_points;
    }
};