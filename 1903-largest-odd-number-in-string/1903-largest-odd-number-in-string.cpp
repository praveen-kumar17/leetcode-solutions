class Solution {
public:
    string largestOddNumber(string num) {
        while(num.length()>0){
            if((num[num.length()-1]-0)%2!=0) return num;
            num.pop_back();
        }
        return "";
    }
};