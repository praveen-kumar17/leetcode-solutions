class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=0;
        int el2=0;
        int cnt1=0;
        int cnt2=0;
        for(int x: nums){
            if(cnt1==0 && x!=el2){
                cnt1=1;
                el1=x;
            }
            else if(cnt2==0 && x!=el1){
                cnt2=1;
                el2=x;
            }
            else if(x==el1){
                cnt1++;
            }
            else if(x==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int el1cnt=0,el2cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                el1cnt++;
            }
            if(nums[i]==el2){
                el2cnt++;
            }
        }
        vector<int> ans;
        if(el1cnt>n/3){
            ans.push_back(el1);
        }
        if(el2cnt>n/3 && el1!=el2){
            ans.push_back(el2);
        }
        return ans;

    }
};