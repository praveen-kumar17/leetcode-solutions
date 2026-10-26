class Solution {
public:
    bool isvalid(char c){
        char ch=tolower(c);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        
    }
    string reverseVowels(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            while(i<j && !isvalid(s[i])){
                i++;
            }
            while(i<j && !isvalid(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i++],s[j--]);
            }
        }
        return s;
    }
};