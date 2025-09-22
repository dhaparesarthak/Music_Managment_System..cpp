#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Song {
private:
    string title;
    string artist;
    string album;
    int duration; // in seconds
    string genre;

public:
    // Constructor
    Song(const string& t, const string& a, const string& al, int d, const string& g)
        : title(t), artist(a), album(al), duration(d), genre(g) {}

    // Method to display song details
    void display() const {
        cout << "|Title: " << title << "            \t           |\n"
            << "|Artist: " << artist << "            \t           |\n"
            << "|Album: " << album << "              \t           |\n"
            << "|Duration: " << duration << " seconds           \t   |\n"
            << "|Genre: " << genre << "           \t           |\n";
    }

    // Getter for title
    string getTitle() const {
        return title;
    }
};

class Playlist {
private:
    string name;
    vector<Song> songs;

public:
    // Constructor
    Playlist(const string& n) : name(n) {}

    // Method to add a song
    void addSong(const Song& song) {
        songs.push_back(song);
    }

    // Method to remove a song by title
    void removeSong(const string& title) {
        auto it = remove_if(songs.begin(), songs.end(),
            [&title](const Song& s) { return s.getTitle() == title; });
        songs.erase(it, songs.end());
    }

    // Method to display the playlist
    void displayPlaylist() const {
        cout << "+------------------------------------------+\n";
        cout << "|           Loading Your Playlist          |\n";
        cout << "+------------------------------------------+\n";
        cout << "|Playlist: " << name << "               |\n";
        cout << "+------------------------------------------+\n";
        if (songs.empty()) {
            cout << "|The playlist is empty.                    |\n";
            cout << "+------------------------------------------+\n";
        } else {
            for (const auto& song : songs) {
                song.display();
                cout << "+------------------------------------------+\n";
            }
        }
    }
};

int main() {
    cout << "+------------------------------------------+\n";
    cout << "|     Welcome to Music Management System   |\n";
    cout << "+------------------------------------------+\n";
    Playlist myPlaylist("My Favorite Songs");

    int choice;
    do {
        cout << "|1. Add Song                               |\n"
             << "|2. Remove Song                            |\n"
             << "|3. Display Playlist                       |\n"
             << "|4. Exit                                   |\n"
             << "+------------------------------------------+\n\n";
        cout << "|-->Enter your choice:";
        cin >> choice;        
        cout << "\n+------------------------------------------+\n\n";

        cin.ignore(); // Clear the newline character from input buffer

        if (choice == 1) {
            string title, artist, album, genre;
            int duration;

            cout << "|-->Enter song title: ";
            getline(cin, title) ;
            cout << "|-->Enter artist: ";
            getline(cin, artist);
            cout << "|-->Enter album: ";
            getline(cin, album);
            cout << "|-->Enter duration (seconds): ";
            cin >> duration;
            cin.ignore(); // Clear the newline character
            cout << "|-->Enter genre: ";
            getline(cin, genre);

            myPlaylist.addSong(Song(title, artist, album, duration, genre));
            cout << "\n+------------------------------------------+";
            cout << "\n|Song added successfully!                  |\n";
            cout << "+------------------------------------------+\n";

        } else if (choice == 2) {
            string title;
            cout << "|-->Enter song title to remove: ";


            getline(cin, title);
            myPlaylist.removeSong(title);
            cout << "\n+------------------------------------------+\n";
            cout << "|Song removed successfully!                |\n";
            cout << "+------------------------------------------+\n";

        } else if (choice == 3) {
            myPlaylist.displayPlaylist();
        }

    } while (choice != 4);
    cout << " ^-^     ^-^     ^-^     ^-^     ^-^     ^-^\n";
    cout << "('-')   ('-')   ('-')   ('-')   ('-')   ('-')\n";
    cout << "<| |>   <| |>   <| |>   <| |>   <| |>   <| |>\n";
    cout << "+------------------------------------------+\n";
    cout << "|Exiting the program. Goodbye!:)           |\n";
    cout << "+------------------------------------------+\n\n";
    return 0;
}
