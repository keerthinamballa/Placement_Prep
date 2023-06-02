// Print all Possible Decodings of a given Digit Sequence
// Given the numeric string str, where 1 represents ‘a’, 2 represents ‘b’, …, 26 represents ‘z’, the task is to print all possible alphabetical strings that can be obtained from str.


void find(string i, string o){
    if(i.empty()){
        cout<<o<<endl;
        return;
    }
    char c1 = i[0] - '0' + a - 1;
    int b = stoi(i.substr(0, 2));
    char c2 = b  + 'a' - 1;
    find(i.substr(1), o+c1);
    if(b >= 10 && b <= 26){
        find(i.substr(2), o+c2);
    }
}

void printSunstrings(string s){
    find(s, "");
}

// Time Complexity : exponential


