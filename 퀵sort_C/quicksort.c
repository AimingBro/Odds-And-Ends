int		partition(int a[], int begin, int end)
{
	int pivot = (begin + end) / 2;
    int L = begin;
    int R = end;
    while(L < R)
    {
        while(a[L] < a[pivot] && L < R)
            L = L + 1;
        while(a[R] >= a[pivot] && L < R)
            R = R - 1;
        if(L < R)
        {
            if(L == pivot)
                pivot = R;
            int temp = a[L];
            a[L] = a[R];
            a[R] = temp;
        }
    }
    int temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;
    return (R);
}

void	quciksort(int a[], int begin, int end)
{
    if(begin < end)
    {
        int	p = partition(a, begin, end);
        quciksort(a, begin, p-1);
        quciksort(a, p+1,end);
    }
}
