#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node * left;
    struct node * right;
} node;


int main()
{
    int T;
   
    FILE* originalStdout = stdin;
    FILE* file = freopen("testLCA.txt","r",stdin);
    cin>>T; 
    for(int i=0;i<T;i++)
    {   
        string n; // number of nodes
        cin>>n;
        int N=stoi(n);    
        map<int,vector<int>> mapof;
        
        for(int i=0;i<N;i++)
        {
              
              string ste;
              getline(cin,ste);
              cout<<" str : "<<ste<<endl;
        }

            



    }
    vector<vector<int>> a{{1,3,3,4,4,4},{1,3,3,4,4,4},{1,3,3,4,4,4},{1,3,3,4,4,4},{1,3,3,4,4,4},{1,3,3,4,4,4}};
    vector<vector<int>> b(a.size(),vector<int>(a.size(),0));
    for(int i=0;i<b.size();i++)
    {
        for(int h=0;h<b[i].size();h++)
        {
            b[i][h]=a[h][i];
        }
    }

    for(int i=0;i<b.size();i++)
    {
        for(int h=0;h<b[i].size();h++)
        {
            cout<<b[i][h]<<" ";
        }
        cout<<endl;
    }

string str;
str.append("abc");
int a1 =100;
    

    string st;
    st= to_string(a1);
        int a2;
        a2= stoi(st);

        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int>> min_heap;
            max_heap.top();
            if(!max_heap.empty())
            {
                binary_search()
            }
    return 0;
}

