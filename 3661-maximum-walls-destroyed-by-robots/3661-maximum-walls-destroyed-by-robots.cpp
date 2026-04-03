struct Robot{
    int p;
    int d;
    Robot(int pos, int dis){
        p=pos, d = dis;
    }
};
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
             int n = robots.size();
             int m = walls.size();
             vector<vector<int>>dp(n, vector<int>(2, 0));
             vector<Robot>v;

             for(int i=0;i<n;i++){
                 v.push_back(Robot(robots[i], distance[i]));
             }

            sort(v.begin(), v.end(), [](const Robot&a, const Robot&b){
                 if(a.p == b.p) return a.d < b.d;
                 return a.p < b.p;
             });
            
            sort(walls.begin(), walls.end());
            for(int i=0;i<n;i++){
                 Robot& robot = v[i];
                 int Ri = i+1 < n ? min(robot.p + robot.d, v[i+1].p - 1) : robot.p + robot.d;
                 int Li = i-1>=0 ? max(robot.p - robot.d, v[i-1].p + 1) : robot.p - robot.d;
                 int RPrev = i-1>=0 ? min(v[i-1].p + v[i-1].d, robot.p - 1) : robot.p - 1;

                 //bullet fires Right
                  int c1 = upper_bound(walls.begin(), walls.end() , Ri) - lower_bound(walls.begin(), walls.end() , robot.p);
                  dp[i][1] = i-1 >=0 ? max(dp[i-1][1], dp[i-1][0]) + c1 : c1;  

                 //bullet fires Left
                 int c2 = upper_bound(walls.begin(), walls.end() , robot.p) - lower_bound(walls.begin(), walls.end() , Li);

                 int c3 = upper_bound(walls.begin(), walls.end() , robot.p) - lower_bound(walls.begin(), walls.end() , max(Li, RPrev+1));

                 int countWhenPrevRobotMovedLeft = i-1>=0 ?dp[i-1][0] + c2 : c2;
                 int countWhenPrevRobotMovedRight = i-1>=0 ?dp[i-1][1] + c3 : c3;
                 dp[i][0] = max(countWhenPrevRobotMovedLeft, countWhenPrevRobotMovedRight);
            }

    return max(dp[n-1][0], dp[n-1][1]);
    }
};