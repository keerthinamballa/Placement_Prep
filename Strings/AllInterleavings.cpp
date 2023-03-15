// Find all interleaving of given strings
// Find all interleavings of given strings that can be formed from all the characters of the first and second string where the order of characters is preserved.


void combi(string ans, string s1, string s2, vector<string>& res){
    if(!s1.length() && !s2.length()){
        res.push_back(ans);
        return;
    }
    if(s1.length()){
        combi(ans+s1[0], s1.substr(1), s2, res);
    }
    if(s2.length()){
        combi(ans+s2[0], s1, s2.substr(1), res);
    }
}

vector<string> findInterleavings(string s1, string s2){
    vector<string> res;
    if(!s1.length() && !s2.length()) return res;
    combi("", s1, s2, res);
    return res;
}

