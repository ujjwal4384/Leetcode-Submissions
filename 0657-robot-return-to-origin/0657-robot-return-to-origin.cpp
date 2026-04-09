class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y= 0;
        for(auto dir: moves){
             if(dir == 'U')y--;
             else if(dir == 'D')y++;
             else if(dir == 'L')x--;
             else x++;
        }
        return x ==0 && y==0;
    }
};