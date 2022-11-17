class TrieNode{
     public :
    TrieNode* arr[26] ={0};
    bool flag = false;
    int countWordEqual =0;
    int countWordStart =0;
    bool contain(char ch ){
         return arr[ch-'a'];
    }
    void put(char ch){
        TrieNode* newNode = new TrieNode();
        arr[ch-'a'] = newNode;
    }
    TrieNode * getNext(char ch){
         return arr[ch-'a'];
    }
    
    void increasePrefix(){
        countWordStart++;
    }
    void increaseWord(){
         countWordEqual++;
}
    
    int getWord(){
      return countWordEqual;
    }
    int getStart(){
        return countWordStart;
    }
    void decreasePrefix(){
        countWordStart--;
}
     void decreaseWord(){
        countWordEqual--;
}
};
class Trie {
public:
   TrieNode * root ;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->contain(word[i])){
                temp->put(word[i]);
                
            }
            
            temp = temp->getNext(word[i]);
            temp->increasePrefix();
        }
        
         temp->increaseWord();
    }
    
    int countWordsEqualTo(string word) {
        TrieNode * temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->contain(word[i])){
                temp = temp->getNext(word[i]);
                
            }else{
                return 0;
            }
            
            
        }
        return temp->getWord();
    }
    
    int countWordsStartingWith(string word) {
        TrieNode * temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->contain(word[i])){
                temp = temp->getNext(word[i]);
                
            }else{
                return 0;
            }
            
            
        }
        return temp->getStart();
         
    }
    
    void erase(string word) {
        if(countWordsEqualTo(word)==0) return;
        TrieNode * temp = root;
        for(int i=0;i<word.size();i++){
               
                temp = temp->getNext(word[i]);
              temp->decreasePrefix();
  }
     temp->decreaseWord();
    
    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */