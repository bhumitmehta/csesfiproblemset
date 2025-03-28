#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >>t;
    while(t-->0){
        int N;
        int X;
        cin >> N >>X;
        std::vector<int> A;
        for(int i=0;i<N;i++){
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        
        int i =0;
        int j=1;
        int temp =-1;
        int maxsize =0;
        while(i<N&&j<N){
            if(A[j-1]<=A[j]){
                j++;
                maxsize = max(maxsize,j-i);

            }else if(A[j-1]>A[j]&& temp==-1){
                if(A[j]*X<A[j-1]){
                    i = j;
                    j++;
                    maxsize = max(maxsize,j-i);
                }
                else {
                temp = j;
                A[j] = A[j]*X;
                j++;
                maxsize = max(maxsize,j-i);
                }
            }else{
                i = temp;
                A[temp] = A[temp]/X;
                temp = -1;
                maxsize=max(maxsize,j-i);
            }
            // cout<<i<<" "<<j<<" "<<maxsize<<" ";

        }
        cout<<maxsize<<endl;
    }
    
    return 0;
    
    
}
