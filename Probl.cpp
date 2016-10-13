#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
int validBig(char c)
{
    if((c>=65)&&(c<=90))
        return 1;
    else return 0;
}
int validSmall(char c)
{
    if((c>=97)&&(c<=122))
        return 1;
    else return 0;
}
ifstream f("input.in");
ofstream g("output.out");
using namespace std;
int main()
{
    char s[100000];
    while(f.getline(s,100000))
    {
        int i=0;
        int n=strlen(s);
        if(validBig(s[i])==0)
            s[i]-=32;
        i+=1;
        do{
            if((s[i]=='.')||(s[i]=='?')||(s[i]=='!'))
            {
                while((s[i+1]=='.')||s[i+1]=='?'||(s[i+1]=='!'))
                    i+=1;
                i+=2;
                if(validSmall(s[i])==1)
                    s[i]-=32;
            }
            else if(validSmall(s[i])==0)
                        if(validBig(s[i])==1)s[i]+=32;
        if(s[i+1]==' ') i+=2;
            else if(s[i+1]==',') i+=3;
            else i++;
    }while(i<=n);
    g<<s<<'\n';
    }
    return 0;
}
