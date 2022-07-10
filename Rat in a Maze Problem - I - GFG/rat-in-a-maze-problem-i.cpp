// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findPaths(int i , int j ,int n ,vector<vector<int>> &m,vector<string>&ans,string &path ){
        
        if(i<0 || j<0 || i>=n ||j>=n || m[i][j] ==0) return;
        
        if(i==n-1 && j== n-1 ) 
        { ans.push_back(path);
        return;
        }    
        
        m[i][j]=0;
        path+='U';
        findPaths(i-1,j,n,m,ans,path);
        path.pop_back();
        path+='D';
        findPaths(i+1,j,n,m,ans,path);
         path.pop_back();
        path+='L';
        findPaths(i,j-1,n,m,ans,path);
         path.pop_back();
        path+='R';
        findPaths(i,j+1,n,m,ans,path);
         path.pop_back();
           m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        string path ="";
        findPaths(0 ,0, n,m,ans,path);
      return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends