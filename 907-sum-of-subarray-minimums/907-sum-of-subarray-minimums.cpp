class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int base=1000000000+7;
        vector<int> leftmin(arr.size(),0),rightmin(arr.size(),0);
        leftmin[0]=-1; 
        rightmin[arr.size()-1]=arr.size();
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]>arr[i]){
                leftmin[i+1]=i;
            }
            else{
                int l=i;
                while( arr[i+1]<arr[l] && leftmin[l]!=-1){
                    l=leftmin[l];
                }
                if(arr[i+1]>=arr[l]){
                    leftmin[i+1]=l;
                }
                else{
                    leftmin[i+1]=-1;
                }
            }
        }
        for(int i=(arr.size()-1);i>0;i--){
            if(arr[i-1]>arr[i]){
                rightmin[i-1]=i;
            }
            else{
                int l=i;
                while(arr[i-1]<=arr[l] && rightmin[l]!=arr.size()){ 
                    l=rightmin[l];
                }
                if(arr[i-1]>arr[l]){
                    rightmin[i-1]=l;
                }
                else{
                    rightmin[i-1]=arr.size();
                }
            }
        }
        long long int res=0;
        for(int i=0;i<arr.size();i++){ 
            res=res%base+((long long)(i-leftmin[i])*(long long)(rightmin[i]-i)*(long long)arr[i]);
        }
        return res;
    }
};