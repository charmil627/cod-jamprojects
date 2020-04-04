
#include<bits/stdc++.h>
using namespace std;
string str1;

void kfc(int p);
int main()
{
    int t;
    cin>>t;
    int qua=0;
    while(t--)
    {
        qua++;
        cin>>str1;
        kfc(qua);
    }
}
void kfc(int qua)
{
        string str="";
        for(int re=0;re<(str1[0]-'0');re++)
            str+='(';
        for(int i=0;i<str1.length()-1;i++)
        {
            if(str1[i+1]-'0'<str1[i]-'0')
            {
                str+=str1[i];
                for(int re=0;re<abs(str1[i+1]-str1[i]);re++)
                    str+=')';
            }
            else
            {
                str+=str1[i];
                for(int re=0;re<abs(str1[i+1]-str1[i]);re++)
                    str+='(';
            }
        }
        str+=str1[str1.length()-1];
        for(int i=0;i<str1[str1.length()-1]-'0';i++)
            str+=')';
        cout<<"Case #"<<qua<<":"<<" "<<str<<endl;
}
