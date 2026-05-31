class TreeNode {
    public:
    TreeNode* links[26];
    bool isEnd;

    TreeNode(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        isEnd = false;
    }
};
class PrefixTree {
public:
    TreeNode* root;
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TreeNode* node = root;
        for(int i=0;i<n;i++){
            char c = word[i];
            if(!node->links[c-'a'])
            node->links[c-'a']= new TreeNode();

            node = node->links[c-'a'];  
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TreeNode* node = root;
        for(int i=0;i<n;i++){
            char c = word[i];
            if(!node->links[c-'a'])
            return false;

            node = node->links[c-'a'];  
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TreeNode* node = root;
        for(int i=0;i<n;i++){
            char c = prefix[i];
            if(!node->links[c-'a'])
            return false;

            node = node->links[c-'a'];  
        }
        return true;
    }
};
