#include <stdio.h>
#include <stdlib.h>

int isreach(int m11, int m12, int n11, int n12, int m21, int m22, int n21, int n22)
{
    int minm1,minm2,temp1,temp2;
    float k1,k2;
    if(m12<m11)
    {
        temp1 = m11;
        temp2 = n11;
        m11 = m12;
        n11 = n12;
        m12 = temp1;
        n12 = temp2;
    }
    if(m22<m21)
    {
        temp1 = m21;
        temp2 = n21;
        m21 = m22;
        n21 = n22;
        m22 = temp1;
        n22 = temp2;
    }
    if(m11<m21)
    {
        minm1 = m21;
    }
    else
    {
        minm1 = m11;
    }
    if(m12<m22)
    {
        minm2 = m12;
    }
    else
    {
        minm2 = m22;
    }
    k1 = (n12-n11)/(m12-m11);
    k2 = (n22-n21)/(m22-m21);
}

int main()
{
    int m,n,lasernum;
    printf("please input the m and n:\n");
    while(scanf("%d %d",&m,&n))
    {
        //flag表示是否有无法通过的情况存在，0表示没有，1表示有
        int i,flag,whichlaser;
        flag = 0;
        whichlaser = 0;
        //printf("%d %d\n",m,n);
        printf("please input the number of laser:\n");
        scanf("%d",&lasernum);
        int x1[lasernum],x2[lasernum],y1[lasernum],y2[lasernum];
        printf("please input all the x1,x2,y1,y2 in order:\n");
        for(i=0;i<lasernum;i++)
        {
            scanf("%d %d %d %d",&x1[i],&x2[i],&y1[i],&y2[i]);
            printf("OK\n");
        }
        for(i=0;i<lasernum;i++)
        {

        }
        printf("please input the m and n:\n");
    }
    return 0;
}
