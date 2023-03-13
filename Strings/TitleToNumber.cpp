// 171. Excel Sheet Column Number
// Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.


int titleToNumber(string s){
    int res  = 0;
    for(char c : s){
        int d = c - 'A' + 1;
        res = res*26 + d;
    }
    return res;
}

