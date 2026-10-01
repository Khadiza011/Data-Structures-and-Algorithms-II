#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Item
{
    int weight;
    int value;
};


// Sort based on value per weight
bool compare(Item a, Item b)
{
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;

    return ratio1 > ratio2;
}


int main()
{
    int n;

    cin >> n;


    vector<Item> items(n);


    // Taking item information
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].weight;
        cin >> items[i].value;
    }


    int thieves;

    cin >> thieves;


    vector<int> capacity(thieves);


    for(int i = 0; i < thieves; i++)
    {
        cin >> capacity[i];
    }



    // Sort items according to value/weight ratio
    sort(
        items.begin(),
        items.end(),
        compare
    );



    double totalValue = 0;



    // Process each thief
    for(int i = 0; i < thieves; i++)
    {
        int remaining = capacity[i];


        for(int j = 0; j < n && remaining > 0; j++)
        {
            if(items[j].weight <= remaining)
            {
                // Take complete item
                totalValue += items[j].value;

                remaining -= items[j].weight;
            }
            else
            {
                // Take fraction of item
                totalValue +=
                ((double)items[j].value / items[j].weight)
                * remaining;

                remaining = 0;
            }
        }
    }



    cout << totalValue;


    return 0;
}
