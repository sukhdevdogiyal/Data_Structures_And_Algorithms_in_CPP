// 1518. Water Bottles
#include <iostream>
using namespace std;
int numWaterBottles(int numBottles, int numExchange)
{
    int ans = numBottles;
    int rem = 0;
    int temp = 0;
    while (rem + numBottles >= numExchange)
    {
        temp = numBottles;
        numBottles = (numBottles + rem) / numExchange;
        rem = (temp + rem) % numExchange;
        ans += numBottles;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    cout << "Number of water bottles you can drink : " << numWaterBottles(9, 3) << endl;
    cout << "Number of water bottles you can drink : " << numWaterBottles(15, 4) << endl;
    return 0;
}
