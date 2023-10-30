/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/



class Solution {
public:
    bool isVowel(char &ch){
        return(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
               ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }

    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if((isVowel(s[i])) && (isVowel(s[j]))){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i])) i++;
            else if(!isVowel(s[j])) j--;
        }
        return s;
    }
};