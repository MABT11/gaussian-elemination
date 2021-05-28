#include <stdio.h>

void user_input(float a [][4], int m)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= m; j++){
            scanf("%f", &a[i][j]); 
        }
    }
}
/*
1  2  3   4
5  6  7   8
9 10  11  12
a[1][0] + ca[0][0]
c = - a[1][0]/a[0][0] 
*/
void ref(float a[][4], int m)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= m; j++)             //00 01 02 03
        {                                       //10 11 12 13
            if(i<j)                             //20 21 22 23 
            {
                float c = -a[j][i]/a[i][i];     //the constant that you will multiply in order to cancel the number below it 
                                                // you want to cancel a[1][0] so you will multiply a[0][0] by the correct coffecient in order to get rid of a[1][0]
                    for(int k = 0; k <= m; k++)
                    a[j][k]=a[j][k]+(c*a[i][k]);    //multiplty all the entries of the row by the same constant and add thekm together
            }
        }
    }
}
void print(float a[][4], int m)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= m; j++){
            printf("%.1f  ", a[i][j]); 
        }
        printf("\n");
    }
}
int main()
{
    int const n = 3;
    float a[n][n+1];
    user_input(a,n);
    ref(a,n);
    print(a,n);
}
