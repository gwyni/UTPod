//
// Created by gdoug on 10/26/2019.
//

#ifndef UNTITLED5_SONG_H
#define UNTITLED5_SONG_H

#include <iostream>
#include "Song.h"
#include <string>

using namespace std;

Song::Song(){
    artist="";
    title="";
    size=0;
}
Song::Song(string a, string t, int sz){
    artist=a;
    title=t;
    size=sz;
}
void Song::setArtist(string a) {
    artist=a;
}
void Song::setTitle(string a, string t) {
    artist=a;
    title=t;
}
void Song::setSize(string a, string t, int sz) {
    artist=a;
    title=t;
    size=sz;
}
bool Song::operator >(Song const &rhs)
{
    if (title>rhs.title || artist >rhs.artist){
        return (title>rhs.title);

    }
    else{
        return false;
    }
}

bool Song::operator ==(Song const &rhs)
{
    return (artist == rhs.artist &&
            title == rhs.title &&
            size == rhs.size);
}

#endif
