#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y,l;
};

int solve(vector<vector<int>> & mat, vector<vector<int>> & vis,int x,int y,int len);
int M,N;
bool isLeft( int val)
{
	if(val== 1 || val== 3 ||val== 6 ||val== 7)
	return true;
	return false;
}
bool isRight( int val)
{
	if(val== 1 || val== 3 ||val== 5 ||val== 4)
	return true;
	return false;
}

bool isTop( int val)
{
	if(val== 1 || val== 2 ||val== 4 ||val== 7)
	return true;

	return false;
}
bool isDown( int val)
{
	if(val== 1 || val== 2 ||val== 5 ||val== 6)
	return true;
	return false;
}
bool isValid(int x,int y)
{
	if(x>=0 && x<N && y>=0 && y<M)
	return true;
	return false;
}

int main() {

	int t,n,m,x,y,L;
	freopen("endoscopy.txt","r",stdin);
    cin>>t;
	vector<vector<int>> mat(1001,vector<int>(1001,0));
	vector<vector<int>> vis(1001,vector<int>(1001,0));
	
	while(t--)
	{
		cin>>n>>m;
		M=m;
		N=n;
		cin>>x>>y;
		cin>>L;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>mat[i][j];
			}
		}
		int count=0;
		count = solve(mat,vis,x,y,L);
		cout<<count<<endl;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=0;
                mat[i][j]=0;
            }
        }

	}
}

int solve( vector<vector<int>>& mat, vector<vector<int>>& vis,int x,int y,int len)
{
	if(len ==0 )
	return 0;

	if(mat[x][y]==0)
	{
		return 0;  // edge case
	}

	queue <point> q;
	point p;

	p.x=x;
	p.y=y;
	p.l=len;
	int count =0;
	//count++;

	q.push(p);
	vis[p.x][p.y]=1;
	
	while(!q.empty())
	{
		point p1;
		p1=q.front();
		q.pop();
	//	cout<< " POINT :" <<p1.x<<p1.y<<endl;
		int val;
		val=mat[p1.x][p1.y];
		vis[p1.x][p1.y]=1;
		count++;

		if(p1.l>1)
		{
			if(isLeft(val))
			{ 
				int n_val;
					if( isValid(p1.x,p1.y-1)  && vis[p1.x][p1.y-1]==0)
					{
						n_val=mat[p1.x][p1.y-1];
						if(n_val!=0)
						{
							if(isRight(n_val))
							{	point p2;
								p2.x=p1.x;
								p2.y=p1.y-1;
								p2.l=p1.l-1;
								q.push(p2);
                                		vis[p2.x][p2.y]=1;

							}
						}
					}
			}

			if(isRight(val))
			{ 
				int n_val;
					if( isValid(p1.x,p1.y+1)  && vis[p1.x][p1.y+1]==0)
					{
						n_val=mat[p1.x][p1.y+1];
						if(n_val!=0)
						{
							if(isLeft(n_val))
							{	point p2;
								p2.x=p1.x;
								p2.y=p1.y+1;
								p2.l=p1.l-1;
								q.push(p2);
                                                                		vis[p2.x][p2.y]=1;

							}
						}
					}
			}			
			if(isTop(val))
			{ 
				int n_val;
					if( isValid(p1.x-1,p1.y)  && vis[p1.x-1][p1.y]==0)
					{
						n_val=mat[p1.x-1][p1.y];
						if(n_val!=0)
						{
							if(isDown(n_val))
							{	point p2;
								p2.x=p1.x-1;
								p2.y=p1.y;
								p2.l=p1.l-1;
								q.push(p2);
                                                                		vis[p2.x][p2.y]=1;

							}
						}
					}
			}	
			
			if(isDown(val))
			{ 
				int n_val;
					if( isValid(p1.x+1,p1.y)  && vis[p1.x+1][p1.y]==0)
					{
						n_val=mat[p1.x+1][p1.y];
                        
                        
						if(n_val!=0)
						{
							if(isTop(n_val))
							{	point p2;
								p2.x=p1.x+1;
								p2.y=p1.y;
								p2.l=p1.l-1;
								q.push(p2);
                                		vis[p2.x][p2.y]=1;
							
                         }
						}
					}
			}
		} //if			
	}  //while
	return count;

}




