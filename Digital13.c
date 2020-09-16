#include<stdio.h>
int charToInt(char ch)
{
    return ch - 48;
}
long long int extractNumber(char str[])
{
    long long int num=0,ans=-1,flag=1;
    for(int i=0;str[i]!='\0';i++)
    {    
        if(str[i]=='9')
            flag=0;
        if(str[i]>=48 && str[i]<=57)
        {
            num = num*10 + charToInt(str[i]);
        }
        else
        {
            if(num>ans && flag==1)
                ans = num;
            num=0;
            flag=1; 
        }
        
    }
    if(num>ans && flag==1)
        ans = num;
    return ans;

}
int main()
{
    char str[1000];
    scanf("%[^\n]s",str);
    long long int ans = extractNumber(str);
    printf("%lld",ans);
    
}