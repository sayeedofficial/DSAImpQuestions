#include<iostream>
using namespace std;
#define ll long long



int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    while(t--){
        ll a,b;
        cin>>a>>b;  

        if(a==1 && b==1){
            cout<<1<<endl;
        }
        else{
            ll smallAns = (a*b )- ((a+1)/2)*((b/2))- (b+1)/2*(a/2) ;
            cout<<smallAns<<endl;
        }
        
    }
    
    return 0;
}
