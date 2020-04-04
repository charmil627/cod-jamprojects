#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int w=0;
    while(T--)
    {
        w++;
        int n;
        cin>>n;
        int a[n][n];
        int s=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(i==j)
                    s+=a[i][j];
            }
        int row=0,col=0;
        bool req=true;

    for(int i=0;i<n;i++)
        {
            req=true;
            for(int j=0;j<n;j++)
            {
                for(int q=j+1;q<n;q++)
                    {
                        if(a[j][i]==a[q][i])
                        {
                            col++;
                            req=false;
                            break;
                        }
                    }
                if(req!=true)
                    break;
            }

    	}

	for(int i=0;i<n;i++)
        {
            req=true;
            for(int j=0;j<n;j++)
            {
                for(int q=j+1;q<n;q++)
                    {
                        if(a[i][j]==a[i][q])
                        {
                            row++;
                            req=false;
                            break;
                        }
                    }
                if(req!=true)
                    break;
            }

    }
    cout<<"Case #"<<w<<":"<<" "<<s<<" "<<row<<" "<<col<<endl;
}
}
