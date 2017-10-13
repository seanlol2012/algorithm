#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>

using namespace std;

struct node
{
    char data;
    node* Lchild;
    node* Rchild;
};

int createBiTree(node* &T)
{
    char input_data;
    T = (node*)malloc(sizeof(node));
    if(!T)
        exit(0);
    cin >> input_data;
    if(input_data!='0') {
        T->data = input_data;
        createBiTree(T->Lchild);
        createBiTree(T->Rchild);
    }else{
        T = NULL;
    }
    return 1;
}

int showBiTreePre(node* T)
{
    if(T!=NULL) {
        cout << T->data << " ";
        showBiTreePre(T->Lchild);
        showBiTreePre(T->Rchild);
    }
    return 1;
}

int showBiTreeMid(node* T)
{
    if(T!=NULL) {
        showBiTreeMid(T->Lchild);
        cout << T->data << " ";
        showBiTreeMid(T->Rchild);
    }
    return 1;
}

int showBiTreeBeh(node* T)
{
    if(T!=NULL) {
        showBiTreeBeh(T->Lchild);
        showBiTreeBeh(T->Rchild);
        cout << T->data << " ";
    }
    return 1;
}

int main()
{
    node* T;
    createBiTree(T);
    showBiTreePre(T);
    showBiTreeMid(T);
    showBiTreeBeh(T);
    return 0;
}
