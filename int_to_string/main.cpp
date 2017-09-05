#include <iostream>

using namespace std;

string IntToString(int num)
{
    int shang,yushu;
    string result;
    char nownum;
    result = "";
    shang = num;
    while(shang != 0) {
        yushu = shang % 10;
        shang = shang / 10;
        nownum = (char)(yushu + '0');
        result = nownum + result;
    }
    return result;
}

int main()
{
    cout << IntToString(328);
    return 0;
}
