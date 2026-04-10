class Solution {
public:
        vector<int> findPSE(vector<int> & arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            int el=arr[i];
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top():-1;
            st.push(i);
        }
        return ans;
    }
        vector<int>findNSE(vector<int> & arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int el=arr[i];
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top():n;
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE=findNSE(arr);
        vector<int> PSE=findPSE(arr);
        int n=arr.size();
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            long long freq=(left*right*1LL);
            long long res=(freq*arr[i]*1LL);
            sum=sum+res;
        }
        return sum;
    }
    vector<int> findPGE(vector<int> & arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            int el=arr[i];
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top():-1;
            st.push(i);
        }
        return ans;
    }

    vector<int> findNGE(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int el=arr[i];
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top():n;
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr){
        vector<int> NGE=findNGE(arr);
        vector<int> PGE=findPGE(arr);
        int n=arr.size();
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-PGE[i];
            int right=NGE[i]-i;
            long long freq=(left*right*1LL);
            long long res=(freq*arr[i]*1LL);
            sum=sum+res;
        }
        return sum;
    }


    long long subArrayRanges(vector<int>& arr) {
        int mod=1e9+7;
        return sumSubarrayMaxs(arr)-sumSubarrayMins(arr);
    }
};