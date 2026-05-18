#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        //2 PQ solution
        priority_queue<int, vector<int>, greater<int>>available_rooms;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>blockedMeetingRoom; //{freeTime, roomNumber}
        int sz = meetings.size();
        for(int i=0;i<n;i++){
            available_rooms.push(i);
        }

        vector<int>meetingCount(n, 0);
        
        for(auto& meet: meetings){
                 int st = meet[0], en = meet[1];
                   //first clear the desk, flush al blocked to available rooms if meetings are over
                   while(blockedMeetingRoom.size() && blockedMeetingRoom.top().first <=st){
                           available_rooms.push(blockedMeetingRoom.top().second);
                           blockedMeetingRoom.pop();
                   }
                   //case:1 room is available
                   if(available_rooms.size() > 0){
                        int roomNumber = available_rooms.top();
                        ll freeAt = st;
                        available_rooms.pop();
                        meetingCount[roomNumber]++;
                        blockedMeetingRoom.push({en, roomNumber});
                   }else{
                    //wait for one of the blocked room to get free
                    int roomNumber =  blockedMeetingRoom.top().second;
                        ll freeAt = blockedMeetingRoom.top().first;
                        blockedMeetingRoom.pop();
                        meetingCount[roomNumber]++;
                          blockedMeetingRoom.push({freeAt + (en-st), roomNumber});
                   }
                  
                 
        }
        int maxMeetingCount = meetingCount[0], roomNumber = 0;
        for(int i=1;i<n;i++){
            if(meetingCount[i] > maxMeetingCount){
                maxMeetingCount = meetingCount[i], roomNumber = i;
            }
        }
        return roomNumber;
    }
};