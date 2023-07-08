#define _CRT_SECURE_NO_WARNNGS
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int row,col;
struct point 
{
    int x,y,s;
};
int solve(vector<vector<int>>& mat,int x,int y)
{
    int steps;
    vector<vector<int>> vis(row,vector<int>(col,0));
    queue<point> Q;
        int d
        Q.push()

}
int main()
{
    freopen("LB.txt","r",stdin);
    int t;
    cin>>t;
    vector<vector<int>> mat;

    while(t--)
    {
        cin>>row>>col;
    for(int i=0;i<row;i++)
    {  
         for(int j=0;j<col;j++)
        {   int tmp;
             cin>>tmp;
             mat[i][j]=tmp;
        }
    }

    int sx,sy;

    cin>>sx>>sy;
    cout<<"STEPS: "<<solve(mat,sx-1,sy-1)<<endl;
    mat.clear();
    }

}