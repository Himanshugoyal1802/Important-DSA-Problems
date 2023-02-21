/*

        TC - N
        SC - 1

Code:

int myAtoi(string s) {
    if(s.size()==0)return 0;
    int i=0;
    while(i<s.size() && s[i] == ' '){
        i++;
    }
    s = s.substr(i);
    int sign = 1;
    long ans = 0;
    if(s[0]=='-')sign = -1;
    int min = INT_MIN, max = INT_MAX;
    if(i = (s[0]=='+'||s[0]=='-') ? 1 : 0);
    while(i<s.size()){
        if(s[i] == ' ' || !isdigit(s[i]))break;
        ans = ans*10 + (s[i]-'0');
        if(sign == -1 && -1*ans < min)return min;
        if(sign == 1 && ans>max)return max;
        i++;
    }
    return sign*ans;
}

*/