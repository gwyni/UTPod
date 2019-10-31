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
        SongNode* newNode = new SongNode(); //allocate space
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
        if (i->s==s){ //check if first element should be deleted, next song is now first
            songs = i->next;
            delete(i);
            return SUCCESS;
        }
        else if((i->next->s==s) && (i->next->next==NULL)){ //check if last song should be deleted, current song now is last
            deleteThis=i->next;
            i->next = NULL;
            delete(deleteThis);
            return SUCCESS;
        }
        else if ((i->next->s==s)&&(i->next->next!=NULL)){ //if the next song should be deleted, current song has to point to 2 places ahead
            deleteThis=i->next;
            i->next = i->next->next;
            delete(deleteThis);
            return SUCCESS;
        }
    }
    return NOT_FOUND;
}
void UtPod::shuffle() {
    int count = 0;
    for(SongNode* i = songs; i != NULL; i = i->next){ //count number of song nodes
        count++;
    }
    if (count != 0){
        SongNode *temp = songs;
        SongNode *shuffled;
        SongNode tempNode;
        for(SongNode* i = songs; i != NULL; i = i->next){
            for(SongNode* j = songs; j != NULL; j = j->next) {
                shuffled = songs;
                int randomNode = rand() % count;
                for (int r = 0; r < randomNode; r++) {
                    shuffled = shuffled->next; //move to the random location
                }
                tempNode.s = temp->s; //move temp values into shuffled list
                temp->s = shuffled->s;
                shuffled->s = tempNode.s;
            }
        }
    }


}
void UtPod::showSongList() {
    SongNode* i;
    for(i = songs; i != NULL; i = i->next){
        cout << i->s.getArtist() << ", " << i->s.getTitle() << ", " <<i->s.getSize() <<endl;
    }
}
void UtPod::sortSongList(){
    SongNode *sg1=songs;
    SongNode *sg2=songs;
    if (sg1==NULL){
        return;}
    if((sg1->next)==NULL){
        return;}
    for(sg1=sg1; sg1!=NULL;sg1=sg1->next){
        for(sg2=sg1;sg2!=NULL;sg2=sg2->next){
            if((sg1->s) > (sg2->s)){
                Song temp=sg1->s;
                sg1->s=sg2->s;
                sg2->s=temp;
            }
        }
    }
}
void UtPod::clearMemory() {
    SongNode *i=songs;
    for(i=songs; i !=NULL;i=i->next){
        delete i;
    }
    songs=NULL;
}
int UtPod::getRemainingMemory() {
    SongNode* i;
    int remainingMem = 0;
    for(i = songs; i != NULL; i = i->next){
        remainingMem += i->s.getSize();
    }
    remainingMem=getTotalMemory()-remainingMem;
    return remainingMem;
}
UtPod::~UtPod() {

}
