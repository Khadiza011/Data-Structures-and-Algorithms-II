#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rnk;

void init(int n) {
    parent.resize(n);
    rnk.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx == ry) {
        cout << "Both elements are already in the same set.\n";
        return;
    }

    if (rnk[rx] < rnk[ry]) {
        swap(rx, ry);
    }

    parent[ry] = rx;

    if (rnk[rx] == rnk[ry]) {
        rnk[rx]++;
    }

    cout << "Union operation completed.\n";
}

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    init(n);

    int choice;

    do {
        cout << "\n========== Disjoint Set Menu ==========\n";
        cout << "1. Union\n";
        cout << "2. Find (Check Same Set)\n";
        cout << "3. Display Parent Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            int x, y;
            cout << "Enter two elements to union: ";
            cin >> x >> y;

            if(x >= 0 && x < n && y >= 0 && y < n)
                unite(x, y);
            else
                cout << "Invalid element.\n";

            break;
        }

        case 2: {
            int x, y;
            cout << "Enter two elements to check: ";
            cin >> x >> y;

            if(x >= 0 && x < n && y >= 0 && y < n){
                if(find(x) == find(y))
                    cout << x << " and " << y << " are in the same set.\n";
                else
                    cout << x << " and " << y << " are in different sets.\n";
            }
            else{
                cout << "Invalid element.\n";
            }

            break;
        }

        case 3: {
            cout << "Parent Array:\n";
            for(int i = 0; i < n; i++){
                cout << "Parent[" << i << "] = " << parent[i] << endl;
            }
            break;
        }

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 4);

    return 0;
}
