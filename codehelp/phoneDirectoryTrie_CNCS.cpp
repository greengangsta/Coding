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
      Trie() {
          root = new TrieNode('\0'); 
      }

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


};

void printSuggestions(TrieNode* curr, vector<string> &ans_temp, string prefix) {

      if (curr->isTerminal) {
          ans_temp.push_back(prefix); 
      }

      for (int i = 0; i < 26; i++) {
          TrieNode* next= curr->children[i]; 
          
          if (next != NULL) {
              prefix += next->data;
              printSuggestions(next, ans_temp, prefix);
              prefix.pop_back();  
              
          }
      }
}
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* trie = new Trie();
    for (int i = 0; i < contactList.size(); i++) {
        trie->insert(contactList[i]); 
    }
    vector<vector<string>> ans; 
    TrieNode* prev = trie->root; 
    string prefix = ""; 
    for (int i = 0; i < queryStr.length(); i++) {
        char ch = queryStr[i]; 
        vector<string> ans_temp; 
        prefix += ch;
        TrieNode* curr = prev->children[ch  - 'a'];
        if (!curr) {
            break; 
        }
        printSuggestions(curr, ans_temp, prefix);
 
        ans.push_back(ans_temp); 
        prev = curr;
        ans_temp.clear(); 
    }

    return ans; 
}
