#include<bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int R;
    cin>>R;

    for(int king=1;king<=R;king++){
        cout<<"Case #"<<king<<": ";

        int n;
        cin>>n;

        vector<pair<pair<int, int>, int>> work;
        for(int i=0;i<n;i++){
            int s, e;
            cin>>s>>e;

            work.push_back({{s, e}, i});
        }
        string s = "";
        for(int i=0;i<n;i++) s += '@';

        vector<pair<int, int>> kaam;

        for(auto it:work){
            kaam.emplace_back(it.first.first, (it.second + 1));
            kaam.emplace_back(it.first.second, -(it.second + 1));
        }

        sort(kaam.begin(), kaam.end());
        bool c = true, j = true;
        bool raft = true;

        for(auto it:kaam){
            if(it.second > 0){
                int index = it.second;
                if(c){
                    s[index - 1] = 'C';
                    c = false;
                }
                else if(j){
                    s[index - 1] = 'J';
                    j = false;
                }
                else{
                    raft = false;
                    break;
                }
            }
            else{
                int index = -it.second;
                if(s[index - 1] == 'C') c = true;
                else if(s[index - 1] == 'J') j = true;
                else{
                    raft = false;
                    break;
                }
            }
        }

        if(raft) cout<<s<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}
