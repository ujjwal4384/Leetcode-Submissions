bool comp(vector<int>&v1, vector<int>&v2){
    if(v1[1] == v2[1]){
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}
class Solution {

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        multiset<int, greater<int>>s;
        int time =0;
        for(auto course:courses){
            int duration = course[0];
            int deadline = course[1];
            
            if(time + duration <= deadline){
                   s.insert(duration); 
                   time += duration;
            }else{
                //can swapping be helpful?
                if (s.size() && (* s.begin()) > duration){
                    time = time - (* s.begin()) + duration;
                    s.erase(s.begin());
                    s.insert(duration);
                }
            }
        }
        return s.size();
    }
};