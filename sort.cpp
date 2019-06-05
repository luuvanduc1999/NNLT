Selection Sort
for (i=0; i<n-1; i++)
{
    min =i;
    for (j=i+1; j<n; j++)
    if (a[j]<a[min]) min=j;
    swap( a[min] , a[i]);
}
//========================
Bubble Sort
for (i=0; i<n-1; i++)
{
    for (j=n-1; j>=i+1; j--)
    if (a[j-1]<a[j])
    swap( a[j-1] , a[j]);
}
//========================
Insert Sort
for(i=1; i<n; i++)
{
    k=a[i];
    j=i-1;

    while (j>=0) && (k<a[j])
    {
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=k;
}
//========================
Quick Sort
void QS(int L, int H)
{
    int i=L;
    int j=H;
    int x=a[(L+H)/2];
    
    do
    {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j)
        {
            Swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    while (i<=j);
    
    if (L<j) QS(L,j);
    if (i<H) QS(i,H);
}
