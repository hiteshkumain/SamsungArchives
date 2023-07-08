#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left=NULL;
    node* right=NULL;
    node(int v)
    {
        val=v;
    }
};
int minD,maxD;
void mindis(node *rt,int l)
{
    if(rt==NULL)
    return;

    if(rt->left==NULL && rt->left==NULL)
    {
        //update min
        minD=min(minD,l);
        maxD=max(maxD,l);
        return ;
    }
    else
    {
            mindis(rt->left,l+1);
            mindis(rt->right,l+1);
            
    }
}
node* createTree(map<int, vector<int>>&mp, int val)
{           
                node *rt = new node(val);
                
                int size;
                size = mp[val].size();
                if(size==0)
                {
                    return rt;
                }
                if(size==1)
                {

                    rt->left=createTree(mp,mp[val].at(0));

                }
                if(size==2)
                {

                    rt->left=createTree(mp,mp[val].at(0));
                    rt->right=createTree(mp,mp[val].at(1));
                }
                return rt;
}
        
        
        bool findHeight(node* rt, int val)
        {           if(rt==NULL)
                    return 0;


                    if(rt->val==val)
                    {
                        return true;
                    }
                    else
                    {
                        return findHeight(rt->left,val) || findHeight(rt->right,val);
                        
                    }
                    return false;
        }
int main()
{
        map<int,vector<int>> mp;
        mp[1].push_back(2);
        mp[1].push_back(3);

        mp[2].push_back(4);
        mp[2].push_back(5);
        
        mp[3].push_back(6);
        mp[3].push_back(7);
        
        mp[4].push_back(8);
        mp[8].push_back(9);
        mp[9].push_back(10);
        mp[10].push_back(12);
         
         node * rt;
         int val;
         rt=createTree(mp,1);
         while(true)
         {
            cin>>val;
            cout<<"STATUS: "<<findHeight(rt,val)<<endl;
            minD=INT_MAX;
            maxD=INT_MIN;
                mindis(rt,1);
            cout<<"Min Dis Leaf : "<< minD<<endl;
            cout<<"Max Dis Leaf : "<< maxD<<endl;

            mp[12].push_back(13);
            mp[12].push_back(14);
            rt=createTree(mp,1);
            mindis(rt,1);    
            cout<<"Min Dis Leaf : "<< minD<<endl;        
            cout<<"Max Dis Leaf : "<< maxD<<endl;

// adding new node
         }

}