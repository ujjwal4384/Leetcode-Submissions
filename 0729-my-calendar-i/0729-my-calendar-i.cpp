class MyCalendar {
    set<pair<int,int>>s;
public:
    
    MyCalendar() {
        
    }
    
    bool book(int st, int en) {
        auto it = s.lower_bound({st, en});
        if(it != s.end() && en > it->first){
            return false;
        }
        auto before = it;
        if(it !=s.begin() && s.size()){
            before --;
            if(st < before->second){
                return false;
            }
        }
        s.insert({st, en});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */