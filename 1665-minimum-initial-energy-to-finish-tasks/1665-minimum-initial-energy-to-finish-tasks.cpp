class Solution {
private:
 bool isValid(vector<vector<int>>& tasks, int& n, int& threshold){
        int energyLeft = threshold;
       
        for(auto& task: tasks){
          
           if(energyLeft < task[1]) return false;
            energyLeft -= task[0];
        }
        return energyLeft >= 0;
 }

public:
    int minimumEffort(vector<vector<int>>& tasks) {
         int n = tasks.size();
         auto comp = [](const vector<int>& task1,const vector<int>& task2){
            return task1[1] -task1[0] > task2[1] - task2[0];
         };
         sort(tasks.begin(), tasks.end(), comp);
         
         int totalMininumEnergyRequired = 0;
         int totalActualEnergy = 0;
         for(auto&task: tasks){
             totalMininumEnergyRequired +=  task[1];
             totalActualEnergy += task[0];
         }

         int l = totalActualEnergy, r = totalMininumEnergyRequired ;

         int ans = r;
         while(l<=r){
             int mid = l+ ((r-l)>>1);
             bool valid = isValid(tasks,n, mid);
             if(valid){
                ans = mid;
                r = mid -1 ;
             }else{
                l = mid+1;
             }
         }
        return ans; 
    }
};