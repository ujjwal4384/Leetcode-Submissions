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
         };//GREEDY: comlpete the task with max buffer first (max delta in reqauiredEnergy to actually consumed)
         sort(tasks.begin(), tasks.end(), comp);
         
         int minInitialEnergyRequired = 0;
         int curEnergy = 0;
         for(auto&task: tasks){
             int actualConsumedForTask = task[0];
             int minReqForTask = task[1];
             if(curEnergy < minReqForTask){
                minInitialEnergyRequired += (minReqForTask - curEnergy);
                curEnergy = minReqForTask;
             }
             curEnergy -=  actualConsumedForTask;
         }

        
        return minInitialEnergyRequired; 
    }
};