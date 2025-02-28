#include <iostream>
#include <vector>
using namespace std;

class Level {
private:
    int levelNumber;
    string difficulty;

public:
    Level(int num, string diff) {
        levelNumber = num;
        difficulty = diff;
    }

    void details() {
        cout << "Level " << levelNumber << " - Difficulty: " << difficulty << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    vector<Level> levels;
    int levelCount; 

public:
    VideoGame(string t, string g) {
        title = t;
        genre = g;
        levelCount = 0;
    }

    void addLevel(Level l) {
        levels.push_back(l);
        levelCount++; 
    }

    void details() {
        cout << "Game Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Levels:" << endl;

        for (int i = 0; i < levelCount; i++) { 
            levels[i].details();
        }
        cout << endl;
    }
};

int main() {
    VideoGame game("Adventure Quest", "RPG");

    game.addLevel(Level(1, "Easy"));
    game.addLevel(Level(2, "Medium"));
    game.addLevel(Level(3, "Hard"));

    cout << "----- Game Details -----" << endl;
    game.details();

    return 0;
}
