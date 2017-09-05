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
    void insertlist(int aKey, int bKey);    //��ֵΪaKey�Ľ��ǰ����ֵΪbKey�Ľ��
    void deletelist(int aKey);  //ɾ��ֵΪaKey�Ľ��
    void outputlist();  //����б�
    void addlistnode(int aKey); //���б�������ӽ��
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

//��ֵΪaKey�Ľڵ�a֮ǰ����ֵΪbKey�Ľڵ�b��
void list::insertlist(int aKey, int bKey)
{
    ListNode *p, *q, *s;//pָ��a��qָ��a��ǰһ���ڵ㣬sָ��b
    s = (ListNode*)new(ListNode);

    s->m_nkey = bKey;

    p = pHead;
    if(pHead == NULL) { //���ǿձ�
        pHead = s;
        s->m_pNext = NULL;
    } else if(p->m_nkey == aKey) {  //��a�ǵ�һ���ڵ�
        s->m_pNext = p;
        pHead = s;
    } else {
        while(p->m_nkey != aKey && p->m_pNext != NULL) {
            q = p;  //����qָ��a��ǰһ���ڵ�
            p = p->m_pNext;
        }
        if(p->m_nkey == aKey) {
            q->m_pNext = s;
            s->m_pNext = p;
        }
    }
}

//ɾ��ֵΪaKey�Ľڵ�a
void list::deletelist(int aKey) {
    ListNode *p, *q;
    p = pHead;
    if(p == NULL) {
        return;
    }
    if(p->m_nkey == aKey) { //��a�ǵ�һ���ڵ�
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

//��ֵΪaKey�Ľڵ���ӵ�list�����
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
