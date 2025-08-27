class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int booked =0;
        for(auto& p:mp){
                booked += p.second;    
                if(booked == 2){
                    mp[startTime]--;
                    mp[endTime]++;
                    return false;
                }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */