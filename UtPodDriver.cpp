/* utPod_driver.cpp
Gwyneth Douglas
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    cout << "add songs..." <<endl;
    Song s1("High School Musical", "Gotta go my own way", 7);
    int result = t.addSong(s1);
    Song s2("High School Musical", "Breaking Free", 5);
    result = t.addSong(s2);
    Song s3("Justin Bieber", "Fall", 6);
    result = t.addSong(s3);
    Song s4("Beyonce", "Best Thing I Never Had", 4);
    result = t.addSong(s4);
    Song s5("Beatles", "Hey Jude1", 25);
    result = t.addSong(s5);
    Song s6("Saweetie", "My Type3", 100);
    result = t.addSong(s6);
    Song s7("Saweetie", "My Type2", 99);
    result = t.addSong(s7);
    Song s8("Beatles", "Hey Jude1", 29);
    result = t.addSong(s8);
    t.showSongList();  // print added songs

    cout<< "shuffling...  "<< endl;  // test shuffling
    t.shuffle();
    t.showSongList();

    cout<< "sorting...  "<< endl; // test sorting
    t.sortSongList();
    t.showSongList();

    t.clearMemory();

    t.showSongList();

    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();


    result = t.addSong(s3);
    cout << "result = " << result << endl;

    result = t.addSong(s3);
    cout << "result = " << result << endl;

    cout <<"list after adding 2 of the same song:" <<endl;
    t.showSongList();

    cout << "removing one instance of Fall by Justin Bieber" <<endl;
    t.removeSong(s3);
    t.showSongList();


    result = t.addSong(s4);
    cout << "result = " << result << endl;

    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    result = t.addSong(s6);
    cout << "add result (should be -1) = " << result << endl;

    t.showSongList();
    result = t.removeSong(s6);
    cout << "remove result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s6);
    cout << "remove result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s6);
    cout << "remove result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s6);
    cout << "remove result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s6);
    cout << "remove result = " << result << endl;
    t.showSongList();

    cout << "remove result (should be -2) = " << result << endl;

    result = t.addSong(s6);
    result = t.addSong(s7);
    result = t.addSong(s8);
    t.showSongList();  // print added songs


    cout << "memory = " << t.getRemainingMemory() << endl;
    t.showSongList();


    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();


    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout<< "get remaining memory... "<< endl;
    cout << "memory = " << t.getRemainingMemory() << endl;
    cout<< "clearing memory... "<< endl;
    cout<< "get remaining memory... "<< endl;
    t.clearMemory();
    cout << "memory = " << t.getRemainingMemory() << endl;

}
