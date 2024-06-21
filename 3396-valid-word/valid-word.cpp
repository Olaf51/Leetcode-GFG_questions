class Solution {
public:
    
    bool isvowel(char ch){
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' 
      || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    else{
        return false;
    }
}
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        int num=0;
        int v=0;
        int c=0;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='0' && ch<='9'){
                num++;
            }
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            if(isvowel(ch)){
                v++;
            }
            else{
                c++;
            }
            }
           
        }
        if(num+v+c==word.size() && v>0 && c>0){
            return true;
        }
        return false;
    }
};