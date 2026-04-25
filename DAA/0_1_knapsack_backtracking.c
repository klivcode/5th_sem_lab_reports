#include<stdio.h>

int main()
{
    int i,w;
    int n=4;
    int W =7; // kanpsack capacity
    int wt[]={1,3,4,5}; // weights of the items
    int val[]={1,4,5,7}; // values of the items

    int k[n+1][W+1];

    for ( i=0; i<=n; i++)
    {
        for ( w=0; w<=W; w++)
        {
            if (i==0 || w==0)
                k[i][w] = 0;
            else if (wt[i-1] <= w){
                if (val[i-1] + k[i-1][w-wt[i-1]] > k[i-1][w])
                    k[i][w] = val[i-1] + k[i-1][w-wt[i-1]];
                else
                    k[i][w] = k[i-1][w];
            }
            else
                k[i][w] = k[i-1][w];
        }
    }

    printf("Maximum Profit is %d\n", k[n][W]);
    // backtracking to find the items included in the knapsack
    printf("Selected items are: ");
    i =n;
    w= W;
    while (i > 0 && w > 0)
    {
        if (k[i][w] != k[i-1][w])
        {
            printf("%d ", i);
            w = w - wt[i-1];
        }
        i--;
    }
    return 0;
}