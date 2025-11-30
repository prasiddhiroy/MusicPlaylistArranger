//All the main source code
// header files
#include <stdio.h>
#include <string.h> //built in functions of string
#include "../include/playlist.h" //includes all the details from include folder
char songs[50][50];
// 50 songs or strings and  max 50 character each song.
int countsongs = 0;  //current number of songs
// add songs to the playlist
void addsongs() 
{
int n , added = 0;
printf("enter the number of songs u want to add");
scanf("%d", &n);
getchar(); //consume newline
for (int i=0; i<n; i++)
{
    if(countsongs>=50)
    {
        printf("no space for new songs\n");
        break;
    }
printf("enter song %d:" , i+1);// we want song to store from 1
fgets(songs[countsongs], 50 , stdin); /*songs store count songs
stdin make sure fgets read the input from keyboard
50= max characters*/
songs[countsongs][strcspn(songs[countsongs], "\n")]=0;
/* in strcpsn line it gives the index of where /n is 
then songs[countsongs][index]=0 replaces /n with null operator*/
countsongs++;
added++;
}
printf("songs added successfullly are:\n", added);
}
// search song by name
void searchthesongs()
{
    char name[50];
    printf("enter the song to search :");
    getchar();
    fgets(name , 50, stdin);
    name[strcspn(name, "\n")]=0;
    int found=0;
    for( int i=0 ; i<countsongs ; i++)
    {
        if(strcmp(songs[i], name)==0) // ==0 means that they are exactly equal
        {
            printf("song found at the position %d\n", i+1);
            found = 1;
            break;

        }
    }
    if (!found) printf("song not found\n");
}
// load songs from songs.txt
void loadsongsfromfile()
 {
    FILE *fp = fopen("../data/songs.txt", "r"); /* fopen opens the file
    r is read mode as we don't want to write the song
    fp file pointer use to access the file*/ 
    if(fp == NULL) {
        printf("Could not open songs.txt. Starting with empty playlist.\n");
        countsongs = 0;
        return;
    }
    countsongs = 0; //reset
    while(fgets(songs[countsongs], 50, fp) != NULL) // stdin and fp both are streamers but stdin take inputs from keyboard but fp from that particular file 
     {
        songs[countsongs][strcspn(songs[countsongs], "\n")] = 0; // remove newline
        countsongs++;
    }
    fclose(fp);// close file after done using to prevent memory leakage
}
// save songs to file
void savesongstofile() // it rewrites songs which were loaded and which were added by removing it all
{
    FILE *fp = fopen("../data/songs.txt", "w");
    if(fp == NULL) {
        printf("Could not save songs.\n");
        return;
    }
    for(int i = 0; i < countsongs; i++) {
        fprintf(fp, "%s\n", songs[i]); /* fprintf(file_pointer,"format string", values...)
        fpfile where we write
        song[i] string we want to write
        fprintf prints outputs to file not us*/
    }
    fclose(fp);
    printf("Playlist saved successfully.\n");
}
// display songs
void showsongs()
{
    if(countsongs==0)
    {
        printf("playlist is empty\n");
        return;
    }
    printf("PLAYLIST");
    for (int i=0; i<countsongs; i++)
    {
        printf("%d. %s\n", i+1, songs[i]);
    }
}

