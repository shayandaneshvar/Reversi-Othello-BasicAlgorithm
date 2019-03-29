#include <stdio.h>

int check(int arr[8][8], int m, int n, int i, int j, int o, int u)
{
    int a = i - m;
    int b = j - n;
    while (arr[i][j] == o && i < 8 && j < 8)
    {
        i += a;
        j += b;
    }
    if (arr[i][j] == u)
        return -1;
    else
        return 0;
}
void value(int arr[8][8])
{
    int i, j;
    //Corners have the value -1 which is already -1
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            //x
            if (((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6)) && arr[i][j] == -1)
                arr[i][j] = -8;
            //c
            else if (((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 0 && j == 6) || (i == 6 && j == 0) || (i == 6 && j == 7) || (i == 7 && j == 6) || (i == 7 && j == 1) || (i == 1 && j == 7)) && arr[i][j] == -1)
                arr[i][j] = -7;
            //4
            else if(((i==2&&j==2)||(i==2&&j==5)||(i==5&&j==5)||(i==5&&j==2))&&arr[i][j] == -1)	
				arr[i][j]=-2;
            //16-4s
            else if (i > 1 && i < 6 && j > 1 && j < 6 && arr[i][j] == -1)
                arr[i][j] = -3;
            //others
            else if (((i > 1 && i < 6 && (j == 1 || j == 6)) || (j > 1 && j < 6 && (i == 1 || i == 6))) && arr[i][j] == -1)
                arr[i][j] = -4;
            //A
            else if (((i == 0 && j == 2) || (i == 0 && j == 5) || (i == 2 && j == 0) || (i == 2 && j == 7) || (i == 5 && j == 0) || (i == 5 && j == 7) || (i == 7 && j == 2) || (i == 7 && j == 5)) && arr[i][j] == -1)
                arr[i][j] = -5;
            //B
            else if (((i==0 && (j==3 || j==4))||(i==7 && (j==3 || j==4))||(j==0 && (i==3 || i==4))||(j==7 && (i==3 || i==4))) && arr[i][j] == -1)
                arr[i][j] = -6;
        }
    }
}
void easy(int arr[8][8]){
	int x=-10,i,j,i1,j1;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(arr[i][j]<0&&arr[i][j]>x){
				x=arr[i][j];
				i1=i;
				j1=j;
			}
		}
	}
	printf("%d %d",j1,i1);
	return;
}
int main(int argc, char *argv[])
{
    int arr[8][8], u = argv[9][0] - '0', o, i, j;
    if (u == 1)
    {
        o = 2;
    }
    else
    {
        o = 1;
    }
    for (i = 1; i < 9; i++)
    {
        for (j = 0; j < 8; j++)
        {
            arr[i - 1][j] = argv[i][j] - '0';
        }
    }

    for (i = 0; i < 8; i++)
     {
        for (j = 0; j < 8; j++)
        {
            if (arr[i][j] == o)
            {
                if (arr[i + 1][j] == 0 && i + 1 < 8)
                {
                    arr[i + 1][j] = check(arr, i + 1, j, i, j, o, u);
                }
                if (arr[i - 1][j] == 0 && i - 1 >= 0)
                {
                    arr[i - 1][j] = check(arr, i - 1, j, i, j, o, u);
                }
                if (arr[i][j + 1] == 0 && j + 1 < 8)
                {
                    arr[i][j + 1] = check(arr, i, j + 1, i, j, o, u);
                }
                if (arr[i][j - 1] == 0 && j - 1 >= 0)
                {
                    arr[i][j - 1] = check(arr, i, j - 1, i, j, o, u);
                }
                if (arr[i + 1][j + 1] == 0 && i + 1 < 8 && j + 1 < 8)
                {
                    arr[i + 1][j + 1] = check(arr, i + 1, j + 1, i, j, o, u);
                }
                if (arr[i + 1][j - 1] == 0 && i + 1 < 8 && j - 1 >= 0)
                {
                    arr[i + 1][j - 1] = check(arr, i + 1, j - 1, i, j, o, u);
                }
                if (arr[i - 1][j - 1] == 0 && i - 1 >= 0 && j - 1 >= 0)
                {
                    arr[i - 1][j - 1] = check(arr, i - 1, j - 1, i, j, o, u);
                }
                if (arr[i - 1][j + 1] == 0 && i - 1 >= 0 && j + 1 < 8)
                {
                    arr[i - 1][j + 1] = check(arr, i - 1, j + 1, i, j, o, u);
                }
            }
        }
    }
    value(arr);
	easy(arr);
    return 0;
}
