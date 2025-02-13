class MedianFinder {
    priority_queue<int, vector<int>>pq1;
    priority_queue<int, vector<int>, greater<int>>pq2;
public:
    MedianFinder() {
    
    }
    
    void addNum(int num) {

        pq1.push(num);
        int sz1 = pq1.size();
        int sz2 = pq2.size();

        if(sz1- sz2 > 1){
            int maxiFromPq1 = pq1.top();
            pq1.pop();
            pq2.push(maxiFromPq1);
        }
        // sz2-sz1 <=1 but pq1 top has bigger el now than pq2 top.
        else if(sz2 >0 && pq1.top() > pq2.top()){
                pq2.push(pq1.top());    
                pq1.pop();
                pq1.push(pq2.top());
                pq2.pop();    
        }
    }
    
    double findMedian() {

        
        
        int sz1 = pq1.size();
        int sz2 = pq2.size();
        int n = sz1+sz2;
        
        if(n==0) return 0;
           
        
        if(n%2){
            //odd
            return pq1.top();
        }else{
            //even
            return (pq1.top() + pq2.top())/2.0 ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */