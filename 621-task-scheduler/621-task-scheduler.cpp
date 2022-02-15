class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> arr(26,0);
        for(char c: tasks)
            arr[c-'A']++;
        
        sort(arr.begin(), arr.end());
        
        int max_val = arr[25]-1;
        
        int emptySlots = n * (max_val);
        
        for(int i = 24; i>-1; i--)
        {
            emptySlots -= min(arr[i], max_val);
        }
        
        if(emptySlots>0)
            return tasks.size() + emptySlots;
        else
            return tasks.size();
    }
};