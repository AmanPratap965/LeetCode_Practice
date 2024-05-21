struct TrieNode{
        TrieNode*links[2];
        bool containKeys(int bit){
            return links[bit]!=NULL;
        }
        TrieNode*get(int bit){
            return links[bit];

        }
        void put(int bit,TrieNode*node){
            links[bit]=node;
        }
};


    class Trie{
        TrieNode*root;
        public:
        Trie(){
            root=new TrieNode();
        }
        void insert(int num){
            TrieNode*node=root;
                for(int i=31;i>=0;i--){
                    int bit=(num>>i)&1;
                    if(!node->containKeys(bit)){
                        node->put(bit,new TrieNode());
                    }
                    node=node->get(bit);
                }
        }
        int getMax(int num){
            TrieNode*node=root;
            int maxNum=0;
            for(int i=31;i>=0;i--){
                    int bit=(num>>i)&1;
                    if(node->containKeys(1-bit)){
                        maxNum=maxNum | (1<<i);
                        node=node->get(1-bit);
                    }else{
                        node=node->get(bit);
                    }
                    
                }
                return maxNum;
        }
    };
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxx=0;
        for(auto &it:nums)trie.insert(it);
        for(auto &it:nums){
            maxx=max(maxx,trie.getMax(it));
        }
        return maxx;
    }
};