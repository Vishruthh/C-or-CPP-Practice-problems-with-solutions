//Set operation - Union on Arrays by Vishruth Codes
#include<iostream>
using namespace std;

void displayed(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout<<a[i]<<".";
        }
        else{
           cout<<a[i]<<", "; 
        }
    }
}

int unions(int a[], int n, int b[], int m, int res[])
{
    int i=0,k=0,t=0,count=0;
    //Copying the elements of first array into the result array.
    while(i<n)
    {
        res[t++]=a[i++];
    }
    while(i<m+n && k<m)
    {
        int j=0;
        while(j<i+1)
        {
            if (res[j]==b[k])
            {
                k++;
                //the value of i should be updated only is the adjacent space is occupied.
                //Here, adjacent space is not occupied, hence to prevent jump to next space
                //we write i--
                i--;
                break;
            }
            else if(j==i)
            {
                res[j]=b[k];
                k++;
                count++;
                break;
            }
            else{
                j++;
            }
        }
        i++;
    }
    return (n+count);
}

int main()
{
    int n,m;
    int ar1[]={1,4,9,16,32};
    int ar2[]={1,2,3,4,5,6,7,8,9,10};
    n=sizeof(ar1)/sizeof(ar1[0]);
    cout<<"\nArray1: ";
    displayed(ar1,n);
    m=sizeof(ar2)/sizeof(ar2[0]);
    cout<<"\nArray2: ";
    displayed(ar2,m);
    int un[n+m];
    int size=unions(ar1,n,ar2,m,un);
    //Here size is the length of union
    cout<<"\nThe union: ";
    displayed(un,size);

    return 0;
}
