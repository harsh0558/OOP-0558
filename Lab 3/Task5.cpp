#include <iostream>
using namespace std;

class MusicPlayer{
private:
    string playlist[100];
    string currentlyPlayingSong;
    int songCount;
public:
    MusicPlayer(){
        songCount = 0;

        for(int i=0;i<100;i++){
            playlist[i] = "";
        }
    }
    
    void addSong(string song){
        if(songCount < 100){
            playlist[songCount] = song;
            songCount++;
        }
        else{
            cout << "Playlist is full" << endl;
        }
    }

    void playSong(string song){
        bool songFound = false;
        for(int i=0;i<100;i++){
            if(playlist[i] == song){
                songFound = true;
                currentlyPlayingSong = song;
                cout << "Playing " << song << endl;
                break;
            }
        }

        if(!songFound){
            cout << "Song not found in the playlist" << endl;
        }
    }

    void showPlaylist(){
        cout << "Playlist:" << endl;
        for(int i=0;i<100;i++){
            if(playlist[i] != ""){
                cout << playlist[i] << endl;
            }
        }
    }

    void removeSong(string song){
        bool songFound = false;
        for(int i=0;i<100;i++){
            if(playlist[i] == song){
                songFound = true;
                playlist[i] = "";
                songCount--;
                cout << song << " removed from the playlist" << endl;
                break;
            }
        }

        if(!songFound){
            cout << "Song not found in the playlist" << endl;
        }
    }
    
};

int main(){
    MusicPlayer player;
    player.addSong("Song 1");
    player.addSong("Song 2");
    player.addSong("Song 3");
    player.addSong("Song 4");
    player.addSong("Song 5");
    player.showPlaylist();
    player.playSong("Song 3");
    player.removeSong("Song 3");
    player.showPlaylist();
    player.playSong("Song 3");

    return 0;
}