#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool compareNumbers(string &str1, string &str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
       return true;
    if (n2 < n1)
       return false;
 
    // If lengths are same
    for (int i=0; i<n1; i++)
    {
       if (str1[i] < str2[i])
          return true;
       if (str1[i] > str2[i])
          return false;
    }
 
    return false;
}

void sortLargeNumbers(vector<string>&v , int n)
{
   sort(v.begin(), v.end(), compareNumbers);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        
        string s;
        cin>>s;
        v.push_back(s);
    
    
    
    
    }
    
    sortLargeNumbers(v, n);
    for(auto it : v)
    {
        
        cout << it <<"\n";
    }
    return 0;
}
