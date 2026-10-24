class Solution {
public:
    vector<int> days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int convert(string s){
        int month=stoi(s.substr(0,2));
        int day=stoi(s.substr(3));
        for(int i=0;i<month-1;i++){
            day+=days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alicearrive=convert(arriveAlice);
        int aliceleave=convert(leaveAlice);
        int bobarrive=convert(arriveBob);
        int bobleave=convert(leaveBob);
        int start=max(alicearrive,bobarrive);
        int end=min(aliceleave,bobleave);
        return max(0,end-start+1);
    }
};