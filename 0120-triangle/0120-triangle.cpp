class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int>prev,cur;
        prev = {triangle[0][0]};
        for(int row=1; row<n; row++){
            for(int col = 0; col<=row; col++){
                  int a = col<prev.size() ? prev[col] : INT_MAX;
                  int b = col-1 >=0 ? prev[col-1] : INT_MAX;
                  cur.push_back(triangle[row][col] +  min(a, b));
            }
            prev= cur;
            cur.clear();
        }
      return *min_element(prev.begin(), prev.end());  
    }
};