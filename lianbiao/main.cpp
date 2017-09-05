#include <iostream>

using namespace std;

struct ListNode
{
    int m_nkey;
    ListNode* m_pNext;
};

class list
{
    ListNode* pHead;
    ListNode* pTail;
public:
    list() {
        pHead = NULL;
    }
    void insertlist(int aKey, int bKey);    //在值为aKey的结点前插入值为bKey的结点
    void deletelist(int aKey);  //删除值为aKey的结点
    void outputlist();  //输出列表
    void addlistnode(int aKey); //在列表的最后添加结点
    ListNode* Gethead() {
        return pHead;
    }
};

void list::outputlist() {
    ListNode* current = pHead;
    while(current != NULL) {
        cout << current->m_nkey << " ";
        current = current->m_pNext;
    }
    cout << endl;
}

//在值为aKey的节点a之前插入值为bKey的节点b；
void list::insertlist(int aKey, int bKey)
{
    ListNode *p, *q, *s;//p指向a，q指向a的前一个节点，s指向b
    s = (ListNode*)new(ListNode);

    s->m_nkey = bKey;

    p = pHead;
    if(pHead == NULL) { //若是空表
        pHead = s;
        s->m_pNext = NULL;
    } else if(p->m_nkey == aKey) {  //若a是第一个节点
        s->m_pNext = p;
        pHead = s;
    } else {
        while(p->m_nkey != aKey && p->m_pNext != NULL) {
            q = p;  //设置q指向a的前一个节点
            p = p->m_pNext;
        }
        if(p->m_nkey == aKey) {
            q->m_pNext = s;
            s->m_pNext = p;
        }
    }
}

//删除值为aKey的节点a
void list::deletelist(int aKey) {
    ListNode *p, *q;
    p = pHead;
    if(p == NULL) {
        return;
    }
    if(p->m_nkey == aKey) { //若a是第一个节点
        pHead = p->m_pNext;
        delete p;
    } else {
        while(p->m_nkey != aKey && p->m_pNext != NULL) {
            q = p;
            p = p->m_pNext;
        }
        if(p->m_nkey == aKey) {
            q->m_pNext = p->m_pNext;
            delete p;
        }
    }
}

//将值为aKey的节点添加到list的最后
void list::addlistnode(int aKey) {
    ListNode *p, *s;

    s = (ListNode*)new(ListNode);
    s->m_nkey = aKey;
    s->m_pNext = NULL;

    p = pHead;
    if(p == NULL) {
        pHead = s;
    } else {
        while(p->m_pNext != NULL) {
            p = p->m_pNext;
        }
        p->m_pNext = s;
    }
}

int main()
{
    list testlist;
    testlist.addlistnode(5);
    testlist.addlistnode(6);
    testlist.insertlist(5,4);
    testlist.outputlist();
    testlist.deletelist(5);
    testlist.outputlist();
    return 0;
}
