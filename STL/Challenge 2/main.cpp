// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing:\n";
    std::cout << song << std::endl; 
}

void error_rating()
{
    std::cout << "Error while processing song rating!\nTry to add it again";
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for(const auto& s: playlist)
        std::cout << s << std::endl;
    std::cout << std::endl;

    std::cout << "Current song:\n";
    std::cout << current_song << std::endl; 
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    char input{};

    // New song input
    std::string song_name;
    std::string song_artist;
    int song_rating;
    //

    display_playlist(playlist, *current_song);

    do
    {
        display_menu();
        std::cin >> input;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        input = std::toupper(input);

        switch (input)
        {
        case 'F':
            system("CLS");
            current_song = playlist.begin();
            play_current_song(*current_song);
            break;
        case 'N':
            system("CLS");
            if(++current_song == playlist.end())
                current_song = playlist.begin();
            
            play_current_song(*current_song);
            break;
        case 'P':
            system("CLS");
            if(current_song == playlist.begin())
                current_song = playlist.end();

            --current_song;
            play_current_song(*current_song);
            break;
        case 'A':
            std::cout << "Enter song name: ";
            std::getline(std::cin, song_name);
            std::cout << "Enter song artist: ";
            std::getline(std::cin, song_artist);
            
            while(true)
            {
                std::cout << "Enter song rating (1-5): ";
                if((std::cin >> song_rating) && song_rating <= 5 && song_rating > 0)
                    break;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                error_rating();
                std::cout << std::endl;
            }

            playlist.emplace(current_song, song_name, song_artist, song_rating);
            system("CLS");
            --current_song;
            play_current_song(*current_song);
            break;
        case 'L':
            system("CLS");
            display_playlist(playlist, *current_song);
            break;
        case 'Q':
            system("CLS");
            break;
        default:
            break;
        }

    } while(input != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}