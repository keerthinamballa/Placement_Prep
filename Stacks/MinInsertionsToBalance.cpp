// 1541. Minimum Insertions to Balance a Parentheses String
// Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
// -> Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
// -> Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
// In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.
// You can insert the characters '(' and ')' at any position of the string to balance it if needed.
// Return the minimum number of insertions needed to make s balanced.


int minInsertions(string s){
    int n = s.length();
    stack<char> st;
    int count = 0;
    for(int i=0; i<n;){
        if(s[i] == '('){
            st.push(s[i]);
            i++;
        }
        else{
            if(st.empty()){
                if(i+1 < n && s[i+1] == ')'){
                    count++;
                    i+=2;
                }
                else{
                    count+=2;
                    i++;
                }
            }
            else{
                if(i+1 < n && s[i+1] == ')'){
                    i+=2;
                }
                else{
                    count++;
                    i++;
                }
                st.pop();
            }
            while(!st.empty()){
                count+=2;
                st.pop();
            }
            return count;
        }
    }
}

// Time Complexity : O(n)
// Space Complexity : O(n)


