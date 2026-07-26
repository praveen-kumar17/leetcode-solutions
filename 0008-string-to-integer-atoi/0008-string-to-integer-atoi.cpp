class Solution {
public:
    long long generate(string s,int i,int sign,long long ans){
        int n=s.length();
        if(i>=n || !isdigit(s[i])){
            return ans*sign;
        }
        int digit=s[i]-'0';
        if(ans > (INT_MAX-digit)/10){
            return sign==1 ? INT_MAX:INT_MIN;
        }
        return generate(s,i+1,sign,(ans*10)+digit);
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
        }else if(s[i]=='+'){
            sign=1;
            i++;
        }
        long long ans=generate(s,i,sign,0);
        return (int)ans;
    }
};