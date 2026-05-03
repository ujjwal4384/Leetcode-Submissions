class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       int totalTasks = tasks.size();
       int freq[26]={};
       for(int i=0; i<totalTasks; i++){
            freq[tasks[i] - 'A']++;
       }
       sort(freq, freq + 26);
       int max_freq = freq[25];
       int idle_slots = (max_freq - 1) * n; //last waale ke liye not required.  
       //start filling these idle slots 
       for(int i=24;i>=0;i--){
              idle_slots -= min(freq[i], max_freq-1); //min becasue what if same freq as max freq then last waala will just append at last of other max freq elements.

       }

       return idle_slots>0 ? idle_slots + totalTasks : totalTasks;
    }
};