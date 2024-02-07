class TrieNode {

    public :
        char data; 
        TrieNode* children[26]; 
        bool isTerminal; 

         TrieNode(char ch) {
         data = ch;
         for (int i = 0; i < 26; i++) {
            children[i] = NULL; 
         }
         isTerminal = false; 
      }
}; 

class Trie {

     

      public :

      TrieNode* root; 

      /** Initialize your data structure here. */
      Trie() {
          root = new TrieNode('\0'); 
      }

  /** Inserts a word into the trie. */
      void insertUtil(TrieNode* root, string word) {

        if (word.length() == 0) {
            root->isTerminal = true; 
            return; 
        }

          int index= word[0] - 'a';
          TrieNode * child = NULL; 
          if (root->children[index] == NULL) {
               root->children[index] = new TrieNode(word[0]);
          }
          child = root->children[index]; 
          word = word.substr(1); 
          insertUtil(child, word);

      }
      void insert(string word) {
          insertUtil(root, word); 
      }

      /** Returns if the word is in the trie. */

      bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal; 
        }
        int index= word[0] - 'a';
        if (root->children[index] == NULL) {
               return false; 
        }
        TrieNode * child = root->children[index]; 
        word = word.substr(1); 
        return searchUtil(child, word);

      }
      bool search(string word) {
          return searchUtil(root, word); 
      }

      bool prefixUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true; 
        }
        int index= word[0] - 'a';
        if (root->children[index] == NULL) {
               return false; 
        }
        TrieNode * child = root->children[index]; 
        word = word.substr(1); 
        return prefixUtil(child, word);

      }

      /** Returns if there is any word in the trie that starts with the given
       * prefix. */
      bool startsWith(string prefix) {
          return prefixUtil(root, prefix); 
      }
};
