#include <iostream>
using namespace std;

bool checkpallindrom(int a)
{
    int num = a;
    int revNum = 0;

    while (num != 0)
    {
        int result = num % 10;
        revNum = revNum * 10 + result;
        num = num / 10;
    }
    if (revNum == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkPallindrome(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (!checkpallindrom(arr[i]))
            return false;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<checkPallindrome(arr,n);
}