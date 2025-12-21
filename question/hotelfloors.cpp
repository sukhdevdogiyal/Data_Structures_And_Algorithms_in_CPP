#include <iostream>
#include <vector>
using namespace std;
int hotelBookings(vector<string> queries)
{
   
    int coins=0;
    vector<bool> booking(261, false);
    for (int i = 0; i < queries.size(); i++)
    {
        string str=queries[i];
        if (str[0]=='+'&&booking[str[1]-'0'+str[2]-'A'+1]==false)
        {
            coins++;
            booking[str[1]-'0'+str[2]-'A'+1]=true;
            
        }
        if(str[0]=='-')
        {
            booking[str[1]-'0'+str[2]-'A'+1]=false;
        }
        
    }
    return coins;

}
int main(int argc, char const *argv[])
{
    //vector<string> querie = {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E","+1A"};
    //vector<string> querie = {"+0A" ,"+0B", "+0C"};
    vector<string> querie;
    //vector<string> querie = {"+3C", "+2B", "+7K", "-2B", "+6C", "-3C", "+5S"};
    cout<< hotelBookings(querie);
    
    vector<string> queries = {"+0A" ,"+0A", "+0C"};
    int coins=0;
    for(int i=0;i<queries.size();i++)
    {
        if(queries[i][0]=='+')
        {
            coins++;
        }
    }
    cout<<coins;
    
    return 0;
}
