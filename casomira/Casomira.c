#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void clearScreen(){
    #ifdef _WIN32
        system("cls"); // Pro Windows
    #else
        system("clear"); // Pro Linux/Unix/MacOS
    #endif
}

int main() {
    int hodiny, minuty, sekundy;
    char zacatek;
    bool start = false;

    printf("Zadejte hodnoty časomíry (H M S oddělené mezerou): ");
    scanf("%d %d %d", &hodiny, &minuty, &sekundy);

    if (hodiny < 0 || minuty < 0 || minuty >= 60 || sekundy < 0 || sekundy >= 60) 
    {
        printf("Neplatné hodnoty času!\n");
        return 1;
    }

    printf("Pro zacatek stisknete 'y': ");
    scanf(" %c", &zacatek);

    if(zacatek == 'y' || zacatek == 'Y')
    {
        start = true;
    }

    if (start)
    {
        while (hodiny > 0 || minuty > 0 || sekundy > 0) {
            clearScreen();
            printf("Časomíra: %02d:%02d:%02d\n", hodiny, minuty, sekundy);

            sleep(1);

            if (sekundy > 0) {
                sekundy--;
            } else if (minuty > 0) {
                minuty--;
                sekundy = 59;
            } else if (hodiny > 0) {
                hodiny--;
                minuty = 59;
                sekundy = 59;
            }
        }
        clearScreen();
        printf("Časomíra skončila!\n");
    }
    else 
    {
        printf("Časomíra nebyla spuštěna.\n");
    }
    
    return 0;
}