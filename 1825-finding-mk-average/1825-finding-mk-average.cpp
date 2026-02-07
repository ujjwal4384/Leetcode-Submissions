class MKAverage {
private:
multiset<int, greater<int>>mini;
multiset<int>reserve;
multiset<int>maxi;
map<int,int>stream;
long long curCost = 0;
int m,k;
int x; //num. of elements in reserve = m- 2*k whose average is need to be calculated.
int index;
public:
    MKAverage(int m, int k) {
          this->m = m;
          this->k =k;
          this->x = (m- 2*k) ;
          this->index =0;
    }
    
    void addElement(int num) {
        //always add to mini greedily.
        stream[index] = num; 
        mini.insert(num);

        //balance mini with reservre
        if(mini.size() > k){
            reserve.insert(*mini.begin());
            curCost += *mini.begin();
            mini.erase(mini.begin());
        }

        //balance reserve with maxi
        if(reserve.size() > x){
            auto it= prev(reserve.end());
            maxi.insert(*it);
            curCost -= *it;
            reserve.erase(it);
        }
        
        //means need to remove el (sliding window) based on condition (maxi sz= k+1 at the moment)
        if(index>=m){
            int toRem = stream[index - m];
            if(mini.find(toRem) != mini.end()){
                mini.erase(mini.find(toRem));
                mini.insert(*reserve.begin());
                curCost -= *reserve.begin();
                reserve.erase(reserve.begin());

                reserve.insert(*maxi.begin());
                curCost += *maxi.begin();
                maxi.erase(maxi.begin());
            } else if(reserve.find(toRem) != reserve.end()){
                curCost -= toRem;
                reserve.erase(reserve.find(toRem));
                reserve.insert(*maxi.begin());
                curCost += *maxi.begin();
                maxi.erase(maxi.begin());
            }else{
                maxi.erase(maxi.find(toRem));
            }
        } 
        index++;

    } 
    
                
    int calculateMKAverage() {
        return index >= m ? curCost/x : -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */