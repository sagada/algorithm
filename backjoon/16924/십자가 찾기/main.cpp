#include<iostream>
#include<vector>
#include<tuple>
#include<string.h>
using namespace std;
 bool check[100][100];
int main(){
    int n,m;
    vector<tuple<int,int,int>> ans;
   
    
  
    cin>>n>>m;
      vector<string> map(n);
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='*')
            {
                int l=0;
                for(int len=1;;len++){
                    if(i+len<n && i-len >= 0  && j+len <m && j-len >=0 ){
                        
                        if(map[i+len][j]=='*' && map[i-len][j]=='*' && map[i][j+len]=='*' && map[i][j-len]=='*'){
                            l=len;
                        }else{
                            break;
                        }
                        
                    }else{
                        break;
                    }
                }
                
                if(l>0){
               
                    ans.push_back(make_tuple(i+1,j+1,l));
                    check[i][j]=true;
                    for(int k=1;k<=l;k++){
                        check[i-k][j]=true;
                        check[i][j-k]=true;
                        check[i+k][j]=true;
                        check[i][j+k]=true;
                    }
                }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check[i][j]==false && map[i][j]=='*'){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto &s : ans){
        int x,y,len;
        tie(x,y,len)=s;
        cout<<x<<" "<<y<<" "<<len<<"\n";
    }
    
    return 0;
    
}
