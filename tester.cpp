#include <algorithm>

// Constructor
Trendtracker::Trendtracker() {}

// Inserts a hashtag into the Trendtracker
void Trendtracker::insert(string ht) {
    // Check if the hashtag already exists
    if (popularity(ht) == -1) {
        Entry entry;
        entry.hashtag = ht;
        entry.pop = 0;
        E.push_back(entry);
    }
}

// Returns the number of hashtags in the Trendtracker
int Trendtracker::size() {
    return E.size();
}

// Adds 1 to the total number of times a hashtag has been tweeted
void Trendtracker::tweeted(string ht) {
    for (auto& entry : E) {
        if (entry.hashtag == ht) {
            entry.pop++;
            return; // Found the hashtag, no need to continue searching
        }
    }
}

// Returns the number of times a hashtag has been tweeted
int Trendtracker::popularity(string name) {
    for (const auto& entry : E) {
        if (entry.hashtag == name) {
            return entry.pop;
        }
    }
    return -1; // Hashtag not found
}

// Returns the most-tweeted hashtag
string Trendtracker::top_trend() {
    if (E.empty()) {
        return "";
    }

    auto maxEntry = max_element(E.begin(), E.end(), [](const Entry& a, const Entry& b) 
    {
        return a.pop < b.pop;
        });

    return maxEntry->hashtag;
}

// Fills the provided vector with the 3 most-tweeted hashtags
void Trendtracker::top_three_trends(vector<string>& T) {
    sort(E.begin(), E.end(), [](const Entry& a, const Entry& b) {
        return a.pop > b.pop;
        });

    T.clear();
    for (int i = 0; i < min(3, static_cast<int>(E.size())); i++) {
        T.push_back(E[i].hashtag);
    }
}

// Remove the given hashtag from the trendtracker
void Trendtracker::remove(string ht) {
    E.erase(remove_if(E.begin(), E.end(), [ht](const Entry& entry) {
        return entry.hashtag == ht;
        }), E.end());
}

// Fills the provided vector with the k most-tweeted hashtags
void Trendtracker::top_k_trends(vector<string>& T, int k) {
    sort(E.begin(), E.end(), [](const Entry& a, const Entry& b) {
        return a.pop > b.pop;
        });

    T.clear();
    for (int i = 0; i < min(k, static_cast<int>(E.size())); i++) {
        T.push_back(E[i].hashtag);
    }
}
