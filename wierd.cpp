#include<iostream> 
// using namespace std;
int main(){
    int a;
    std::cin >> a;
    std::cout << a<<" ";
    while (a>=0){
        if (a%2==0){
            a = a/2;
            std::cout << a;
        }else {
            a = a*3+1;
            std::cout << a;
        }
        if (a!=1)
            std::cout<<" ";
    }
    return 0;
}