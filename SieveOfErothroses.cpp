#include<iostream>
#include<vector>
#include<cmath>
#include<map>


using namespace std;

int main(){
    int a,b,n;
    cin >> a>>b>>n;
    vector<pair<int,int>> row ;
    for(int i=a;i<=b;i++){
        row.push_back({i,1});
    }
    for(int i=2;i<=b;i++){
        for(int j=1;j<=b;j=j*i){
                row[j].second++;
        }
    }
    int count =0;
    for(int i=0;i<row.size();i++){
        if(row[i].second == n){
            count++;
        }
    }
    cout<< count <<endl;
    return 0;
}