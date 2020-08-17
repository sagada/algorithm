#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n;
int main(){

    cin>>n;
    string a;
    
    vector<pair<int,int>> vec[26][2];
    for(int i=0;i<n;i++){
        cin>>a;
        
        for(int j=0;j<a.size();j++){
            vec[a[j]-'a'][0].push_back(make_pair(j, i));
            vec[a[j]-'a'][1].push_back(make_pair((int)a.size()-(j+1),i));
        }
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<2;j++){
            sort(vec[i][j].begin(),vec[i][j].end());
        }
    }
    int ans=22;
    for(int i=0;i<26;i++){
        if(vec[i][0].size()==0 || vec[i][1].size()==0)
            continue;
        
        int temp_front=vec[i][0][0].first;
        for(int j=0;j<vec[i][1].size();j++){
            if(vec[i][0][0].second!= vec[i][1][j].second){
                ans=min(ans,vec[i][1][j].first+temp_front);
                break;
            }
        }
        int temp_rear=vec[i][1][0].first;
        for(int k=0;k<vec[i][0].size();k++){
            if(vec[i][1][0].second != vec[i][0][k].second){
                ans=min(ans,vec[i][0][k].first + temp_rear);
                break;
            }
        }
    }
    if(ans==22){
        cout<<"-1\n";
    }else{
        cout<<ans<<"\n";
    }
}
