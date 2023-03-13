// 168. Excel Sheet Column Title
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.


string columnTitle(int n){
    string res;
    while(n){
        int index = (n-1)%26;
        res = char(index + 'A') + res;
        n = (n-1)/26;
    }
    return res;
}



