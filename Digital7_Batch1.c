#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
char secondFrequentChar(char str[],int n)
{
    int hash[128] = {0};
    for(int i=0;i<n;i++)
    {
        hash[str[i]]++;
    }
    int max= 0, sMax = 0,ind;
    char ans;
    for(int i=0;i<127;i++) // a= 5 b=3 
    {
        if(hash[i]>max)
        {
            sMax = max;
            if(sMax!=0)
            {
               ans = ind; 
            }
            ind = i;
            max = hash[i];

        }
        else
        {
            if(hash[i]>sMax && hash[i]!=max)
            {
                ans = i;
                sMax = hash[i];
            }
        }
        
    }
    return sMax!=0?ans:-1;

}
int main()
{
    char str[1000];
    scanf("%s",str);
    int n = strlen(str);
    char x = secondFrequentChar(str,n);
    if(x!=-1)
        printf("%c is the second frequent character",x);
    else
        printf("No second frequent character");
}