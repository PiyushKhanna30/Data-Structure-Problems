class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        char carry='0';
        int as=a.size()-1;
        int bs=b.size()-1;
        while(as>=0 || bs>=0)
        {
            char ta='0',tb='0';
            if(as>=0)
            {
                ta=a[as];
                as--;
            }
            if(bs>=0)
            {
                tb=b[bs];
                bs--;
            }
            // cout<<"ta "<<ta<<"tb "<<tb<<endl;
            if(tb=='1' && ta=='1')
            {
                if(carry=='1')
                {
                    ans='1'+ans;
                    carry='1';
                }
                else
                {
                    ans='0'+ans;
                    carry='1';
                }
            }
            if(tb=='0' && ta=='0')
            {
                if(carry=='1')
                {
                    ans='1'+ans;
                    carry='0';
                }
                else
                {
                    ans='0'+ans;
                    carry='0';
                }
            }
            if((tb=='0' && ta=='1')||(tb=='1' && ta=='0'))
            {
                if(carry=='1')
                {
                    ans='0'+ans;
                    carry='1';
                }
                else
                {
                    ans='1'+ans;
                    carry='0';
                }
            }
        }
        if(carry=='1')
            ans='1'+ans;
        return ans;
    }
};