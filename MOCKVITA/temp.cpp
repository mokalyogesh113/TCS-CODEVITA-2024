#include<iostream>
using namespace std;
int main()
{
    int a=0,b=0,c=0;

    for(c = 3;c<=4;c++)
    {
        if(b+a < a-b)
        {
            a=c+a;
        }
    }

    cout<<a+b;

}