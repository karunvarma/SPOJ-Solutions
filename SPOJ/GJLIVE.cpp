#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[10], sum = 0;
    for (int i = 0; i < 10; ++i)
	{
        cin>>array[i];
        sum += array[i];
        if (sum >= 100)
		{
            if (sum - 100 <= 100 - (sum-array[i]))
			cout<<sum<<endl;
            else
            cout<<sum-array[i]<<endl;
            return 0;
        }
    }
    cout<<sum<<endl;
    return 0;
}
