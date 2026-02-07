class MedianFinder {
    multiset<int,greater<int>>left;
    multiset<int>right;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.insert(num) ;
          
        if(right.size() && (*left.begin() > *right.begin())){
            int curL = *left.begin();
            int curR = *right.begin();
            left.erase(left.begin());
            right.erase(right.begin());
            left.insert(curR);
            right.insert(curL);
        }

        if(left.size() -right.size() > 1){
            right.insert(*left.begin());
            left.erase(left.begin());
        } 
    }
    
    double findMedian() {
        int n = left.size() + right.size();
        if(n==0) return -1;
        if(n%2) return *left.begin();
        return (0LL + *left.begin() + *right.begin())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */