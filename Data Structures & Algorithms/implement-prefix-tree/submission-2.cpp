class PrefixTree {
public:
    bool leaf;
    PrefixTree* child[26];
    PrefixTree() {
        leaf=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
    
    void insert(string word) {
        PrefixTree* curr=this;
        for(auto c:word){
            int index = c - 'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new PrefixTree();

            }
            curr=curr->child[index];
        }
        curr->leaf=true;
    }
    
    bool search(string word) {
        PrefixTree* curr=this;
        for(auto c:word){
            int index = c - 'a';
            if(curr->child[index]==nullptr){
                return false;

            }
             curr=curr->child[index];
        }
        return curr->leaf;
    }
    
    bool startsWith(string prefix) {
         PrefixTree* curr=this;
        for(auto c:prefix){
            int index = c - 'a';
            if(curr->child[index]==nullptr){
                return false;

            }
             curr=curr->child[index];
        }
        return true;
    }
};
