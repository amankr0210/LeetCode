class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> groups;
    int maxFreq = 0;
    
    public:
    FreqStack(){}

        void push(int val){
            int f = ++freq[val];

            groups[f].push_back(val);
            maxFreq = max(maxFreq, f);

        }

        int pop(){
            int val = groups[maxFreq].back();
            groups[maxFreq].pop_back();

            if (--freq[val] == 0)
            freq.erase(val);

            if (groups[maxFreq].empty())
            -- maxFreq;

            return val;

        }
    };