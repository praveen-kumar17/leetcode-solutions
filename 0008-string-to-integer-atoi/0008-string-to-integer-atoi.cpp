class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long ans=0;
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
        while(i<n && isdigit(s[i])){
            int digit =s[i]-'0';
            ans=ans*10+digit;
           if(ans*sign<INT_MIN) return INT_MIN;
           if(ans*sign>INT_MAX) return INT_MAX;
           i++;
        }
        return (int)(sign*ans);
    }
};