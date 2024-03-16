
//abhi lho yha pe timing-> june tak easily nikal jaayga.
// 3 months to nail it.-> DSA chod do. System Design chod do, give as many interviews as possible.
//daily morning 7-9 AM : jobHunt linkedin, mail, resume ready rhe, modify accordingly . 
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //refill=> total no. of refueling stations
        //distance=> distance coverable so far with current availableFuel. you cannot go ahead from distance untill you refill.
        //iterate till distance is < target. and see all stations which are reachable till distance. then refill with max fueling station. if there are no such stations means you cannot go ahead.  return -1.
        int refill=0,i=0, n=stations.size();
        int distance = startFuel;
        priority_queue<int, vector<int>>pq;
        
        while(distance<target){
            while(i<n && stations[i][0]<= distance){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())return -1;
            distance+= pq.top();
            refill++;
            pq.pop();
        }
       
        return refill;
    }
    
    
};