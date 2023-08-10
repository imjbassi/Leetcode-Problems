class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        if (s.empty() || words.empty()) {
            return result;
        }
        
        int wordLength = words[0].size();
        int totalWords = words.size();
        int windowSize = wordLength * totalWords;
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentWordCount;
            
            while (right + wordLength <= s.size()) {
                string currentWord = s.substr(right, wordLength);
                right += wordLength;
                
                if (wordCount.find(currentWord) != wordCount.end()) {
                    currentWordCount[currentWord]++;
                    count++;
                    
                    while (currentWordCount[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordLength);
                        left += wordLength;
                        currentWordCount[leftWord]--;
                        count--;
                    }
                    
                    if (count == totalWords) {
                        result.push_back(left);
                    }
                } else {
                    currentWordCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};