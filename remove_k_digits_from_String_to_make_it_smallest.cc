class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        while(k)
        {
            int cur=0,next=0;
            
            if(num[i] != 0)    
                cur = num[i] - '0';
                
            if(i < (num.size()-1))
                next = num[i+1] - '0';
            
            if((cur > next) || (k == (num.size()-i)))
            {
                num.erase(i,1);
                i = max(-1,i-2);
                k--;
            }
            i++;
        }
        
        std::size_t found = num.find_first_not_of("0");
        num.erase(0,found);
        
        if(num.size() == 0)
            num.push_back('0');
            
        return num;
    }
};