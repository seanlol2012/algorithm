#include <iostream>

using namespace std;

int StringToNum(string& str)
{
    int num;
    int i,weinum;
    i = 0;
    while(str[i]!='\0') {
        i++;
    }
    weinum = i;
    int sum,nownum;
    sum = 0;
    for(i=0; i<weinum; i++) {
        nownum = (int)(str[i]-'0');
        sum = sum*10 + nownum;
    }
    num = sum;
    return num;
}

int main() {
    string str;
    str = "80";
    int num;
    num = StringToNum(str);
    cout << num;
    return 0;
}
