#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> languages(n);

    for(int i = 0; i < n; i++)
    {
        cin >> languages[i];
    }

    int m;
    cin >> m;

    vector<int> audio(m);
    vector<int> subtitle(m);

    for(int i = 0; i < m; i++)
    {
        cin >> audio[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> subtitle[i];
    }

    sort(languages.begin(), languages.end());

    int answer = 1;
    int bestAudio = -1;
    int bestSubtitle = -1;

    for(int i = 0; i < m; i++)
    {
        int audioCount =
            upper_bound(languages.begin(), languages.end(), audio[i])
            - lower_bound(languages.begin(), languages.end(), audio[i]);

        int subtitleCount =
            upper_bound(languages.begin(), languages.end(), subtitle[i])
            - lower_bound(languages.begin(), languages.end(), subtitle[i]);

        if(audioCount > bestAudio ||
          (audioCount == bestAudio && subtitleCount > bestSubtitle))
        {
            bestAudio = audioCount;
            bestSubtitle = subtitleCount;
            answer = i + 1;
        }
    }

    cout << answer;

    return 0;
}
