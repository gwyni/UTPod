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
Song::Song(string sgArtist, string sgTitle, int sgSize){
    artist=sgArtist;
    title=sgTitle;
    size=sgSize;
}
void Song::setArtist(string sgArtist) {
    artist=sgArtist;
}
void Song::setTitle(string sgArtist, string sgTitle) {
    artist=sgArtist;
    title=sgTitle;
}
void Song::setSize(string sgArtist, string sgTitle, int sgSize) {
    artist=sgArtist;
    title=sgTitle;
    size=sgSize;
}
bool Song::operator >(Song const &rhs){
    if(artist<rhs.artist){
        return false;
    }
    if (artist>rhs.artist){
        return true;
    }
    if ((artist==rhs.artist) && (title>rhs.title)){
        return true;
    }
    if((artist==rhs.artist) && (title==rhs.title) && (size>rhs.size)){
        return true;
    }
    return false;
}
bool Song::operator <(Song const &rhs){
    if(artist>rhs.artist){
        return false;
    }
    if (artist<rhs.artist){
        return true;
    }
    if ((artist==rhs.artist) && (title<rhs.title)){
        return true;
    }
    if((artist==rhs.artist) && (title==rhs.title) && (size<rhs.size)){
        return true;
    }
    return false;
}

bool Song::operator ==(Song const &rhs)
{
    return (artist == rhs.artist &&
            title == rhs.title &&
            size == rhs.size);
}

#endif
