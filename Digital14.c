#include<stdio.h>
#include<math.h>
void destination(int n)
{
    int ans[2];
    int x1=10,y1=20,x2=-20,y2=20,x3=-20,y3=-20,x4=30,y4=-20;
    int m1=20,n1=20,m2=-20,n2=20,m3=-20,n3=-20,m4=20,n4=-20;
    if(n==1)
    {
        ans[0]=0;
        ans[1]=10;
        
    }
    int quadrant = (n-1)%4==0?4:(n-1)%4;
    int visit = ceil((n-1)/4.0);
    if(quadrant==1)
    {
        int a = m1*(visit-1);
        int b= n1*(visit-1);
        ans[0] = x1+a;
        ans[1] = y1+b;
        
    }
    else if(quadrant==2)
    {
        int a = m2*(visit-1);
        int b= n2*(visit-1);
        ans[0] = x2+a;
        ans[1] = y2+b;
       
    }
    else if(quadrant==3)
    {
        int a = m3*(visit-1);
        int b= n3*(visit-1);
        ans[0] = x3+a;
        ans[1] = y3+b;
        
    }
    else if(quadrant==4)
    {
        int a = m4*(visit-1);
        int b= n4*(visit-1);
        ans[0] = x4+a;
        ans[1] = y4+b;
        
    }
    printf("%d %d",ans[0],ans[1]);

}
int main()
{
    int n;
    scanf("%d",&n);
    destination(n);
}