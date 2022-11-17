class TrieNode{
    
    public :
          TrieNode* arr[26] = {0};
          bool flag = false;
          bool contain(char ch){
              return arr[ch-'a'];
          }
          void put(char ch){
               TrieNode* newNode = new TrieNode();
               arr[ch-'a'] = newNode;
          }
         TrieNode*  getNext(char ch){
              return arr[ch-'a'];
          }
          void setFlag(){
              flag = true;
          }
          bool getFlag(){
              return flag;
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
        }
        temp->setFlag();
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->contain(word[i])){
                temp = temp->getNext(word[i]);
            }
            else return false;
        }
        
        return temp->getFlag();
    }
    
    bool startsWith(string word) {
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->contain(word[i])){
                temp = temp->getNext(word[i]);
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */