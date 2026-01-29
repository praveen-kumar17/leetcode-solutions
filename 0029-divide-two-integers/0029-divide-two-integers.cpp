class Solution {
public:
    int divide(int divident, int divisor) {
        if(divident==divisor){
            return 1;
        }
        bool sign=true;
        if(divident>=0 && divisor<0) sign=false;
        if(divident<0 && divisor>=0) sign=false;
        long n=labs((long)divident);
        long d=labs((long)divisor);
        divisor=abs((long)divisor);
        long quotient=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            quotient+=1<<cnt;
            n-=(d<<cnt);
        }
        if(quotient==(1<<31) && sign){
            return INT_MAX;
        }
        if(quotient==(1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? quotient:-quotient;
    }
};