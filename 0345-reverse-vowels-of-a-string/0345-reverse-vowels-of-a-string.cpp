class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char ,int>mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        int l=0;
        int h =s.length()-1;
        while(l<=h){
            if(mp[s[l]]==1 && mp[s[h]]==1) {
                swap(s[l],s[h]);
                l++;h--;}
            else if(mp[s[h]]==1){ 
                l++;
            }else if(mp[s[l]]==1){
                h--;
            }else{
                l++;
                h--;
            }
        }
        return s;
    }
};