class MedianFinder {
priority_queue<int>pqL; 
priority_queue<int, vector<int>, greater<int>>pqR;
int n;
public:
    MedianFinder() {
      n=0;  
      pqL.push(INT_MIN);
      pqR.push(INT_MAX);
    }
    
    void addNum(int num) {
        n++;
        pqL.push(num);
       if(pqL.top()>pqR.top()){
          int x = pqL.top();pqL.pop();
          pqR.push(x);
       }
       if(n==3){
       }
       if(pqL.size()>(pqR.size()+1)){
        
          int x = pqL.top();pqL.pop();
          pqR.push(x);
       }
       if(pqR.size()>pqL.size()){
        
        int x = pqR.top();pqR.pop();
        cout<<"hiii"<<n<<"\t"<<x<<endl;
        pqL.push(x);
       }
    }
    
    double findMedian() {
        if(n==0) return 0;
        if(n%2){
         //    cout<<n<<'\t'<<pqL.top()<<pqR.top()<<endl;
            return pqL.top();
        }
        int x = pqL.top(),y=pqR.top();
        double a = (x+y)/2.0;
        //cout<<n<<'\t'<<a<<endl;
        
        return (x+y)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 /*
 [min,1],   [2,3, max]
 
 */