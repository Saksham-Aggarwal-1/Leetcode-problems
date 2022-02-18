class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        
        long A = (long) a;
        long B = (long) b;
        long C = (long) c;
        
        long ab = A*B/ __gcd(a,b);
        long bc = B*C/__gcd(b,c);
        long ca = C*A/__gcd(c,a);
        long abc = A*bc/__gcd(A, bc);
        
        int l = 1;
        int h = 2*(int)1e9;
        
        while(l<h)
        {
            int mid = l+(h-l)/2;
            int temp = mid/A + mid/B + mid/C - mid/ab -mid/bc - mid/ca + mid/abc;
            
            if(temp<n)
                l = mid+1;
            else
                h = mid;
        }
        
        return l;
    }
};