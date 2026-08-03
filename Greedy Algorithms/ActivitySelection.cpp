#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int selection(vector<int> &start, vector<int> &finish){
    vector<vector<int>> a;
    for(int i=0;i<start.size();i++){
        a.push_back({start[i],finish[i]});
    }

    sort(a.begin(),a.end(),compare); //explicit

    cout<<"After sorting: "<<endl;
    for(auto x: a){
        cout<<"{"<<x[0]<<","<<x[1]<<"}"<<endl;
    }

    int j=0,count=1;
    vector<vector<int>> selected;
    selected.push_back(a[0]);


    for(int i=1;i<a.size();i++){
        if(a[i][0]>=a[j][1]){
            count++;
            selected.push_back(a[i]);
            j=i;
        }
    }
    cout<<"Selected Activities: "<<endl;
    for(auto p: selected){
        cout<<"{"<<p[0]<<","<<p[1]<<"}"<<endl;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++)
        cin >> finish[i];

    int res = selection(start, finish);

    cout << "Total activity: " << res << endl;

    return 0;
}                   create README.md fot githubeverything is okay just change the hardcode input into user input
