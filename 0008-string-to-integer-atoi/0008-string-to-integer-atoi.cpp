class Solution {
public:
    long long recursivecalls(string &s,int i,long long ans,int sign){
        if(i>=s.length() || !isdigit(s[i])){
            return ans*sign;
        }
        int digit=s[i]-'0';
        if(ans > (INT_MAX-digit)/10){
            return sign==1 ? INT_MAX:INT_MIN;
        }
        return recursivecalls(s,i+1,ans*10+digit,sign);
    }
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        int sign=1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        } else if(s[i]=='+'){
            sign=1;
            i++;
        }
        long long res=recursivecalls(s,i,0,sign);
        return (int)(res);
    }
};