#include<iostream>
#include<string>
using namespace std;

int main(){

    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int d = 256, q = 101, p = 0, t = 0;

    int n = text.length();
    int m = pattern.length();

    int h = 1;

    // Step 1: Compute h = (d^(m-1)) % q
    for(int i = 0; i < m - 1; i++){
        h = (h * d) % q;
    }

    // Step 2: Compute initial hash values
    for(int i = 0; i < m; i++){
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Step 3: Slide the pattern over the text
    for(int i = 0; i <= n - m; i++){

        if(p == t){
            bool match = true;

            for(int j = 0; j < m; j++){
                if(text[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }

            if(match){
                cout << "Pattern found at index: " << i << endl;
            }
        }

        if(i < n - m){
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if(t < 0){
                t += q;
            }
        }
    }

    return 0;
}
