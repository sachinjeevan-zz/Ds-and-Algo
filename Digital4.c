#include<stdio.h>
#include<string.h>
void display(char ans[])
{
    printf("%s\n",ans);
}
int isSafe(char ans[],int pos,char x)
{
    for(int i=0;i<pos;i++)
    {
        if(ans[i]==x)
        {
            return 0;
        }
    }
    return 1;
}
void solve(char str[],char ans[],int len,int pos)
{
    if(pos!=len)
    {
        for(int i=0;i<len;i++)
        {
            if(isSafe(ans,pos,str[i])==1)
            {
                ans[pos] = str[i];
                solve(str,ans,len,pos+1);
            }
            
        }
    }
    else
    {
        ans[pos]='\0';
        display(ans);
    }
    
}
int main()
{
    char str[1000];
    scanf("%s",str);
    int len = strlen(str);
    char ans[1000];
    for(int i=0;i<len;i++)
    {
        ans[0] = str[i];
        solve(str,ans,len,1);
    }

}