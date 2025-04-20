class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string c(max(a.size(),b.size()), '0');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size()>b.size()){
            string push1(a.size()-b.size(),'0');
             b.append(push1);
        }else{
             string push2(b.size()-a.size(),'0');
             a.append(push2);
        }
        
        for (int i = 0; i < a.size(); i++) {

            if (a[i] == b[i] && b[i] == '1') {
                c[i] = '0' + carry;
                carry = 1;
            } else if (a[i] == b[i] && b[i] == '0') {
                c[i] = '0' + carry;
                carry = 0;
            } else if (carry == 1) {
                c[i] = '0';
                carry = 1;
            } else {
                c[i] = '1';
                carry = 0;
            }
        }
        if (carry == 1) {
            c.push_back('1');
        }
        reverse(c.begin(), c.end());
        return c;
    }
};