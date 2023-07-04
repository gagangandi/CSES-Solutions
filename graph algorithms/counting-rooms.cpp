#include<iostream>
using namespace std;
void dfs(char **arr,int i,int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m || arr[i][j]!='.')
    {
        return;
    }
    arr[i][j]=',';
    dfs(arr,i,j-1,n,m);
    dfs(arr,i,j+1,n,m);
    dfs(arr,i-1,j,n,m);
    dfs(arr,i+1,j,n,m);
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char **arr;
    arr = (char **)malloc(sizeof(char *) * n);
    for(int i=0;i<n;i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * m);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int rooms=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='.')
            {
                rooms++;
                dfs(arr,i,j,n,m);
            }
        }
    }
    cout<<rooms<<endl;
}