#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>

using namespace std;

struct testNode
{
    int value_a = 1;
    int value_b = 2;
    int value_c = 3;
};

int compare( const void* a, const void* b)
{
    testNode* aa = (testNode*)a;
    testNode* bb = (testNode*)b;
    if(aa->value_a != bb->value_a) {
        return aa->value_a > bb->value_a ? 1:-1;
    }else if(aa->value_b != bb->value_b) {
        return aa->value_b > bb->value_b ? 1:-1;
    }else{
        return aa->value_c > bb->value_c ? 1:-1;
    }
}

int main()
{
    testNode array_int[3];
    array_int[1].value_a = 1;
    array_int[1].value_b = 3;
    array_int[1].value_c = 2;
    array_int[2].value_a = 3;
    array_int[2].value_b = 2;
    array_int[2].value_c = 2;
    qsort(array_int, 3, sizeof(array_int[0]), compare);
    for(int i=0; i<3; i++) {
        cout << array_int[i].value_a << " " << array_int[i].value_b << " " << array_int[i].value_c << endl;
    }
    return 0;
}
