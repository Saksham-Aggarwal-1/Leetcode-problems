class Solution {
public:
    int func(int a, vector<int> A, vector<int> B)
    {
        int ans = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i] == a)
                continue;
            else
            {
                if(B[i] == a)
                    ans++;
                else
                    return INT_MAX;
            }
        }
        
        return ans;
    }
    
//     int min(int a, int b, int c, int d)
//     {
//         return min(a, min(b, min(c, d)));
//     }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(func(tops[0], tops, bottoms), 
                      min(func(bottoms[0], tops, bottoms),
                          min(
                              func(tops[0], bottoms, tops), func(bottoms[0], bottoms, tops)
                          )
                         )
                     );
        return (ans == INT_MAX)? -1:ans;
    }
};