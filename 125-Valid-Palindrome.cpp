class Solution {
private:
    char toLowercase(char c){
        if( (c>='a' && c<='z') || (c>='0' && c<='9') ){
            return c;
        }else{
            c = (c-'A')+'a';
        }
        return c;
    }
public:
    bool isPalindrome(string s) {
        int st = 0;
        int en = s.size()-1;
        while(st<en){
            if(isalnum(s[st]) && (isalnum(s[en]))){
                if(toLowercase(s[st++])!=toLowercase(s[en--])){
                    return 0;
                }
            }else{
                if(isalnum(s[st])==0){ st++; } 
                else if (isalnum(s[en])==0) { en--; }             
            }
        }
        return 1;    
    }
};