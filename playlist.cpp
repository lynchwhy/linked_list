/*
* playlist.cpp
* Written by : Jo Lynch (c3200655)
* Modified   : 27/08/23
*
* This class represents the implementation for a playlist class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#include "playlist.h"

Playlist::Playlist()
{
   // empty constructor
}

Playlist::~Playlist()
{
    // empty destructor
}

void Playlist::add_song(Song song)
{
    playlist.push_back(song);
}

void Playlist::print()
{
    if(playlist.empty())
    {
        std::cout << "Playlist is empty" << std::endl;
        return;
    }
    playlist.begin();
    for (int i = 0; i < playlist.size(); i++)
    {
        std::cout << "#" << playlist.get_current().get_id() << ": " << playlist.get_current().get_title() << " by " << playlist.get_current().get_artist();
        if (playlist.get_current().get_favourite() == true)
        {
            std::cout << " *" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
        playlist.forward();
    }
    playlist.begin();
}

void Playlist::detail_current_song()
{
    if(playlist.empty())
    {
        std::cout << "Playlist is empty" << std::endl;
        return;
    } 
    
    Song& currentSong = playlist.get_current();
    std::cout << "ID: " << currentSong.get_id() << std::endl;
    std::cout << "Title: " << currentSong.get_title() << std::endl;
    std::cout << "Artist: " << currentSong.get_artist() << std::endl;
    std::cout << "Year: " << currentSong.get_year() << std::endl;
    std::cout << "Favourite: " << currentSong.get_favourite() << std::endl;
}

Song& Playlist::get_current_song()
{
    return playlist.get_current();
}

void Playlist::next_song()
{
   playlist.forward();
}

void Playlist::prev_song()
{
    playlist.backward();
}

void Playlist::locate_song(int song_id)
{
    playlist.begin(); // Set current to the first node
    for (int i = 0; i < playlist.size(); i++) // Loop through the list
    {
        if (playlist.get_current().get_id() == song_id) // If the current node is the target then return
        {
            return;
        }
        playlist.forward();
    }
    std::cout << "Could not find a Song with that ID" << std::endl;
    playlist.begin();
}

void Playlist::flip_current_favourite()
{
    playlist.get_current().flip_favourite();
}

void Playlist::insert_song_before_current(Song song)
{
    playlist.insert(song);
}

void Playlist::remove_song()
{
    playlist.remove();
    playlist.begin();
}

int Playlist::count_favourite_songs()
{
    int favCount = 0; // Initialise the count of favourite songs to 0
    for (int i = 0; i < playlist.size(); i++) // Iterate through the Playlist
    {
        if (playlist.get_current().get_favourite() == true) // Check if the current song is a favorite
        {
            favCount++; // Increment the count of favourite songs
        }
        playlist.forward(); // Move to the next song
    }
    return favCount; // Return the count of favourite songs

}

int Playlist::count_total_songs()
{
    return playlist.size();
}

Playlist Playlist::filter_songs_of_artist(std::string &artist)
{
    Playlist result; // Create a new Playlist for the filtered songs

    playlist.begin(); // Start iterating from the beginning of the original Playlist

    for (int i = 0; i < playlist.size(); i++)
    {
        Song currentSong = playlist.get_current(); // Get the current song

        // Check if the artist matches the specified artist
        if (currentSong.get_artist() == artist)
        {
            // Add a copy of the current song to the result Playlist
            result.add_song(currentSong);
        }

        playlist.forward(); // Move to the next song
    }

    playlist.begin(); // Reset the original Playlist's current position
    return result; // Return the filtered Playlist
}

Playlist Playlist::filter_favourite_songs()
{
    Playlist result; // Create a new Playlist for the filtered songs

    playlist.begin(); // Start iterating from the beginning of the original Playlist

    for (int i = 0; i < playlist.size(); i++)
    {
        Song currentSong = playlist.get_current(); // Get the current song

        // Check if the current song is a favorite
        if (currentSong.get_favourite())
        {
            // Add a copy of the current song to the result Playlist
            result.add_song(currentSong);
        }

        playlist.forward(); // Move to the next song
    }

    playlist.begin(); // Reset the original Playlist's current position
    return result; // Return the filtered Playlist
}