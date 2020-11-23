#include <iostream>
using namespace std;

bool linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return true;
    }
    return false;
}

bool checkSubarray(int *arr,int *subarray ,int n,int m)
{
    for(int i=0;i<m;i++){
        if(!linearSearch(arr,n,subarray[i])){
            return false;
        }
    }
    return true;

}

bool checkTriphLet(int *arr,int n,int x){

    for(int i=0;i<n;i++){
        for(int j=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==x){
                    return true;
                }
            }
        }
    }
    return false;

}


void sort012(int *arr,int n){
    int count0 = 0,count1=1,count2=0;
    for(int i=0;i<n;i++){
        switch (arr[i])
        {
        case 0 : count0++;
            break;
        case 1 : count1++;
            break;
        case 2 : count2++;
            break;
        }
        
    }
    for(int i=0;i<=count1;i++)
        arr[i]=0;
    for(int i=count1;i<=count2;i++)
        arr[i]=1;
    for(int i=count2;i<n;i++)
        arr[i]=2;
    
}



int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        // int n,m;
        // cin>>n;
        // cin>>m;

        // int *arr = new int[n];
        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }
        // int *subArray = new int[m];
        // for(int i=0;i<m;i++){
        //     cin>>subArray[i];
        // }
        
        // if(checkSubarray(arr,subArray,n,m)){
        //     cout<<"Yes"<<endl;
        // }
        // else{
        //     cout<<"No"<<endl;
        // }
        // delete[] arr;
        // delete[] subArray;
        // int n;
        // cin>>n;
        // int x;
        // cin>>x;
        // int *arr = new int[n];
        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }

        // if(checkTriphLet(arr,n,x)){
        //     cout<<1<<endl;
        // }
        // else{
        //     cout<<0<<endl;
        // }

        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        
    }

    return 0;
}