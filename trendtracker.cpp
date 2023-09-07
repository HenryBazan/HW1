#include "trendtracker.h"
#include <algorithm>

// Constructor: Creates a new Trendtracker tracking no hashtags.
Trendtracker::Trendtracker() {}

// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
void Trendtracker::insert(string ht) {
    bool found = false;
    for (Entry &e : E) {
        if (e.hashtag == ht) {
            found = true;
            break;
        }
    }
    if (!found) {
        Entry entry;
        entry.hashtag = ht;
        entry.pop = 0;
        E.push_back(entry);
    }
}

// Returns the number of hashtags in the Trendtracker.
int Trendtracker::size() {
    return E.size();
}

// Adds 1 to the total number times a hashtag has been tweeted.
void Trendtracker::tweeted(string ht) {
    for (Entry &e : E) {
        if (e.hashtag == ht) {
            e.pop++;
            break;
        }
    }
}

// Returns the number of times a hashtag has been tweeted.
int Trendtracker::popularity(string name) {
    for (const Entry &e : E) {
        if (e.hashtag == name) {
            return e.pop;
        }
    }
    return -1;
}

// Returns a most-tweeted hashtag.
string Trendtracker::top_trend() {
    string top;
    int maxPop = -1;
    for (const Entry &e : E) {
        if (e.pop > maxPop) {
            maxPop = e.pop;
            top = e.hashtag;
        }
    }
    return top;
}

// Fills the provided vector with the 3 most-tweeted hashtags.
void Trendtracker::top_three_trends(vector<string> &T) {
    T.clear();
    vector<Entry> sortedE = E;
    sort(sortedE.begin(), sortedE.end(), [](const Entry &a, const Entry &b) {
        return a.pop > b.pop || (a.pop == b.pop && a.hashtag < b.hashtag);
    });
    int count = min(3, static_cast<int>(sortedE.size()));
    for (int i = 0; i < count; ++i) {
        T.push_back(sortedE[i].hashtag);
    }
}

// Remove the given hashtag from the trendtracker.
void Trendtracker::remove(string ht) {
    auto it = E.begin();
    while (it != E.end()) {
        if (it->hashtag == ht) {
            it = E.erase(it);
        } else {
            ++it;
        }
    }
}

// Fills the provided vector with the k most-tweeted hashtags.
void Trendtracker::top_k_trends(vector<string> &T, int k) 
{
    T.clear();
    vector<Entry> sortedE = E;
    sort(sortedE.begin(), sortedE.end(), [](const Entry &a, const Entry &b) 
    {return a.pop > b.pop || (a.pop == b.pop && a.hashtag < b.hashtag);});
    int count = min(k, static_cast<int>(sortedE.size()));
    for (int i = 0; i < count; ++i) {
        T.push_back(sortedE[i].hashtag);
    }
}
