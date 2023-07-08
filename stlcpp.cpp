#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
void putValues( vector< vector<int> >& );
void getValues( vector< vector<int> >& );
 
int R,C;


int main()
{  cout<<"------------"<<endl;
    cin>>R>>C;
    vector<vector<int>> vec(R,vector<int>(C,0));

    putValues(vec);
    cout<<"------------"<<endl;
   
    getValues(vec);
    cout<<"------------"<<endl;
   
    cout<< "GCD "<<__gcd(R,C)<<endl;

    vector <int> vect{1,2,2,3,4,5,6};

    next_permutation(vect.begin(),vect.end());
    next_permutation(vec.at(0).begin(),vec.at(0).end());
   //__next_permutation(vect.begin(),vect.end(),NULL);
   cout<<"------------"<<endl;
   
    getValues(vec);
    
    for(auto it:vect)
    {
        cout<<(it)<<endl;
    }

    next_permutation(vect.begin(),vect.end());
    cout<<"--------------"<<endl;
        for(auto it:vect)
    {
        cout<<(it)<<endl;
    }

        return 0;
   } 
void putValues(vector<vector<int>>& vec)
{
    for(int i=0;i<R;i++)
    { 
        for(int j=0;j<C;j++)
        {
              cin>> vec[i][j];      
        }   
    }

}
void getValues(vector<vector<int>>& vec)
{
    for(int i=0;i<R;i++)
    { 
        for(int j=0;j<C;j++)
        {
              cout<< vec[i][j]<<" ";      
        }   
        cout<<endl;
    }

}
