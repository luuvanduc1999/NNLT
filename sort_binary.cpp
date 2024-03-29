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
void QS(int L, int R)
{
    int i=L;
    int j=R;
    int x=a[(L+R)/2];
    
    do
    {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    while (i<=j);
    
    if (L<j) QS(L,j);
    if (i<R) QS(i,R);
}
//============================
L=0; R=n-1;
while (L<R) do
{
	k=(L+R)/2;
	if (a[k]==X) 
		return(k);
	if (a[k]<X) L=k+1;
	else R=k-1;
}
Return(-1);
