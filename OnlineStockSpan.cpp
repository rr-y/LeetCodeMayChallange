// Beautiful Problem
// Stack Demonstration
// Problem Lin-> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/

class StockSpanner {
    stack<pair<int, int> > prices;
public:
    StockSpanner() {
        while(!prices.empty())
            prices.pop();
        
    }
    
    int next(int price) {
        int w = 1;
        while(!prices.empty() && prices.top().first <= price){
            w += prices.top().second;
            prices.pop();
        }
        
        prices.push({price, w});
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
