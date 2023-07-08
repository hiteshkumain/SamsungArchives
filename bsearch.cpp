#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

vector<int> vec;
vec.push_back(12);
vec.push_back(121);
vec.push_back(10);
vec.push_back(142);
vec.push_back(12);
vec.push_back(122);
vec.push_back(42);
vec.push_back(22);
vec.push_back(4);
vec.push_back(2);
vec.push_back(1);
sort(vec.begin(),vec.end());

int found= binary_search(vec.begin(),vec.end(), 10);
cout<<found<<endl;
found= binary_search(vec.begin(),vec.end(), 11212);
cout<<found<<endl;
cout<< *min_element(vec.begin(),vec.end());

string str="ABCDE";
string str2="ABEDC";
}