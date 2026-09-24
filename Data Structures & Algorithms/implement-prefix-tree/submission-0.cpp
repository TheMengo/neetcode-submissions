class TrieNode{
    public:
        // Key: Character, Value: The node to the character
        unordered_map<char, TrieNode*> child;
        bool endOfWord = false;
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* cur = root;

        for(char c : word){
            // If it character does not exist than we have to create a new hash entry
            if(cur->child.find(c) == cur->child.end()){
                cur->child[c] = new TrieNode();
            }

            // If it already exists in the trie
            cur = cur->child[c];
        }
        cur->endOfWord = true;
        
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word){
            //if the next character cannot be found, return false
            if(cur->child.find(c) == cur->child.end()){
                return false;
            }
            cur = cur->child[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix){
            if(cur->child.find(c) == cur->child.end()){
                return false;
            }
            cur = cur->child[c];
        }
        return true;
        
    }
};
