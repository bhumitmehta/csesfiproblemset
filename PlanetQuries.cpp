#include<iostream>
#include<vector>

using namespace std;


void dfs(vector<vector<int>>& a,int from,int i,vector<int> planets) {
    visited
    dfs(a,from,planets[i],planets);
}

vector<vector<int>> creategraph(vector<int> planets)
{
    vector<vector<int>> a (planets.size()-1,vector<int>());
    for(int i=0;i<planets.size();i++){
        dfs(a,0,i,[planets]);
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n>>q;
    vector<int> planets(n);
    for(int i = 0; i < n; i++){
        cin >> planets[i];
    }
    vector<vector<int>> a = creategraph(planets);

    while(q-->0){
        int a,b;
        cin>>a>>b;

    }

    return 0;
}