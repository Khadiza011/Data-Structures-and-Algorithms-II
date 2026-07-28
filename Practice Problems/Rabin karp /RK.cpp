#include<iostream>
#include<string>

using namespace std;

string removeSpace(string s){
   string text="";

   for(char c:s){
    if(c != ' '){
        text= text+c;
    }
   }
  return text;
}

int main(){

string text,pattern;

cout<<"Network Log: ";
getline(cin,text);

text= removeSpace(text);

cout<<"Suspicious Token: ";
getline(cin,pattern);

int n = text.length();
int m = pattern.length();

int p=0,t=0;    //pattern hash(p)  text window hash(t)

for(int i=0;i<m;i++){
    p = p + pattern[i];
    t = t + text[i];
}

 p = p%100;
 t = t%100;

 cout<<endl;
 cout<< "Pattern Hash = "<<p<<endl;
 cout<<endl;

 int c=0;

 for(int i=0;i<=n-m;i++){
    if(p==t){
        bool match =true;
        for(int j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                match=false;
                break;
            }
        }

        if(match){
            cout<<"Position "<<i<<": Hash Match -> Verified"<<endl;
            c++;
        }else{
             cout<<"Position "<<i<<": Hash Match -> Rejected (Collision)"<<endl;
        }
    }

    if(i<n-m){
        t=(t-text[i]+text[i+m])%100;

        if(t<0){
            t=t+100;
        }
    }
 }

 cout<<endl;
 cout<<"Total Valid Occurrences = "<<c;
}
