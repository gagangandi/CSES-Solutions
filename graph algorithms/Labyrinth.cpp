#include<bits/stdc++.h>
using namespace std;

void printpath(vector<vector<char>>&grid, vector<vector<pair<int,int>>>&parent)
{
    int n=grid.size();
    int m=grid[0].size();

    vector<char>st;

    int endrow,endcol;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='B')
            {
                endrow=i;
                endcol=j;
                break;
            }
        }
    }

    int r=endrow;
    int c=endcol;
    while(r!=-1 && c!=-1)
    {
        int parr=parent[r][c].first;
        int parc=parent[r][c].second;

        if(r-parr==1)
        {
            st.push_back('D');
        }
        else if(r-parr==-1)
        {
            st.push_back('U');
        }
        else
        {
            if(c-parc==1)
            {
                st.push_back('R');
            }
            else
            {
                st.push_back('L');
            }
        }

        r=parr;
        c=parc;
    }

    for(int i=st.size()-2;i>=0;i--)
    {
        cout<<st[i];
    }
    cout<<endl;
}

int bfs(int r, int c, vector<vector<char>>&grid,vector<vector<int>>&vis, vector<vector<pair<int,int>>>&parent)
{
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},0});
    vis[r][c]=1;

    int delr[4]={-1,0,1,0};
    int delc[4]={0,1,0,-1};

    while(q.size()>0)
    {
        int nr=q.front().first.first;
        int nc=q.front().first.second;
        int d=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int newr=nr+delr[i];
            int newc=nc+delc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m
            && grid[newr][newc]=='.' && !vis[newr][newc])
            {
                parent[newr][newc]={nr,nc};
                vis[newr][newc]=1;
                q.push({{newr,newc},d+1});
            }

            else if(newr>=0 && newr<n && newc>=0 && newc<m
            && grid[newr][newc]=='B' && !vis[newr][newc])
            {
                parent[newr][newc]={nr,nc};
                vis[newr][newc]=1;
                q.push({{newr,newc},d+1});
                return d+1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>vis(n,vector<int>(m));
    int startrow,startcol;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A')
            {
                startrow=i;
                startcol=j;
                break;
            }
        }
    }

    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));
    parent[startrow][startcol]={-1,-1};
    int ans=bfs(startrow,startcol,grid,vis,parent);
    if(ans)
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        printpath(grid,parent);
    }
    else
    {
        cout<<"NO"<<endl;
    }
}