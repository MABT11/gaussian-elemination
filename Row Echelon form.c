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
            if(i>j)                             //20 21 22 23 
            {
                float c = -a[i][j]/a[j][j];     //value of the number you want to cancel/ the number above it
                    for(int k = 0; k <= m; k++)
                    a[i][k]=a[i][k]+(c*a[0][k]);
                
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
