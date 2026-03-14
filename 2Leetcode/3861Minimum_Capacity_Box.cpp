// 3861. Minimum Capacity Box
// https://leetcode.com/problems/minimum-capacity-box/description/
// https://leetcode.com/contest/weekly-contest-492/problems/minimum-capacity-box/description/
#include <iostream>
#include <vector>
using namespace std;
int minimumIndex(vector<int> &capacity, int itemSize)
{
    int ans = -1;
    int min = -1;
    for (int i = 0; i < capacity.size(); i++)
    {
        if (capacity[i] >= itemSize && (ans == -1 || capacity[i] < capacity[ans]))
        {
            ans = i;
        }
    }
    return ans;
}
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> c = {1, 5, 3, 7};
    int s = 3;
    cout << "capacity : ";
    print(c);
    cout << "Item Size : " << s << endl;
    cout << "Minimum Index for this capacity = " << minimumIndex(c, s) << endl;

    cout << endl;
    c = {3, 5, 4, 3};
    s = 3;
    cout << "capacity : ";
    print(c);
    cout << "Item Size : " << s << endl;
    cout << "Minimum Index for this capacity = " << minimumIndex(c, s) << endl;

    cout << endl;
    c = {4};
    s = 5;
    cout << "capacity : ";
    print(c);
    cout << "Item Size : " << s << endl;
    cout << "Minimum Index for this capacity = " << minimumIndex(c, s) << endl;
    return 0;
}
