class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedText; //this will store the final justified text
        int B= maxWidth; //this stores number of remaining slots in each line of text
        auto iter=words.begin();
        string curLine;
        while(iter!=words.end())
        {
            string word=*iter;
            int wordlen=word.length();
            bool PadBefore=B!=maxWidth;//if we are starting with a new line or not
            
            if(maxWidth == B && wordlen==B)
            {//case when a single word exactly fits into the statement
                justifiedText.emplace_back(word);
                iter++;
            }
            
            else if(wordlen + (PadBefore?1:0) > B)
            {//when the current word cant be adjusted in the given line and must be shiftd to the next line. hence adjustment of this very line needs to occur
                curLine=adjustSpaces(curLine, maxWidth, false);
                justifiedText.emplace_back(curLine);
                B=maxWidth;
                curLine.clear();                    
            }
            
            else
            {//word can be appended
                string toAppend;
                toAppend += PadBefore?" ":"";
                toAppend+=word;
                curLine+=toAppend;
                B-=toAppend.length();
                iter++;
            }
        }
        if(!curLine.empty()) //last line waala case
            justifiedText.emplace_back(adjustSpaces(curLine,maxWidth, true));
        return justifiedText;
    }
    
    string adjustSpaces(string text, int maxWidth, bool lastLine)
    {
    // Case 1 : lastline, no extra space between words
        if (lastLine) 
        {
            int curWidth = text.length();
            while (curWidth < maxWidth) 
            {
                text += ' ';
                curWidth++;
            }
            return text;
        }
        // Case 2 : not lastline, spaces to be distributed evenly
        // Any extra space to be distrubuted starting from left
        auto words = split(text);
        // Case 2.1 : only 1 word in text
        // This is same as adjusting spaces for last line where last line has only 1 word
        if (words.size() == 1)
            return adjustSpaces(text, maxWidth, true);
        // Case 2.2 : multiple words in text
        string formatted;
        int numGaps = words.size() - 1;
        int curWidth = text.length();
        int numSpaces = maxWidth - (curWidth - numGaps);
        int equalSpaces = numSpaces / numGaps;
        int extraSpaces = numSpaces % numGaps;
        formatted += words[0];
        for (int i = 1; i < words.size(); ++i) {
            formatted += string(equalSpaces, ' ');
            if (extraSpaces) {
                formatted += ' ';
                --extraSpaces;
            }
        formatted += words[i];
    }
    return formatted;
}
    
    vector<string> split(string str)
    {
        vector<string> ans;
        while (!str.empty()) {
            auto pos = str.find(' ');
            if (pos == string::npos) // last segment
            {
                ans.emplace_back(str);
                return ans;
            }
            ans.emplace_back(str.substr(0, pos));
            str.erase(0, pos + 1);
        }
        return ans;
    }
};
