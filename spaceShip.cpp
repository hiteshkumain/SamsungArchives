#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct point 
{
 int row,col;
};
int ROW;

int max_coin=0;

bool isValid(int y)
{
    if(y<5 && y>=0)
    return true;
    return false;

}
void solve(   vector<vector<int>> &space, int row,int col,int coin,bool bomb,int range)
{
            if(row==-1)
            {
                //update max coins
                max_coin= max(max_coin,coin);
                return ;
            }

// else
            for(int i=-1;i<=1;i++) // all three paths 
            {
                    if(isValid(col+i))
                    {       
                        int val;
                        val=space[row][col+i];
                        //cout<<"R-"<<row<<" C-"<<col+i<<"-- "<<val<<endl;
                        if(val==1 || val==0)
                        {
                                if(bomb==false)
                                    {
                                        solve(space,row-1,col+i,coin+val,bomb,range);
                                    }
                                else
                                    {
                                        solve(space,row-1,col+i,coin+val,bomb,range-1);
                                    }
                        }
                        else //val == 2 i.e enemy
                        {

                           if(bomb==true)
                           {
                                if(range>0)
                                {

                                    solve(space,row-1,col+i,coin,bomb,range-1);
                                }

                           }
                           else // bomb nahi fata
                           {
                                    bomb= true;
                                    solve(space,row-1,col+i,coin,bomb,5);
                           }     




                        }

                    }
            }

            return;
  }

int main()
{
    int t;
    int R,C;
    vector<vector<int>> space(100,vector<int>(5,0));

    freopen("spaceShip.txt","r",stdin);

    cin>>t;
    while(t--)
    {       int temp;
            cin>>R;
            ROW=R;
            max_coin=0;
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<5;j++)
                {
                    cin>>temp;
                    space[i][j]=(temp);
                }
            }
            
            solve(space,R-1,2,0,false,0);
            cout<<max_coin<<endl;
            max_coin=0;
            space.clear();
    }

}



