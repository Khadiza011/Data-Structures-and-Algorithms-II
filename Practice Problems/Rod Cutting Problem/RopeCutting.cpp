#include<iostream>
#include<algorithm>

using namespace std;

int main(){

int l;
cout<<"ENTER ROPE LENGTH: ";
cin>>l;

int n;
cout<<"ENTER PIECES NUMBER: ";
cin>>n;

int length[n];
cout<<"ENTER LENGTHS: ";
for(int i=0;i<n;i++){
    cin>>length[i];
}

int price[n];
cout<<"ENTER PRICES OF LENGTHS: ";
for(int i=0;i<n;i++){
    cin>>price[i];
}

int dp[n+1][l+1];

for(int i=0;i<=n;i++){
    for(int j=0;j<=l;j++){
    dp[i][j]=0;
  }
}

for(int i=1;i<=n;i++){
    for(int j=1;j<=l;j++){
    if(length[i-1]<=j){
        dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
    }else{
       dp[i][j]=dp[i-1][j];
    }
  }
}

    cout<<"Maximum Obtainable Profit = "<<dp[n][l];

}
