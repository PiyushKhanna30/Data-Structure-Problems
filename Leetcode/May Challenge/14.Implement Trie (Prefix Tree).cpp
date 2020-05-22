/**
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
**/
class TrieNode
{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data=data;
        children=new TrieNode *[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root=new TrieNode('\0');
    }
    void insertWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }
    bool searchWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return searchWord(child,word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertWord(root,word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(root,word);
    }
    bool startsWithH(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return startsWithH(child,word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithH(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
