#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cout << "enter the value if n" << endl;
    cin >> n;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not prime number" << endl;
            break;
        }
    }
    if (i >= n)
    {
        cout << "prime Number" << endl;
    }
    return 0;
}