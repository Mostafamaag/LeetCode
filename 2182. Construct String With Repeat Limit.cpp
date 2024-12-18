class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>, vector<pair<char,int>>> pq;
        vector<int> count(26,0);
        for(auto ch : s){
            count[ch - 'a']++;
        }
        for(int i = 0; i < count.size(); i++){
            if(count[i]) pq.push({'a' + i, count[i]});
        }
        string res = "";

        while(!pq.empty()){
            auto [ch, cnt] = pq.top();
            pq.pop();
            if(cnt <= repeatLimit){
                res.append(cnt, ch);
            }

            else{
                res.append(repeatLimit, ch);
                if(pq.empty()) break;

                auto [ch2, cnt2] = pq.top();
                pq.pop();
                res.push_back(ch2);
                pq.push({ch, cnt - repeatLimit});
                if(cnt2 - 1) pq.push({ch2, cnt2 - 1});
            }
        }
        return res;
    }
};
