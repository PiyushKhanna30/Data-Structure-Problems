class Solution {
public:
    string defangIPaddr(string address) {
        string new_add="";
        for(int i=0;address[i]!='\0';i++)
        {
            if(address[i]=='.')
            {
                new_add+="[.]";
                continue;
            }
            new_add+=address[i];
        }
        return new_add;
    }
};