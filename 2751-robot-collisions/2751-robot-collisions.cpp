struct Robot{
  int health;
  int position;
  int direction;
  int index;
  Robot(int h, int p, int d, int i){
    health = h, position = p, direction = d, index = i;
  }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
  
        int n= healths.size();
        vector<Robot>robots;
        for(int i=0;i<n;i++){
            int d = directions[i] == 'L' ? -1: 1;
            robots.push_back(Robot(healths[i], positions[i], d, i));
        }
        sort(robots.begin(), robots.end(), [](Robot& a, Robot& b){
            return a.position < b.position;
        });

        stack<Robot>st;
        for(int i=0; i<n;i++){
            Robot robot = robots[i];
            if(robot.direction==1){
                st.push(robot);
                continue;
            }
            int h = robot.health;
            while(!st.empty() && st.top().direction == 1 && st.top().health < h){
                 st.pop();
                 h--;
            }
            if(st.empty() || st.top().direction == -1){
                if(h>0){
                    robot.health = h;
                    st.push(robot);
                }
                continue;
            }
            else if(!st.empty()){
                if(st.top().health == h)
                     st.pop();
                else if(st.top().health > h)
                     st.top().health--;
                   
                continue;
            }
        }

        vector<Robot>survivors;
        while(!st.empty()){
            survivors.push_back(st.top());
            st.pop();
        }
        sort(survivors.begin(), survivors.end(), [](Robot& a, Robot& b){
            return a.index < b.index;
        });

        vector<int>ans;
        for(auto&r:survivors)ans.push_back(r.health);

     return ans;
    }
};