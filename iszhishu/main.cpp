#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int num;
    while(cin >> num) {
        if(num == 1) {
            cout << "1������" << endl;
        }
        if(num == 2) {
            cout << "2������" << endl;
        }
        int mid = static_cast<int>(sqrt(num));
        int j;
        for(j = 3; j <= mid; j +=2)
            if(num%j == 0)
                break;
    }
}
