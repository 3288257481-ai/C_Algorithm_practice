#include<stdio.h>
int q[1000];
int n;

int quick_sort(int q[], int l, int r, int k)
{
    if(l>=r) return q[l];

    int i = l-1;
    int j = r+1;
    int x = q[(l+r)/2];

    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);

        if(i<j)
        {
            int temp = q[i];
            q[i] = q[j];
            q[j] = temp;
        }
    }

    if(j-l+1>=k) return quick_sort(q, l, j, k);
    else return quick_sort(q, j+1, r, k-(j-l+1));
}

int main()
{
    int k;
    scanf("%d",&k);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }

    int number = quick_sort(q,0,n-1,k);
    printf("%d",number);
}