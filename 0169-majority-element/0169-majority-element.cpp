class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int n=nums.size();
        int cnt=0;
        int i=0;
        while(i<n){
            if(cnt==0){
                el=nums[i];
                cnt++;
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
            i++;
        }
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el){
                cnt2++;
            }
        }
        if(cnt2>n/2){
            return el;
        }
        return -1;

    }
};