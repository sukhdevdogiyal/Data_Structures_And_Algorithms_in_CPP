// Rat in a Maze
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool issafe(int x,int y,int n,vector<vector<int>> &maze,vector<vector<int>> &visited)
{
    if (x<n&&y<n&&x>=0&&y>=0&&visited[x][y]==0&&maze[x][y]==1)
    {
        return true;
    }
    return false;
    
}
void findPath(vector<vector<int>> &maze,vector<vector<int>> &visited,string path,int n,int x,int y,vector<string> &ans)
{
    // base case
    if (x==n-1&&y==n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down
    int newx = x+1;
    int newy = y;
    if (issafe(newx,newy,n,maze,visited))
    {
        path.push_back('D');
        findPath(maze,visited,path,n,newx,newy,ans);
        path.pop_back();
    }
    
    // left
    newx = x;
    newy = y-1;
    if (issafe(newx,newy,n,maze,visited))
    {
        path.push_back('L');
        findPath(maze,visited,path,n,newx,newy,ans);
        path.pop_back();
    }
    
    // Right
    newx = x;
    newy = y+1;
    if (issafe(newx,newy,n,maze,visited))
    {
        path.push_back('R');
        findPath(maze,visited,path,n,newx,newy,ans);
        path.pop_back();
    }
    
    // Up
    newx = x-1;
    newy = y;
    if (issafe(newx,newy,n,maze,visited))
    {
        path.push_back('U');
        findPath(maze,visited,path,n,newx,newy,ans);
        path.pop_back();
    }
    visited[x][y]=0;
    
    
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    vector<vector<int>> visited = maze;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            visited[i][j]=0;
        }
        
    }
    vector<string>ans;
    string path;
    findPath(maze,visited,path,maze.size(),0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    cout << "GFG Q. :- Rat in a Raze " << endl;
    cout << "Input :- " << endl;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    vector<string>ans=ratInMaze(maze);
    cout<<"Output :- ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
