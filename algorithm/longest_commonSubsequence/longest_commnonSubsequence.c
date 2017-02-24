#include<stdio.h>
#include<string.h>

/*global varibles*/
char a[100],b[100];
char state_transient[101][101];//中间结果
char flag_subscript[101][101];    //标记数组来标识下标的走向，


void longest_commonSubsequence(); //用动态规划求解
void get_commonSubsequence();    //求最长公共子序列

int main()
{
    char array[100] = {'\0'};

    while(1)
    {
        //第一行输入序列a，回车，第二行输入序列b，再回车**/
        scanf("%s", array);
        strcpy(a,array);
        memset(array, '\0', sizeof(array));
        //getchar();
        scanf("%s" ,array);
        strcpy(b,array);
        memset(array, '\0', sizeof(array));

        memset(state_transient,0, sizeof(state_transient));
        memset(flag_subscript,0, sizeof(flag_subscript));
        longest_commonSubsequence();

        get_commonSubsequence();
    }
    return 0;
}

void longest_commonSubsequence()
{
    int i = 0;
    int j = 0;

    for(i = 1; i <= strlen(a); i++)
    {
        for(j = 1; j <= strlen(b); j++)
        {
            if(a[i-1] == b[j-1])   //attention!!!!
            {
                state_transient[i][j] = state_transient[i-1][j-1] + 1;
                flag_subscript[i][j] = 1;  //turn inclined down
            }
            else if(state_transient[i][j-1] > state_transient[i-1][j])
            {
                state_transient[i][j] = state_transient[i][j-1];
                flag_subscript[i][j] = 2;  //turn right
            }
            else
            {
                state_transient[i][j] = state_transient[i-1][j];
                flag_subscript[i][j] = 3;  /////turn down
            }
        }
    }
}

void get_commonSubsequence()
{

    char final_subSequence[100] = {'\0'};
    int i = strlen(a);
    int j = strlen(b);
    int k = 0;////用于保存结果的数组标志位

    while(i > 0 && j > 0)
    {
        if(flag_subscript[i][j] == 1)   //斜向下标记
        {
            final_subSequence[k] = a[i-1];
            k++;
            i--;
            j--;
        }
        else if(flag_subscript[i][j] == 2)  //斜向右标记
            j--;
        else if(flag_subscript[i][j] == 3)  //斜向下标记
            i--;
    }

    printf("%d\n", state_transient[strlen(a)][strlen(b)]);
    for(i = k-1;i >= 0; i--)
        printf("%c",final_subSequence[i]);
    printf("\n");
}
