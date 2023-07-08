/*
Mr. Kim has to deliver refrigerators to N customers. From the office, 
he is going to visit all the customers and then return to his home. 
Each location of the office, his home, and the customers is given in the 
form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . 
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|,
 where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. 
 The locations of the office, his home, and the customers are all distinct. 
 You should plan an optimal way to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; 
the number of the customers is in the range of 5 to 10. Write a program that, 
starting at the office, finds a (the) shortest path visiting all the customers 
and returning to his home. Your program only have to report the distance of a (the) shortest path.

Constraints
5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.
Input
You are given 10 test cases. Each test case consists of two lines; 
the first line has N, the number of the customers, 
and the following line enumerates the locations of the office, 
Mr. Kim’s home, and the customers in sequence. 
Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.
Output
Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. 
Each line looks like ‘#x answer’ where x is the index of a test case. 
‘#x’ and ‘answer’ are separated by a space.
I/O Example
Input (20 lines in total. In the first test case,
the locations of the office and the home are (0, 0) and (100, 100) respectively, 
and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)

5 ← Starting test case #1
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6 ← Starting test case #2
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10 ← Starting test case #3
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
Output (10 lines in total)
#1 200
#2 304
#3 366
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct point{
    int x,y;
};

int min_cost;
int N;



int discal(point p,point d);

void solve(vector<point>& cust,vector<int>& vis,point p,point end, int cost, int custN);
int main()
{
        int t;
        freopen("kim.txt","r",stdin);
        cin>>t;
        while(t--)
        {

                int ox,oy,hx,hy,n;
                cin>>n;
                N=n;
                vector<point> cust(n);
                vector<int> vis(n);
                cin>>ox>>oy>>hx>>hy;
                point start,end;
                start.x=ox;
                start.y=oy;
                end.x=hx;
                end.y=hy;

                for(int i=0;i<n;i++)
                {
                      cin>>cust[i].x;
                      cin>>cust[i].y;  
                      vis[i]=0;
                }
                min_cost=INT_MAX;
                solve(cust,vis,start,end,0,n); //cost
                cout<<" #COST : "<<min_cost<<endl;

        }
}

void solve(vector<point>& cust,vector<int>& vis,point p,point end, int cost, int custN)
{
        if(custN==0)
        {
            // go to home and update min
            int dis=discal(p,end);
            min_cost=min(min_cost, cost+dis);
            return;            
        }
        if(min_cost<cost)
        {
            return; //prune
        }

        for(int i=0;i<N;i++)
        {
            if(vis[i]!=1)
            {       
                point  c;
                c=cust[i];


                    int dis;
                    dis=discal(p,c);
                    vis[i]=1;

                    solve(cust,vis,c,end,cost+dis,custN-1);

                    vis[i]=0; //backtrack

            }
        }




}

int discal(point p,point d)
{
    return abs(p.x-d.x) + abs(p.y-d.y);
}