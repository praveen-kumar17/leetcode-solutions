class BusBooking {
    int n;
    vector<vector<int>> rows;
    vector<vector<int>> cost;
    int total_time=0;
    int min_time=0;
public:
    BusBooking(int n) {
        this->n=n;
        rows=vector<vector<int>>(n+1,vector<int>(4,0));
        cost=vector<vector<int>>(n+1,vector<int>(4,0));
    }
    
    void toggle(string seat) {
        char type= seat[0];
        int no=stoi(seat.substr(1));
        int col=type-'A';
        if(rows[no][col]==0){
            int time=1;
            if(type=='A' && rows[no][1]!=0){
                time=3;
            }
            if(type=='D' && rows[no][2]!=0){
                time=3;
            }
            rows[no][col]=1;
            cost[no][col]=time;
            total_time+=time;
            min_time++;
        }else{
            total_time-=cost[no][col];
            rows[no][col]=0;
            cost[no][col]=0;
            min_time--;
        }
    }
    
    int getTotalTime() {
        return total_time;
        
    }
    
    int getMinTime() {
        return min_time;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */