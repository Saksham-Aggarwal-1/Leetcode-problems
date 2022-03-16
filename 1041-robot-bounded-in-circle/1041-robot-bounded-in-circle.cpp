class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        vector<int>dir={0,1};
        for(char c: instructions)
        {
            if(c == 'G')
            {
                cout<<"case1\n";
                x+=dir[0];
                y+=dir[1];
                cout<<"at "<<x<<" "<<y<<"\n";
            }
            else if(c == 'L')
            {
                if(dir[0] == 0 && dir[1] == 1)
                {
                    cout<<"case2.1\n";
                    dir[0]=-1;
                    dir[1]=0;
                }
                else if(dir[0] == -1 && dir[1] == 0)
                {
                    cout<<"case2.2\n";
                
                    dir[0]=0;
                    dir[1]=-1;
                }
                else if(dir[0] == 0 && dir[1] == -1)
                {
                    cout<<"case2.3\n";
                
                    dir[0]=1;
                    dir[1]=0;
                }
                else if(dir[0] == 1 && dir[1] == 0)
                {
                    cout<<"case2.4\n";
                
                    dir[0]=0;
                    dir[1]=1;
                }
            }
            else
            {
                if(dir[0] == 0 && dir[1] == 1)
                {
                    cout<<"case3.1\n";
                
                    dir[0]=1;
                    dir[1]=0;
                }
                else if(dir[0] == 1 && dir[1] == 0)
                {
                    cout<<"case3.2\n";
                
                    dir[0]=0;
                    dir[1]=-1;
                }
                else if(dir[0] == 0 && dir[1] == -1)
                {
                    cout<<"case3.3\n";
                
                    dir[0]=-1;
                    dir[1]=0;
                }
                else if(dir[0] == -1 && dir[1] == 0)
                {
                    cout<<"case3.4\n";
                
                    dir[0]=0;
                    dir[1]=1;
                }
            }
        }
        
        cout<<"complete\n";
        if(x == 0 && y == 0)
            return true;
        if(dir[0] == 0 && dir[1] == 1)
            return false;
        return true;
    }
};