class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2)
    {
        if(v1[1]<v2[1] || (v1[1]==v2[1] && v1[2]<v2[2]))
            return true;
        return false;
    }
        
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int n = trips.size() ;
		
        sort(trips.begin(),trips.end(),cmp) ;
        
        int curr = 0 ;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // destination , numpassengers
        
        for(int i=0;i<n;i++)
        {
			while(!pq.empty() && pq.top().first<=trips[i][1])
            {
                curr-=pq.top().second ;
                pq.pop() ;
            }
            
			pq.push({trips[i][2],trips[i][0]}) ;
            curr+=trips[i][0] ;
			
			if(curr>capacity)
                return false ;
        }
		
        return true ;  
    }
};