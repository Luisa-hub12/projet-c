#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "../Consignes/utils.h"
#include "../Shapes/shapes.h"
 

void menu_creation() {
    int choix;
    do {
        printf(CYAN"\n========== CRÉER UNE FORME ==========\n"RESET);
        printf(BLUE"1 - CIRCLE"RESET"\n");
        printf(BLUE"2 - SQUARE"RESET"\n");
        printf(BLUE"3 - RECTANGLE"RESET"\n");
        printf(BLUE"4 - LINE"RESET"\n");
        printf(BLUE"5 - ELLIPSE"RESET"\n");
        printf(BLUE"6 - POLYGON"RESET"\n");
        printf(BLUE"7 - POLYLINE"RESET"\n");
        printf(BLUE"8 - PATH"RESET"\n");
        printf(MAGENTA"0 - RETOUR\n"RESET);
        printf(BLUE"\n->>> Choisissez une forme à créer (0-8) : "RESET);
        choix = lire_entier();

        switch (choix) {
            case 1: ask_circle(); break;
            case 2: ask_square(); break;
            case 3: ask_rectangle(); break;
            case 4: ask_line(); break;
            case 5: ask_ellipse(); break;
            case 6: ask_polygon(); break;
            case 7: ask_polyline(); break;
            case 8: ask_path(); break;
            case 0: 
                printf(YELLOW"\n-----------------------------\n Retour au menu principal...\n-----------------------------\n"RESET);
                break;
            default:
                printf(RED"\n-----------------\n Choix invalide !!\n-----------------\n"RESET);
                break;
        }

    } while (choix != 0);
}

/** @brief --- Les fonctions de création de formes ---**/
void ask_circle() {
    int x, y, radius, thickness;
    char line_color[MAX_COLOR], background_color[MAX_COLOR];
    printf(MAGENTA"\n========== CRÉATION D'UN CERCLE ==========\n"RESET);
    printf(CYAN"Centre X : "RESET"\n"); x = lire_entier();
    printf(CYAN"Centre Y : "RESET"\n"); y = lire_entier();
    printf(CYAN"Rayon : "RESET"\n"); radius = lire_entier();
    saisir_couleur(line_color, RED"Couleur du trait : "RESET"\n");
    saisir_couleur(background_color, RED"Couleur de fond : "RESET"\n");
    printf(RED"Épaisseur : "RESET"\n"); thickness = lire_entier();

    circle* cir = create_circle(x, y, radius, line_color, background_color, thickness);
    if (cir && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = cir;
        formes[nb_formes].type = 'c';
        nb_formes++;
        printf(GREEN"\n---------------\n LE CERCLE A ÉTÉ CRÉER !!\n---------------\n"RESET);
    } else if (cir) {
        free_circle(cir);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n-------------------------\n Erreur création cercle.\n-------------------------\n"RESET);
    }
}

