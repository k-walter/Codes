#include<bits/stdc++.h>
using namespace std;
typedef pair<string, int> strint; 

int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
    freopen("janeeyre.in", "r", stdin);

    int n,m,k;
    cin>>n>>m>>k;
    cin.get();

    priority_queue <strint, vector<strint>, greater<strint> > pq;
    pq.push(make_pair("Jane Eyre",k));

    while(n--){
        string input;
        getline(cin,input);

        input = input.substr(1);
        int pos = input.find("\"");
        string title = input.substr(0,pos);
        if(title>="Jane Eyre")
            continue;
        int no_pages = stoi(input.substr(pos+2));
        pq.push(make_pair(title,no_pages));
    }

    map<long int, strint> given;
    while(m--){
        long int t;
        cin>>t; cin.get();

        string input;
        getline(cin, input);

        input = input.substr(1);
        int pos = input.find("\"");
        string title = input.substr(0,pos);
        if(title>="Jane Eyre")
            continue;
        int no_pages = stoi(input.substr(pos+2));
        given.insert(pair<long int,strint>(t,make_pair(title,no_pages)));

    }

    long long int time = 0;
    while(!pq.empty()){
        auto itr = given.begin();
        while(itr!=given.end() && itr->first <= time){
            pq.push(make_pair(itr->second.first, itr->second.second));
            given.erase(given.begin());
            itr = given.begin();
        }

        strint reading = pq.top();
        pq.pop();

        time += reading.second;
        if(reading.first == "Jane Eyre"){
            cout<<time;
            break;
        }
    }

    return 0;  
}