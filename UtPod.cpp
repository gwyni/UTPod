//
// Created by gdoug on 10/26/2019.
//

#include "UtPod.h"

UtPod::UtPod()
{
    songs= NULL;
    memSize = MAX_MEMORY;
}
UtPod::UtPod(int size){
    songs = NULL; //song list is originally empty

    if (size <=0 || size > MAX_MEMORY){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
}

int UtPod::addSong(Song const &s) {
    if (getRemainingMemory()>s.getSize()){
        SongNode* newNode = new SongNode();
        newNode -> s = s;
        newNode -> next = songs;
        songs = newNode;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}
int UtPod::removeSong(Song const &s) {
    SongNode* i;
    SongNode* deleteThis;
    for(i = songs; i != NULL; i = i->next){
        if (i->s==s){ //check if first element is song
            songs = i->next;
            delete(i);
            return SUCCESS;
        }
        else if((i->next->s==s) && (i->next->next==NULL)){ //check if last element is song
            deleteThis=i->next;
            i->next = NULL;
            delete(deleteThis);
            return SUCCESS;
        }
        else if ((i->next->s==s)&&(i->next->next!=NULL)){
            deleteThis=i->next;
            i->next = i->next->next;
            delete(deleteThis);

            return SUCCESS;
        }
    }
    return NOT_FOUND;
}
void UtPod::shuffle() {

}
void UtPod::showSongList() {
    SongNode* i;
    for(i = songs; i != NULL; i = i->next){
        cout << i->s.getArtist() << ", " << i->s.getTitle() << ", " <<i->s.getSize() <<endl;
    }

}
void UtPod::sortSongList(){

}
void UtPod::clearMemory() {

}
int UtPod::getRemainingMemory() {
    SongNode* i;
    int remainingMem = 0;
    for(i = songs; i != NULL; i = i->next){
        remainingMem += i->s.getSize();
    }
    remainingMem=getTotalMemory()-remainingMem;
//cout <<remainingMem<<endl;
    return remainingMem;
}
UtPod::~UtPod() {

}
