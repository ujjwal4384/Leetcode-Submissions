class ExamRoom {
    private:
     set<int>occupied;
     int n;
public:
    ExamRoom(int n) {
        this->n = n;
        occupied.insert(0);
        occupied.insert(n+1);
    }
    
    int seat() {
         if(occupied.size() ==2 ){
            occupied.insert(1);
            return 0;
         }
         auto it = occupied.begin();
         

         int maxD = 0;
         int i = -1;
        
         
         while(it != occupied.end()){
            int a = *it;
            auto nxt = ++it;
            if(nxt == occupied.end()) break;
            
            int b = *(nxt);

            int closestDistance=-1, guy=-1;
            if(a==0){
                guy = 1;
                closestDistance = b-1;
            }else if(b==n+1){
                guy = n;
                closestDistance = n-a;
            }else{
                 closestDistance = (b-a)/2;
                 guy = (a+b)/2;
            }
            
            if(closestDistance > maxD){
                maxD = closestDistance;
                i = guy;
            }   
          
           
         }

         occupied.insert(i);   
       return i-1;
    }
    
    void leave(int p) {
        p++;
        occupied.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */