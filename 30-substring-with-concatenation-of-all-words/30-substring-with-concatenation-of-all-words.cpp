class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ans;
        
        if(words.size()==0)
        {
            return ans;
        }
        
        if(s.size()==0)
        {
            return ans;
        }
        
        int size_of_one_word = words[0].size();
        
        //cout<<size_of_one_word<<"\n";
        
        int sizeOfTheSubstringToBeExamined = words.size()*size_of_one_word;
        
        //cout<<sizeOfTheSubstringToBeExamined<<"\n";
        
        if(s.size()<sizeOfTheSubstringToBeExamined)
        {
            return ans;
        }
        
        
        unordered_map<string,int> wordMap,aux;
        
        for(auto w : words)
        {
            aux[w]++;
        }
        
        
        for(int i=0;i<=s.size()-sizeOfTheSubstringToBeExamined;i++)
        {
            //cout<<i<<" : ";
            string sub = s.substr(i,sizeOfTheSubstringToBeExamined);
            
            //cout<<sub<<"\n";
            
            bool flag = true;
            
            wordMap = aux; 
            
            for(int j=0;j<sub.size();j+=size_of_one_word)
            {
                string subOfsub = sub.substr(j,size_of_one_word);
                
                //cout<<subOfsub<<"\n";
                
                if(wordMap.find(subOfsub)!=wordMap.end() && wordMap[subOfsub]>0)
                {
                    wordMap[subOfsub]--;
                }else{
                    //cout<<"false for this word : "<<subOfsub<<"\n";
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};