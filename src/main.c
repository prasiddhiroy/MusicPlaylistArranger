#include <stdio.h>
#include "../include/playlist.h"
int main()
{
    int choice;
    loadsongsfromfile(); // loading existing songs from file
do 
{
    printf("MUSIC PLAYLIST");
    printf("1> displaysongs\n 2> add songs\n 3> search songs\n 4>saveplaylist\n 5> exist\n");
    printf("enter your choice:");
    scanf("%d", &choice );

        switch(choice) {
            case 1:
                showsongs();
                break;
            case 2:
                addsongs();
                break;
            case 3:
                searchthesongs();
                break;
            case 4:
                savesongstofile();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5) ;

    return 0;
}