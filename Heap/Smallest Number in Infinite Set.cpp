class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int present[1001]={0};
    SmallestInfiniteSet() {
        for(int num=1;num<=1000;num++)
        {
            pq.push(num);
        }
    }
    
    int popSmallest() {
        int x=pq.top();
        pq.pop();
        present[x]=1;
        return x;  
    }
    
    void addBack(int num) {
        if(present[num]==1)
        {
            pq.push(num);
            present[num]=0;
        } 
    }
};