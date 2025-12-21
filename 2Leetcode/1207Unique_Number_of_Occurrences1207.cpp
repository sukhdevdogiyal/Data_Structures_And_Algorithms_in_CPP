// 1207. Unique Number of Occurrences
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdbool.h>
using namespace std;
bool uniqueOccurrences(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> v;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 1;
        while (i + 1 < arr.size() && arr[i] == arr[i + 1])
        {
            count++;
            i++;
        }
        v.push_back(count);
        sort(v.begin(), v.end());
        // cout<<endl;
        for (int j = 0; j < v.size() - 1; j++)
        {
            // cout<<v[j]<<" ";
            if (v[j] == v[j + 1])
            {
                return false;
            }
        }
    }

    return true;
}
main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << "Unique Number of Occurrences = " << uniqueOccurrences(arr) << endl;
    arr = {1, 2};
    cout << "Unique Number of Occurrences = " << uniqueOccurrences(arr) << endl;
    arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << "Unique Number of Occurrences = " << uniqueOccurrences(arr) << endl;
}