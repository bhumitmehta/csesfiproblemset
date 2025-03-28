#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;


void dfs(vector<vector<char>>& floor,vector<vector<bool>>& visited,int i,int j){
   if (i < 0 || j < 0 || i >= floor.size() || j >= floor[0].size() || visited[i][j] || floor[i][j] == '#') {
        return;
    }
        else{
        visited[i][j]=true;
        dfs(floor,visited,i+1,j);
        dfs(floor,visited,i-1,j);
        dfs(floor,visited,i,j+1);
        dfs(floor,visited,i,j-1);
        return;
    }
}


int main(){
    int n,q;

    cin>>n>>q;
    vector<vector<char>> floor (n,vector<char>(q));
    vector<vector<bool>> visited(n,vector<bool>(q,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cin>> floor[i][j];
        }
    }
    
    int rooms =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            // cout<<"here";
            if(!visited[i][j] && floor[i][j]=='.'){
                
                dfs(floor,visited,i,j);
                rooms++;
            }
        }
    }
cout<<rooms;
    
    return 0;
}