//
// Created by gdoug on 10/26/2019.
//

#ifndef UNTITLED5_SONG_H
#define UNTITLED5_SONG_H

#endif

#include <iostream>
#include <string>

using namespace std;

class Song
{
private:
    string artist;
    string title;
    int size;
public:
    Song();
    Song(string a, string t, int sz);
    void setArtist(string a);
    void setTitle(string a, string t);
    void setSize(string a, string, int sz);

    string getArtist() const
    {  return artist;  }
    string getTitle() const
    {  return title;  }
    int setSize() const
    {  return size;  }

    bool operator >(Song const &rhs);
    bool operator==(Song const &rhs);
};

