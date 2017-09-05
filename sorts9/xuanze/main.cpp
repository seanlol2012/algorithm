#include <iostream>

using namespace std;

void select_sort(int *a, int n);    //ѡ������
void bubble_sort(int *a, int n);    //ð������
void insert_sort(int *a, int n);    //��������
void shell_sort(int *a, int n);     //ϣ������
void merge_sort(int *a, int low, int high); //�鲢����low��high��
void quick_sort(int *a, int l, int r);      //��������l��r��
void heap_sort(int *a, int n);      //������
void counting_sort(int *a, int n);

//���ڹ鲢�����������n�Ŀռ�
int b[6] = {0};

int main()
{
    //cout << "Hello world!" << endl;
    int a[] = {5,1,3,6,2,4};
    int array_len;
    array_len = sizeof(a) / sizeof(int);
    //select_sort(a, array_len);
    //bubble)sort(a, array_len);
    //insert_sort(a, array_len);
    //shell_sort(a, array_len);
    //merge_sort(a, 0, array_len - 1);
    //quick_sort(a, 0, array_len - 1);
    heap_sort(a, array_len);
    for(int i=0; i<6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

void select_sort(int *a , int n)
{
    int i, j;
    int min_pos, temp;
    for(i=0; i<n-1; i++) {
        min_pos = i;
        for(j=i+1; j<n; j++) {
            if(a[j] < a[min_pos])
                min_pos = j;
        }
        if(min_pos != i) {
            temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}

void bubble_sort(int *a, int n)
{
    int i,j;
    int temp;
    for(i=0; i<n; i++) {
        for(j=n-1; j>i; j--) {
            if(a[j] < a[j-1]) {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

void insert_sort(int *a, int n)
{
    int i, j;
    int temp;
    for(i=1; i<n; i++) {
        j = i - 1;      //jΪ��ǰ���i��ǰһ����ֵ
        temp = a[i];    //��ǰ���i������ֵ
        while(j >= 0) { //��temp�Ӻ���ǰ���뵽���ź���ĸպô���������ֵ֮ǰ��������Ų���ź����ֵ
            if(a[j]>temp) {
                a[j+1] = a[j];
                j--;
            } else {
                break;
            }
        }
        a[j+1] = temp;
    }
}

void shell_sort(int *a, int n)
{
    //�˴�����Ϊ5��3��1����Ϊ����
    int gap;
    int i, j;
    int temp;
    for(gap=5; gap>0; gap-=2) {
        for(i=gap; i<n; i++) {
            j = i - gap;
            temp = a[i];
            while(j >= 0) {
                if(a[j] > temp) {
                    a[j+gap] = a[j];
                    j -= gap;
                } else {
                    break;
                }
            }
            a[j+gap] = temp;
        }
    }
}

void merge_sort(int *a, int low, int high)
{
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        int i = low, j = mid + 1;
        int k = i;
        while(i <= mid && j <= high) {  //�ϲ�
            if(a[i] <= a[j]) {
                b[k++] = a[i];
                i++;
            } else {
                b[k++] = a[j];
                j++;
            }
        }
        while(i <= mid) {
            b[k++] = a[i++];
        }
        while(j <= high) {
            b[k++] = a[j++];
        }
        for(int x=1, i=low; x<=high-low+1; x++, i++)
            a[i] = b[i];
    }
}

void quick_sort(int *a, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = a[l];
        while (i < j)
        {
            while(i < j && a[j]>= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                a[i++] = a[j];  //������һ��ֵ�滻Ϊ�Ҳ��һ��С��x����
            while(i < j && a[i]< x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                a[j--] = a[i];  //���Ҳ���Ǹ�ֵ�滻Ϊ����һ��С��x����
        }
        a[i] = x;
        quick_sort(a, l, i - 1); // �ݹ����
        quick_sort(a, i + 1, r);
    }
}

void max_heapify(int *a, int p, int n)
{
    int left = 2 * p;
    int right = 2 * p + 1;
    int large = p;
    if(left <= n && a[left] > a[p])
        large = left;
    if(right <= n && a[right] > a[large])
        large = right;

    if(large != p) {
        int temp = a[p];
        a[p] = a[large];
        a[large] = temp;
        max_heapify(a, large, n);
    }
}

void heap_sort(int *a, int n)
{
    //build_max_heap
    for(int i = n/2; i > 0; i--)
        max_heapify(a, i-1, n-1);

    int temp;
    while(n > 0){
        temp = a[n];
        a[n] = a[0];
        a[0] = temp;

        --n;
        max_heapify(a, 0, n-1);
    }
}
