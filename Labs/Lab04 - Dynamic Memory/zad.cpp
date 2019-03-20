#include <iostream>
#include <cstring>
using namespace std;

class Song
{
private:
    char *title;
    int length;
    int playCount;

public:
    Song()
    {
        title = nullptr;
        length = 0;
        playCount = 0;
    }

    Song(const char* _title, int _length)
    {
        int len = strlen(_title);
        title = new char[len + 1];
        strcpy(title, _title);
        length = _length;
        playCount = 0;
    }

    Song(const Song& other)
    {
        length = other.length;
        if(other.title != nullptr)
        {
            int len = strlen(other.title);
            title = new char[len + 1];
            strcpy(title, other.title);
        }
        else
        {
            title = nullptr;
        }
        playCount = other.playCount;
    }

    Song& operator=(const Song& other)
    {
        if(this != &other)
        {
            delete title;
            length = other.length;
            if(other.title != nullptr)
            {
                int len = strlen(other.title);
                title = new char[len + 1];
                strcpy(title, other.title);
            }
            else
            {
                title = nullptr;
            }
            playCount = other.playCount;
        }
        return *this;
    }

    ~Song()
    {
        delete title;
    }

    const char* getTitle() const
    {
        return title;
    }

    int getLength() const
    {
        return length;
    }

    int getPlayCount() const
    {
        return playCount;
    }

    void play()
    {
        cout << "Now playing: " << title << endl;
        playCount++;
    }

};

class MusicPlayer
{
private:
    Song* songs;
    int capacity;
    int size;
public:
    MusicPlayer()
    {
        songs = new Song[4];
        capacity = 4;
        size = 0;
    }

    MusicPlayer(const MusicPlayer& other)
    {
        capacity = other.capacity;
        songs = new Song[capacity];
        for (size = 0; size < other.size; size++)
        {
            songs[size] = other.songs[size];
        }
    }

    ~MusicPlayer()
    {
        delete[] songs;
    }

    MusicPlayer& operator=(const MusicPlayer& other)
    {
        if(this != &other)
        {
            delete[] songs;
            capacity = other.capacity;
            songs = new Song[capacity];
            for (size = 0; size < other.size; size++)
            {
                songs[size] = other.songs[size];
            }
        }
        return *this;
    }

    void addSong(const char* title, int length)
    {
        if(size == capacity)
        {
            capacity *= 2;
            Song* temp = new Song[capacity];
            for(int i = 0; i < size; i++)
            {
                temp[i] = songs[i];
            }
            delete[] songs;
            songs = temp;
        }

        Song song(title, length);
        songs[size++] = song;
    }

    void removeSong(const char* title)
    {
        for(int i = 0; i < size; i++)
        {
            if(strcmp(songs[i].getTitle(), title) == 0)
            {
                for(int j = i+1; j < size; j++)
                {
                    songs[j-1] = songs[j];
                }
                size--;
            }
        }
    }

    void playSong(const char* title)
    {
        for(int i = 0; i < size; i++)
        {
            if(strcmp(songs[i].getTitle(), title) == 0)
            {
                songs[i].play();
                return;
            }
        }
        cout << "Song not found!\n";
    }

    void mostPlayed(int count)
    {
        if(count > size)
        {
            cout << "Count > size\n";
        }

        Song* ptrs[size];
        for(int i = 0; i < size; i++)
        {
            ptrs[i] = &songs[i];
        }

        for(int i = 0; i < size; i++)
        {
            int max = i;
            for(int j = i+1; j < size; j++)
            {
                if(ptrs[max]->getLength() < ptrs[j]->getLength())
                {
                    max = j;
                }
            }    

            if(max != i)
            {
                swap(ptrs[i], ptrs[max]);
            }
        }

        for(int i = 0; i < count; i++)
        {
            cout << ptrs[i]->getTitle() << " " << ptrs[i]->getLength() << " " << ptrs[i]->getPlayCount() << endl;
        }
    }
};

int main()
{
    Song a;
    Song b("Life is life", 322);
    cout << b.getTitle() <<  " " << b.getLength() << endl;
    b.play();
    cout << b.getTitle() <<  " " << b.getLength() << " " << b.getPlayCount() << endl;

    MusicPlayer mp;
    mp.addSong("Somebody", 234);
    mp.addSong("Octavarium", 2323);
    mp.addSong("Wheel of time", 1435);

    mp.playSong("Octavarium");
    mp.playSong("Octavarium");
    mp.playSong("Wheel of time");

    mp.mostPlayed(2);

    mp.removeSong("Wheel of time");
    mp.mostPlayed(2);
}
