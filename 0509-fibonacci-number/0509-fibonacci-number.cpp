class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
       int prev=0;
       int curr=1;
       int ans=0;
       for(int i=1;i<n;i++){
          ans=prev+curr;
          prev=curr;
          curr=ans;
       }
       return curr;
    }
};