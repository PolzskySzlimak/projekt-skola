#ifndef LOCATION_H
#define LOCATION_H

#include "game_utils.h"
#include "character.h"
#include <stdio.h>

void locationAction(int location, Character player) {
    printf("Jste v lokaci %d.\n", location);
    int action = 0;

    switch (location) {
    case 1:
        printf("1. Prohledej okol�\n");
        printf("2. Pokus se otev��t truhlu (uhodni k�d)\n");
        printf("3. Pokra�uj d�le\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatn� vstup.\n");
            return;
        }

        if (action == 2) {
            int correctCode = generateRandomNumber(1, 10);

            if (player.intelligence > 7) {
                if (correctCode > 5) {
                    printf("N�pov�da: Mo�n� byste se m�li zam��it na vy��� ��sla.\n");
                }
                else {
                    printf("N�pov�da: Mo�n� byste se m�li zam��it na ni��� ��sla.\n");
                }
            }

            printf("Zadejte ��slo mezi 1 a 10: ");
            int guess;
            if (scanf_s("%d", &guess) != 1) {
                printf("Neplatn� vstup.\n");
                return;
            }
            if (guess == correctCode) {
                printf("Spr�vn� k�d! Truhla se otev�r� a nach�z�te poklad.\n");
            }
            else {
                printf("�patn�! Spr�vn� k�d byl %d.\n", correctCode);
            }
        }
        break;
    case 2:
        printf("1. Projdi se po lese\n");
        printf("2. Vy�e� matematickou �lohu\n");
        printf("3. Pokra�uj d�le\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatn� vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Dopl�te chyb�j�c� ��slo v �ad�: 2, 4, 6, ?\n");

            if (player.intelligence > 6) {
                printf("N�pov�da: Hledejte pravidelnost ve zv�t�ov�n� ��sel.\n");
            }

            int answer;
            if (scanf_s("%d", &answer) != 1) {
                printf("Neplatn� vstup.\n");
                return;
            }
            if (answer == 8) {
                printf("Spr�vn�! Pokra�ujete d�le.\n");
            }
            else {
                printf("�patn�! Spr�vn� odpov�� byla 8.\n");
            }
        }
        break;

    case 3: {
        printf("Bojuj s protivn�kem\n");

        printf("Stiskn�te enter pro hod kostkou...\n");
        getchar();
        getchar();

        srand((unsigned int)time(NULL));
        int roll = (rand() % 6) + 1;
        printf("Hodili jste: %d\n", roll);

        if (roll >= 4) {
            printf("�der byl dostate�n� siln� a vyhr�l jsi souboj!\n");
        }
        else {
            printf("Prohr�v�te souboj.\n");

            if (player.strength > 7) {
                printf("M�te s�lu vy��� ne� 7, z�sk�v�te druh� pokus!\n");
                printf("Stiskn�te enter pro nov� hod kostkou...\n");
                getchar();

                roll = (rand() % 6) + 1;
                printf("Hodili jste: %d\n", roll);

                if (roll >= 4) {
                    printf("�der byl dostate�n� siln� a vyhr�l jsi souboj na druh� pokus!\n");
                }
                else {
                    printf("Prohr�ly jste souboj i na druh� pokus.\n");
                }
            }
        }
        break;
    }
    case 4:
        printf("1. Najdi tajn� vchod\n");
        printf("2. Vy�e� �lohu s prvo��sly\n");
        printf("N�pov�da: Hledejte n�sleduj�c� prvo��sla po zadan�m ��sle.\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatn� vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Zadejte n�hodn� generovan� ��slo: ");
            int number;
            if (scanf_s("%d", &number) != 1) {
                printf("Neplatn� vstup.\n");
                return;
            }

            if (player.intelligence > 5) {
                printf("N�pov�da: Zkuste se zam��it na ��sla, kter� nejsou d�liteln� ��dn�mi men��mi ��sly.\n");
            }

            printf("Nejbli��� t�i prvo��sla po %d jsou: ", number);
            findNextPrimes(number);
        }
        break;
    default:
        printf("Pokra�ujete do dal�� lokace...\n");
        break;
    }
}

#endif
