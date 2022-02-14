class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || asteroids[i]>0)
                s.push(asteroids[i]);
            else
            {
                while(true)
                {
                    int x = s.top();
                    if(x<0)
                    {
                        s.push(asteroids[i]);
                        break;
                    }
                    else if(x == -asteroids[i])
                    {
                        s.pop();
                        break;
                    }
                    else if(x>-asteroids[i])
                    {
                        break;
                    }
                    else
                    {
                        s.pop();
                        if(s.empty())
                        {
                            s.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }
        
        vector<int> ans(s.size());
        for(int i=s.size()-1; i>-1; i--){
            ans[i]=s.top();
            s.pop();
        }
        
        return ans;
    }
};