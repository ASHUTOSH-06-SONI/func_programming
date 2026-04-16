#include <iostream>
#include<string>
#include<vector>
#include<queue>
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
    vector<int> res = a;
    for(int i=0; i<res.size();i++){
        res[i] = (i%2==0)? 2*res[i]:res[i]; 
    }
    return res;
}
// traverse, if any num is more then 10 then divide it by 10 and its rem also
int sumDigits(vector<int>& a){
    int sum =0;
    for(int x:a){
        if(x>=10){
            sum+=x/10;
            sum+=x%10;
        }else{
            sum+=x;
        }
    }return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   //  int t; cin >> t;
 //   while(t--){
      //  solve();
//}g
    string s; 
    cout<<"Enter some shit (number daalo but in 1 unit)"<<'\n';
    cin>>s;
    vector<int> digits = toDigits(s);
    cout<< "Ascending: "<<'\n';
    for(int i:digits){
        cout<<i<<" ";
    }cout<<'\n';
    vector<int> revDigits = toDigitsRev(s);
    cout<<"Descending: "<<'\n';
    for(int i : revDigits){
        cout << i << " ";
    }
    cout<<'\n';
    vector<int> doublethemup = doubletheevens(revDigits);
    cout<<"Double the nums"<<'\n';
    for(int i: doublethemup){
        cout<<i<<" ";
    }cout<<'\n';
    int total = sumDigits(doublethemup);
    cout << "Final sum: " << total << '\n';
}



