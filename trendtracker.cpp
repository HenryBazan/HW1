#include "trendtracker.h"
#include <algorithm>

//initializing a Trendtracker constructor, no definition.
//Trendtracker::Trendtracker()
//{}

void Trendtracker::insert(string ht)
{
    if (popularity(ht) == -1) 
    {
        Entry entry;
        entry.hashtag = ht;
        entry.pop = 0;
        E.push_back(entry);
    }
};

int Trendtracker::size()
{
    return E.size();
};

void Trendtracker::tweeted(string ht)
{
    for (auto& entry : E)
    {
        if (entry.hashtag == ht)
        {
            entry.pop++;
            return;
        }
    }
};

int Trendtracker::popularity(string name)
{
    for (const auto& entry : E)
    {
        if (entry.hashtag == name)
        {
            return entry.pop;
        }
    }
    return -1;
};

string Trendtracker::top_trend()
{
    if(E.empty())
    {
        return "";
    }
    auto maxEntry = max_element(E.begin(), E.end(), [](const Entry& a, const Entry& b) 
    {
        return a.pop < b.pop;
    });
    return maxEntry->hashtag;
};

void Trendtracker::top_three_trends(vector<string> &T)
{
    sort(E.begin(), E.end(), [](const Entry& a, const Entry& b)
    {
        return a.pop > b.pop;
    });

    T.clear();
    for (int i = 0; i < min(3, static_cast<int>(E.size())); i++)
    {
        T.push_back(E[i].hashtag);
    }
};

void Trendtracker::remove(string ht)
{
    E.erase(remove_if(E.begin(), E.end(), [ht](const Entry& entry)
    {
        return entry.hashtag == ht;
    }), 
    E.end());
};

void Trendtracker::top_k_trends(vector<string> &T, int k)
{
    sort(E.begin(), E.end(), [](const Entry& a, const Entry& b)
    {
        return a.pop > b.pop;
    });
};