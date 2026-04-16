#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<numeric>
#include<algorithm>
using namespace std;
#define ll long long

void getDigit(int N, vector<int>& result){
    if(N==0){
        return;
    }
    int r = N % 10;
    getDigit(N/10,result);
    result.push_back(r);
}

vector<int> toDigits(string s){
    // this was my initial approach, ignore any stupidity lol
    // 1234 % 10 -> 4  
    // 1234-4 % 10^2 -> 3
    // 1230-3*10^1 % 10^3 -> 2
    // 1200-2*10^2 % 10^4 -> 1   
    // now insert in stack {1,2,3,4}
    vector<int> result;
    for(char c:s){
        result.push_back(c-'0');
    }
    return result;
}
vector<int> toDigitsRev(string s){
    deque<int> dq;
    for (char c : s) {
        dq.push_front(c -'0');   
    }
    return vector<int>(dq.begin(),dq.end());
}
vector<int> doubletheevens(const vector<int>& a){
    vector<int> res(a.size());
    int i = 0;
    transform(a.begin(), a.end(), res.begin(), [&](int x){
        return (i++ % 2 == 1) ? 2 * x : x;
    });
    return res;
}
// traverse, if any num is more then 10 then divide it by 10 and its rem also
int sumDigits(const vector<int>& a){
    return accumulate(a.begin(),a.end(),0,[](int acc,int x){
        if(x>=10){
            return acc + (x/10)+(x%10);
        }return acc+x;
    });
}
bool validate(const string& s){
    int total = sumDigits(doubletheevens(toDigitsRev(s)));
    return (total%10==0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; 
    cout<<"Enter some shit (number daalo but in 1 unit)"<<'\n';
    cin>>s;
    if(validate(s)){
        cout<<"Valid"<<'\n';
    }else{
        cout<<"Invalid"<<'\n';
    }
}



