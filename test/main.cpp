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

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

int main()
{
    int array_int[] = {1,2,7,6,8,4,5,3,9,0};
    merge_sort(array_int, 0, 9);
    for(int i=0; i<10; i++) {
        cout << array_int[i] << endl;
    }
    return 0;
}
