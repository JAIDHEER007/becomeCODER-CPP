# 345. Reverse Vowels of a String

### <a href=https://leetcode.com/problems/reverse-vowels-of-a-string/>Link to LeetCode</a>

---

Given a string ```s```, reverse only all the vowels in the string and return it.<br>
The vowels are ```'a'```, ```'e'```, ```'i'```, ```'o'```, and ```'u'```, and they can appear in **both cases**.

## Example 1
```
Input: s = "hello"
Output: "holle"
```
## Example 2
```
Input: s = "leetcode"
Output: "leotcede"
```

## Constraints
* ```1 <= s.length <= 3 * 10⁵```
* ```s consist of printable ASCII characters.```

## Fucntion to check if a character is Vowel or Not
```
bool isVowel(char ch){
    return ((ch == 'a')||(ch == 'e')||(ch == 'i')||(ch == 'o')||(ch == 'u'))||
           ((ch == 'A')||(ch == 'E')||(ch == 'I')||(ch == 'O')||(ch == 'U'));
}
```

## Naive Approach
Storing all vowels in to a string by traversing the input string for the first time<br>
Now traverse the input string again and if we encounter a Vowel, we will replace it with character that is<br>
taken from last of the vowels string<br>
```
string reverseVowels(string s) {
    string vowels = "";
    for(char ch:s)
        if(isVowel(ch)) vowels += ch; 
     
    string::reverse_iterator itr = vowels.rbegin(); 
    for(char &ch:s)
        if(isVowel(ch)) ch = *(itr++); 
    return s; 
}
```

## Using 2 Pointers Approach 
```
string reverseVowels(string s) {
    int start = 0; 
    int end = s.length() - 1; 
        
    while(start < end){
        if(!isVowel(s[start])) ++start; 
        else if(!isVowel(s[end])) --end; 
        else swap(s[start++], s[end--]);
    }
       
    return s; 
}
```

## Useful Links

* <a href=https://www.cplusplus.com/reference/string/string/rend/> Reverse Iterator for a String</a>


