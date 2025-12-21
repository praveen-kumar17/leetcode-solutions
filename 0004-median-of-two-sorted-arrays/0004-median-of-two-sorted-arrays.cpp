class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int i=0,j=0;
        int el1=-1,el2=-1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) el1=nums1[i];
                if(cnt==ind2) el2=nums1[i];
                i++;
            }
            else{
                if(cnt==ind1)el1=nums2[j];
                if(cnt==ind2)el2=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<n1){
            if(cnt==ind1) el1=nums1[i];
            if(cnt==ind2) el2=nums1[i];
            i++;
            cnt++;
        }
        while(j<n2){
            if(cnt==ind1) el1=nums2[j];
            if(cnt==ind2) el2=nums2[j];
            j++;
            cnt++;
        }
        if(n%2==1) return (double)el2;
        return (el1+el2)/2.0;
    }
};