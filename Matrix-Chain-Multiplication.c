/**
 ** Author - Dipendu Ghosh
 ** Program - Matrix Chain Multiplication
 **/

#include<stdio.h>
#include<stdlib.h>

void MatrixChainOrder(int p[],int n,int **m,int **s)
{
    int i,j,k,l,q;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for (l=2;l<n;l++)
    {
        for (i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=32767;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}

void PrintParenthesis(int **s,int i,int j)
{
    if (i == j)
        printf(" A%d ",i);
    else
    {
        printf("( ");
        PrintParenthesis(s,i,s[i][j]);
        PrintParenthesis(s,s[i][j]+1,j);
        printf(" )");
    }
}

int main()
{
    int n,i,j;
    printf("\nEnter the no. of matrices : ");
    scanf("%d",&n);
    int *dimension=(int*)calloc((n+1),sizeof(int));
    printf("\nEnter the dimensions : ");
    for(i=0;i<n+1;i++)
        scanf("%d",&dimension[i]);

    int **m=calloc((n+1),sizeof(int));
    for(i=0;i<n+1;i++)
        m[i]=(int*)calloc(n+1,sizeof(int));
    int **s=calloc(n,sizeof(int));
    for(i=0;i<n+1;i++)
        s[i]=(int*)calloc(n+1,sizeof(int));

    MatrixChainOrder(dimension,n+1,m,s);

    printf("\n\n>>> Optimal Parenthesization :\n\n\t\t");
    PrintParenthesis(s,1,n);

    printf("\n\n\n>>> Optimal Scalar Multiplication Required = %d\n\n",m[1][n]);
    return 0;
}
