class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int len = digits.size();
        int i=0;
        while(i < len){
            digits[i]+=1;
            if(digits[i]!=10)
                break;
            digits[i]=digits[i]%10;
            i++ ;
        }
        if(i==len)
            digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};