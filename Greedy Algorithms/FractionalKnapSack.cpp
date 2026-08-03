#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(Item a, Item b){
    double x1 = (double) a.value/a.weight;
    double x2 = (double) b.value/b.weight;
    return x1>x2;
}

double knapsack(int capacity,vector<Item> &items){
    sort(items.begin(),items.end(),compare);

    for(auto &it: items){
        cout<<it.value<<" "<<it.weight<<endl;
    }

    double total = 0.0;

    for(auto it:items){
        if(capacity>= it.weight){
            capacity = capacity - it.weight;
            total = total + it.value;
        }else{
            double tempWeight= (double) capacity/it.weight;
            total = total + it.value*tempWeight;
            break;
        }
    }
    return total;
}



int main(){
    int n, capacity;
    cout<<"n?";
    cin>>n;

    vector<Item> items(n);

    cout<<"value, item:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"item "<<i+1<<":"<<endl;
        cin>>items[i].value>>items[i].weight;
    }
    cout<<"capacity?";
    cin>>capacity;

    double result = knapsack(capacity,items);
    cout<<"total: "<<result;

return 0;
}
