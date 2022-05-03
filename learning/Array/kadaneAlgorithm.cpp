/*created by :
Ayush Goel

*/
#include <bits/stdc++.h>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//function for max subarray sum 
int kadaneAlgo(int arr[],int n){
  
  //global sum that stores the  Final result
  int ans=0;
  //Local sum that stores sum  element by element ;
  
  
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    ans= max(sum,ans);
    sum = max(sum,0);
    
  }
  return ans;
  
}

int main(){

 int n;
 cin>>n;
 
 int arr[n];
 
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 
 cout << kadaneAlgo(arr,n);
  return 0;
}
 

/*notes :
ranges :
-10e9<int <10e9
-10e12< long int <10e12
-10e18< long int <10e18
INT_MAX ,INT_MIN= keyword used 
1LL -  used to implicit type conversion


Modulo :
add - (a+b)%M=[(a%M)+(b%M)]%M;
multiply- (a*b)%M = [(a%M)*(b%M)]%M;
subtract -(a-b)%M  = [(a%M)-(b%M)+M]%M;
divide - (a/b)%M = [(a%M)*(b)^-1 ]%M;

precomputation:{for multipule queries}
1. array storing before the queries start 
2. Hashing to store the count 

prefix sum :
use  1 - indexing (input starts in a[1 ] not a[0]for easy handling)
1D - p[i]=p[i-1]+a[i];
2D - p[i][j]= a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1] */