void ask_line() {
    int x1, y1, x2, y2, thickness;
    char line_color[MAX_COLOR];
    printf(MAGENTA"\n========== CRÉATION DE LIGNE ==========\n"RESET);
    printf(CYAN"Point de départ X : "RESET"\n"); x1 = lire_entier();
    printf(CYAN"Point de départ Y : "RESET"\n"); y1 = lire_entier();
    printf(YELLOW"Point d'arrivée X : "RESET"\n"); x2 = lire_entier();
    printf(YELLOW"Point d'arrivée Y : "RESET"\n"); y2 = lire_entier();
    saisir_couleur(line_color, RED"Couleur du trait : "RESET"\n");
    printf(RED"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    line* lin = create_line(x1, y1, x2, y2, line_color, thickness);
    if (lin && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = lin;
        formes[nb_formes].type = 'l';
        nb_formes++;
        printf(GREEN"\n--------------------\n LA LIGNE A ÉTÉ CRÉER !!\n--------------------\n"RESET);
    } else if (lin) {
        free_line(lin);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n--------------------------------\n Erreur création ligne.\n--------------------------------\n"RESET);
    }
}

void ask_square() {
    int x, y, listed, thickness;
    char line_color[MAX_COLOR], background_color[MAX_COLOR];

    printf(MAGENTA"\n========== CRÉATION D'UN CARRÉ ==========\n"RESET);
    printf(CYAN"Coordonnée X du coin inférieur gauche : "RESET"\n"); x = lire_entier();
    printf(CYAN"Coordonnée Y du coin inférieur gauche : "RESET"\n"); y = lire_entier();
    printf(CYAN"Côté : "RESET"\n"); listed = lire_entier();
    saisir_couleur(line_color, RED"Couleur du trait : "RESET"\n");
    saisir_couleur(background_color, RED"Couleur de fond : "RESET"\n");
    printf(RED"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    square* squ = create_square(x, y, listed, line_color, background_color, thickness);
    if (squ && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = squ;
        formes[nb_formes].type = 'a';
        nb_formes++;
        printf(GREEN"\n--------------\n LE CARRÉ A ÉTÉ CRÉER.\n--------------\n"RESET);
    } else if (squ) {
        free_square(squ);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n--------------------------------------\n Erreur création carré.\n--------------------------------------\n"RESET);
    }
}

void ask_rectangle() {
    int x, y, width, height, thickness;
    char line_color[MAX_COLOR], background_color[MAX_COLOR];

    printf(MAGENTA"\n========== CRÉATION D'UN RECTANGLE ==========\n"RESET);
    printf(CYAN"Coordonnée X du coin inférieur gauche : "RESET"\n"); x = lire_entier();
    printf(CYAN"Coordonnée Y du coin inférieur gauche : "RESET"\n"); y = lire_entier();
    printf(RED"Largeur : "RESET"\n"); width = lire_entier();
    printf(RED"Hauteur : "RESET"\n"); height = lire_entier();
    saisir_couleur(line_color, RED"Couleur du trait : "RESET"\n");
    saisir_couleur(background_color, RED"Couleur de fond : "RESET"\n");
    printf(RED"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    rectangle* rec = create_rectangle(x, y, width, height, line_color, background_color, thickness);
    if (rec && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = rec;
        formes[nb_formes].type = 'r';
        nb_formes++;
        printf(GREEN"\n------------------\n LE RECTANGLE A ÉTÉ CRÉER !!\n------------------\n"RESET);
    } else if (rec) {
        free_rectangle(rec);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n------------------------------------------\n Erreur création rectangle.\n------------------------------------------\n"RESET);
    }
}

void ask_ellipse() {
    int x, y, rayonx, rayony, thickness;
    char line_color[MAX_COLOR], background_color[MAX_COLOR];

    printf(MAGENTA"\n========== CRÉATION D'UNE ELLIPSE ==========\n"RESET);
    printf(CYAN"Coordonnée X du coin inférieur gauche : "RESET"\n"); x = lire_entier();
    printf(CYAN"Coordonnée Y du coin inférieur gauche : "RESET"\n"); y = lire_entier();
    printf(CYAN"Rayon 1 : "RESET"\n"); rayonx = lire_entier();
    printf(CYAN"Rayon 2 : "RESET"\n"); rayony = lire_entier();
    saisir_couleur(line_color, RED"Couleur du trait : "RESET"\n");
    saisir_couleur(background_color, RED"Couleur de fond : "RESET"\n");
    printf(RED"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    ellipse* ell = create_ellipse(x, y, rayonx, rayony, line_color, background_color, thickness);
    if (ell && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = ell;
        formes[nb_formes].type = 'e';
        nb_formes++;
        printf(GREEN"\n-----------------\n L'ÉLLIPSE A BIEN ÉTÉ CRÉE !!\n-----------------\n"RESET);
    } else if (ell) {
        free_ellipse(ell);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n------------------------------------------\n Erreur création ellipse.\n------------------------------------------\n"RESET);
    }
}

void ask_polygon() {
    int nb_points;
    printf(MAGENTA"\n========== CRÉATION D'UN POLYGONE ==========\n"RESET);
    printf(RED"⚠️ Nombre de points (>=3) : "RESET"\n"); nb_points = lire_entier();
    if (nb_points < 3) {
        printf(RED"⚠️ Un polygone doit avoir au moins 3 points.\n"RESET);
        return;
    }

    Point* points = malloc(sizeof(Point) * nb_points);
    if (!points) {
        printf(RED"\nErreur allocation mémoire pour les points.\n"RESET);
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d X : ", i); points[i].x = lire_entier();
        printf("Point %d Y : ", i); points[i].y = lire_entier();
    }

    char line_color[MAX_COLOR], background_color[MAX_COLOR];
    int thickness;
    saisir_couleur(line_color, PINK"Couleur du trait : "RESET"\n");
    saisir_couleur(background_color, PINK"Couleur de fond : "RESET"\n");
    printf(PINK"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    polygon* pgn = create_polygon(points, nb_points, line_color, background_color, thickness);
    free(points);

    if (pgn && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = pgn;
        formes[nb_formes].type = 'g';
        nb_formes++;
        printf(GREEN"\n------------------\n LE POLYGONE A BIEN ÉTÉ CRÉÉ !!\n------------------\n"RESET);
    } else if (pgn) {
        free_polygon(pgn);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n-----------------------------------------\n Erreur création polygone.\n-----------------------------------------\n"RESET);
    }
}

void ask_polyline() {
    int nb_points;
    printf(MAGENTA"\n========== CRÉATION DE LIGNE PARALLÈLE ==========\n"RESET);
    printf(RED"⚠️ Nombre de points (>=2) : "RESET"\n"); nb_points = lire_entier();
    if (nb_points < 2) {
        printf(RED"\n--------------------------------------------\n⚠️ Une polyline doit avoir au moins 2 points.\n--------------------------------------------\n"RESET);
        return;
    }

    Point* points = malloc(sizeof(Point) * nb_points);
    if (!points) {
        printf(RED"\n----------------------------------------------\n Erreur d'allocation mémoire pour les points.\n----------------------------------------------\n"RESET);
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d X : ", i); points[i].x = lire_entier();
        printf("Point %d Y : ", i); points[i].y = lire_entier();
    }

    char line_color[MAX_COLOR];
    int thickness;
    saisir_couleur(line_color, PINK"Couleur du trait : "RESET"\n");
    printf(PINK"Épaisseur du trait : "RESET"\n"); thickness = lire_entier();

    int nb_lignes;
    printf(PINK"Nombre total de lignes parallèles : "RESET"\n"); nb_lignes = lire_entier();

    if (nb_lignes < 2) {
        printf(RED"\n------------------------------------------------------\nLe nombre de lignes doit être supérieur ou égal à 2.\n------------------------------------------------------\n"RESET);
        free(points);
        return;
    }

    polyline* pll = create_polyline(points, nb_points, line_color, thickness);
    free(points);

    if (pll && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = pll;
        formes[nb_formes].type = 'p';
        nb_formes++;
        printf(GREEN"\n----------------------\n LA POLYLIGNE A BIEN ÉTÉ CRÉÉE !!\n----------------------\n"RESET);
    } else if (pll) {
        free_polyline(pll);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n--------------------------------------------\n Erreur lors de la création de la polyline.\n--------------------------------------------\n"RESET);
    }
}

void ask_path() {
    int nb_points;
    printf(MAGENTA"\n========== CRÉATION D'UN PATH (CHEMIN SVG) ==========\n"RESET);
    printf(RED"⚠️ Nombre de points (>=2) : "RESET"\n");
    nb_points = lire_entier();

    if (nb_points < 2) {
        printf(RED"\n--------------------------------------------\n⚠️ Un path doit avoir au moins 2 points.\n--------------------------------------------\n"RESET);
        return;
    }

    Point* points = malloc(sizeof(Point) * nb_points);
    if (!points) {
        printf(RED"\n----------------------------------------------\n Erreur d'allocation mémoire pour les points.\n----------------------------------------------\n"RESET);
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d X : ", i); points[i].x = lire_entier();
        printf("Point %d Y : ", i); points[i].y = lire_entier();
    }

    char line_color[MAX_COLOR];
    char fill_color[MAX_COLOR];
    int thickness;
    bool closed;

    saisir_couleur(line_color, PINK"Couleur du contour : "RESET"\n");
    saisir_couleur(fill_color, PINK"Couleur de remplissage : "RESET"\n");
    printf(PINK"Épaisseur du trait : "RESET"\n");
    thickness = lire_entier();

    int fermer;
    printf(BROWN"Le path doit-il être fermé ? (1 = oui, 0 = non) : "RESET"\n");
    fermer = lire_entier();
    closed = (fermer == 1);

    path* pth = create_path(points, nb_points, line_color, fill_color, thickness, closed);
    free(points);

    if (pth && nb_formes < MAX_FORMES) {
        formes[nb_formes].forme = pth;
        formes[nb_formes].type = 'h'; /** @note on note 'h' pour "path" */
        nb_formes++;
        printf(GREEN"\n----------------------\n LE PATH A ÉTÉ CRÉER AVEC SUCCÈS !!\n----------------------\n"RESET);
    } else if (pth) {
        free_path(pth);
        printf(ORANGE"\n----------------------------\n Limite de formes atteinte !!\n----------------------------\n"RESET);
    } else {
        printf(RED"\n--------------------------------------------\n Erreur lors de la création du path.\n--------------------------------------------\n"RESET);
    }
}
