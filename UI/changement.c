#include <stdio.h>
#include <stdlib.h>
#include "changement.h"
#include <string.h>
#include "../Consignes/utils.h"
#include "../Shapes/shapes.h"


void modifier_forme() {
    if (nb_formes == 0) {
        printf(YELLOW"\n--------------------------\n Aucune forme à modifier.\n--------------------------\n"RESET);
        return;
    }

    afficher_formes();
    printf(MAGENTA"\nTouche Entrer -> Annuler\n"RESET);
    printf(BLUE"\n>>> Index de la forme à modifier (0-%d) : "RESET, nb_formes-1);

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), stdin)) return; /** @note annule si erreur**/
    buffer[strcspn(buffer, "\n")] = '\0';
    if (strlen(buffer) == 0) return; /** @note Entrée seule = annuler**/

    int idx = atoi(buffer);
    if (idx < 0 || idx >= nb_formes) {
        printf(RED"\n-----------------\n Index invalide.\n-----------------\n"RESET);
        return;
    }

    FormeStockee* f = &formes[idx];

    switch(f->type) {
        case 'c': { 
            circle* cir = f->forme;
            printf(MAGENTA"\n========== MODIFIER CERCLE ==========\n"RESET);
            printf(BLUE"1 - Déplacer le centre"RESET"\n");
            printf(BLUE"2 - Modifier le Rayon"RESET"\n");
            printf(BLUE"3 - Changer la Couleur du trait"RESET"\n");
            printf(BLUE"4 - Changer la Couleur du fond"RESET"\n");
            printf(BLUE"5 - Inverser selon un axe"RESET"\n");
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment !!\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(CYAN"===== Déplacer X de : ====="RESET"\n");
                    if (!lire_entier_ou_retour(&dx)) break;
                    printf(CYAN"===== Déplacer Y de : ====="RESET"\n");
                    if (!lire_entier_ou_retour(&dy)) break;
                    cir->x += dx; cir->y += dy;
                } break;
                case 2: {
                    int nouveau;
                    printf(CYAN"===== Nouveau rayon : ====="RESET"\n");
                    if (!lire_entier_ou_retour(&nouveau)) break;
                    cir->radius = nouveau;
                } break;
                case 3: {
                    printf(CYAN"Nouvelle couleur du trait : "RESET"\n"); scanf("%15s", cir->line_color); vider_buffer();
                } break;
                case 4: {
                    printf(CYAN"Nouvelle couleur du fond : "RESET"\n"); scanf("%15s", cir->background_color); vider_buffer();
                } break;
                case 5: { /** @brief flip selon un axe */
                        printf(BLUE"\n===== Inverser le cercle :=====\n"RESET);
                        printf(CYAN"1 - Selon X (horizontal)"RESET"\n");
                        printf(CYAN"2 - Selon Y (vertical)"RESET"\n");
                        printf(MAGENTA"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_circle(cir, true, false, 800, 800);  /** @brief inverser horizontalement */
                          else if (axe == 2)
                            flip_circle(cir, false, true, 800, 800);  /** @brief inverser verticalement */
                        else
                            printf(YELLOW"\n=====ANNULÉ.=====\n"RESET);
                } break;
            }
        } break;

        case 'a': { 
            square* squ = f->forme;
            printf(MAGENTA"\n========== MODIFIER CARRÉ ==========\n"RESET);
            printf(BLUE"1 - Déplacer le coin inférieur gauche"RESET"\n");
            printf(BLUE"2 - Longueur des côtés"RESET"\n");
            printf(BLUE"3 - Couleur du trait"RESET"\n");
            printf(BLUE"4 - Couleur du fond"RESET"\n");
            printf(BLUE"5 - Inverser selon un axe"RESET"\n");
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment !!\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(CYAN"===== Déplacer X : ====="RESET"\n");
                    if (!lire_entier_ou_retour(&dx)) break;
                    printf(CYAN"===== Déplacer Y : ====="RESET"\n");
                    if (!lire_entier_ou_retour(&dy)) break;
                    squ->x += dx; squ->y += dy;
                } break;
                case 2: {
                    int listed;
                    printf(CYAN"->>Nouvelle longueur des côtés  : "RESET"\n");
                    if (!lire_entier_ou_retour(&listed)) break;
                    squ->listed = listed;
                } break;
                case 3: printf(CYAN"Nouvelle couleur du trait : "RESET"\n"); scanf("%15s", squ->line_color); vider_buffer(); break;
                case 4: printf(CYAN"Nouvelle couleur du fond : "RESET"\n"); scanf("%15s", squ->background_color); vider_buffer(); break;
                case 5: { 
                        printf(BLUE"\nInverser le carré :"RESET"\n");
                        printf(BLUE"1 - Selon X (horizontal)"RESET"\n");
                        printf(BLUE"2 - Selon Y (vertical)"RESET"\n");
                        printf(ORANGE">>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_square(squ, true, false, 800, 800);
                          else if (axe == 2)
                            flip_square(squ, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            }
        } break;

        case 'r': { 
            rectangle* rec = f->forme;
            printf(MAGENTA"\n========== MODIFIÉ RECTANGLE ==========\n"RESET);
            printf(BLUE"1 - Déplacer le coin inférieur gauche\n"RESET);
            printf(BLUE"2 - Largeur\n"RESET);
            printf(BLUE"3 - Hauteur\n"RESET);
            printf(BLUE"4 - Couleur du trait\n"RESET);
            printf(BLUE"5 - Couleur du fond\n"RESET);
            printf(BLUE"6 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(CYAN"Déplacer X  : "RESET"\n"); if (!lire_entier_ou_retour(&dx)) break;
                    printf(CYAN"Déplacer Y  : "RESET"\n"); if (!lire_entier_ou_retour(&dy)) break;
                    rec->x += dx; rec->y += dy;
                } break;
                case 2: {
                    int larg; printf(RED"Nouvelle largeur : "RESET"\n"); if (!lire_entier_ou_retour(&larg)) break;
                    rec->width = larg;
                } break;
                case 3: {
                    int haut; printf(RED"Nouvelle hauteur : "RESET"\n"); if (!lire_entier_ou_retour(&haut)) break;
                    rec->height = haut;
                } break;
                case 4: printf(RED"Nouvelle couleur : "RESET"\n"); scanf("%15s", rec->line_color); vider_buffer(); break;
                case 5: printf(RED"Nouvelle couleur du fond : "RESET"\n"); scanf("%15s", rec->background_color); vider_buffer(); break;
                case 6: { 
                        printf(BLUE"\nInverser le rectangle :\n"RESET);
                        printf(BROWN"1 - Selon X (horizontal)\n"RESET);
                        printf(BROWN"2 - Selon Y (vertical)\n"RESET);
                        printf(ORANGE"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_rectangle(rec, true, false, 800, 800);
                          else if (axe == 2)
                            flip_rectangle(rec, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            }
        } break;

        case 'l': { 
            line* lin = f->forme;
            printf(MAGENTA"\n========== MODIFIÉ LIGNE ==========\n"RESET);
            printf(BLUE"1 - Déplacer le premier point\n"RESET);
            printf(BLUE"2 - Déplacer le second point\n"RESET);
            printf(BLUE"3 - Couleur du trait\n"RESET);
            printf(BLUE"4 - Épaisseur du trait\n"RESET);
            printf(BLUE"5 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour Annuler à tout moment\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx1, dy1;
                    printf(GREEN"Déplacer X1 : "RESET"\n"); if (!lire_entier_ou_retour(&dx1)) break;
                    printf(GREEN"Déplacer Y1 : "RESET"\n"); if (!lire_entier_ou_retour(&dy1)) break;
                    lin->x1 += dx1; lin->y1 += dy1;
                } break;
                case 2: {
                    int dx2, dy2;
                    printf(GREEN"Déplacer X2 : "RESET"\n"); if (!lire_entier_ou_retour(&dx2)) break;
                    printf(GREEN"Déplacer Y2 : "RESET"\n"); if (!lire_entier_ou_retour(&dy2)) break;
                    lin->x2 += dx2; lin->y2 += dy2;
                } break;
                case 3: printf(CYAN"Nouvelle couleur du trait : "RESET"\n"); scanf("%15s", lin->line_color); vider_buffer(); break;
                case 4: {
                    int epaisseur;
                    printf(CYAN"Nouvelle épaisseur du trait : "RESET"\n"); if (!lire_entier_ou_retour(&epaisseur)) break;
                    lin->thickness = epaisseur;
                } break;
                case 5: {
                        printf(BLUE"\nInverser la ligne :\n"RESET);
                        printf(BROWN"1 - Selon X (horizontal)\n"RESET);
                        printf(BROWN"2 - Selon Y (vertical)\n"RESET);
                        printf(ORANGE"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_line(lin, true, false, 800, 800);
                          else if (axe == 2)
                            flip_line(lin, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            }
        } break;

        case 'e': {
            ellipse* ell = f->forme;
            printf(MAGENTA"\n========== MODIFIER ELLIPSE ==========\n"RESET);
            printf(BLUE"1 - Déplacer le centre\n"RESET);
            printf(BLUE"2 - Rayons\n"RESET);
            printf(BLUE"3 - Couleur du trait\n"RESET);
            printf(BLUE"4 - Couleur du fond\n"RESET);
            printf(BLUE"5 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour Annuler à tout moment\n"RESET);
            printf(BLUE"\n>>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(GREEN"Déplacer X : "RESET"\n"); if (!lire_entier_ou_retour(&dx)) break;
                    printf(GREEN"Déplacer Y : "RESET"\n"); if (!lire_entier_ou_retour(&dy)) break;
                    ell->x += dx; ell->y += dy;
                } break;
                case 2: {
                    int r1, r2;
                    printf(ORANGE"===== Nouveau rayon 1 : ====="RESET"\n"); if (!lire_entier_ou_retour(&r1)) break;
                    printf(ORANGE"===== Nouveau rayon 2 : ====="RESET"\n"); if (!lire_entier_ou_retour(&r2)) break;
                    ell->radiusx= r1; ell->radiusy = r2;
                } break;
                case 3: printf(ORANGE"===== Nouvelle couleur du trait : ======"RESET"\n"); scanf("%15s", ell->line_color); vider_buffer(); break;
                case 4: printf(ORANGE"===== Nouvelle couleur du fond : ====="RESET"\n"); scanf("%15s", ell->background_color); vider_buffer(); break;
                case 5: {
                        printf(BLUE"\nInverser l'ellipse :\n"RESET);
                        printf(RED"1 - Selon X (horizontal)\n"RESET);
                        printf(RED"2 - Selon Y (vertical)\n"RESET);
                        printf(YELLOW"->>> Votre choix : ");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_ellipse(ell, true, false, 800, 800);
                          else if (axe == 2)
                            flip_ellipse(ell, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            }
        } break;

        case 'g': {
            polygon* pgn = f->forme;
            printf(MAGENTA"\n========== MODIFIER LE POLYGONE ==========\n"RESET);
            printf(BLUE"1 - Déplacer le polygone\n"RESET);
            printf(BLUE"2 - Couleur du trait\n"RESET);
            printf(BLUE"3 - Couleur du fond\n"RESET);
            printf(BLUE"4 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(PURPLE"===== Déplacer X : ====="RESET"\n"); if (!lire_entier_ou_retour(&dx)) break;
                    printf(PURPLE"===== Déplacer Y : ====="RESET"\n"); if (!lire_entier_ou_retour(&dy)) break;
                    for (int i = 0; i < pgn->nb_points; i++) {
                        pgn->points[i].x += dx;
                        pgn->points[i].y += dy;
                    }
                } break;
                case 2: printf(CYAN"===== Nouvelle couleur du trait : ====="RESET"\n"); scanf("%15s", pgn->line_color); vider_buffer(); break;
                case 3: printf(CYAN"===== Nouvelle couleur du fond : ====="RESET"\n"); scanf("%15s", pgn->background_color); vider_buffer(); break;
                case 4: {
                        printf(BLUE"\nInverser le polygone :\n"RESET);
                        printf(BLUE"1 - Selon X (horizontal)\n"RESET);
                        printf(BLUE"2 - Selon Y (vertical)\n"RESET);
                        printf(RED"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_polygon(pgn, true, false, 800, 800);
                          else if (axe == 2)
                            flip_polygon(pgn, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            }
        } break;

        case 'p': { 
            polyline* pln = f->forme;
            printf(MAGENTA"\n========== MODIFIER LA POLYLIGNE ==========\n"RESET);
            printf(BLUE"1 - Déplacer la polyligne\n"RESET);
            printf(BLUE"2 - Couleur du trait\n"RESET);
            printf(BLUE"3 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment !!\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(BROWN"===== Déplacer X : ====="RESET"\n"); if (!lire_entier_ou_retour(&dx)) break;
                    printf(BROWN"===== Déplacer Y : ====="RESET"\n"); if (!lire_entier_ou_retour(&dy)) break;
                    for (int i = 0; i < pln->nb_points; i++) {
                        pln->points[i].x += dx;
                        pln->points[i].y += dy;
                    }
                } break;
                case 2: printf(BROWN"===== Nouvelle couleur du trait : ====="RESET"\n"); scanf("%15s", pln->line_color); vider_buffer(); break;
                case 3: {
                        printf(BLUE"\nInverser la polyligne :\n"RESET);
                        printf(GREEN"1 - Selon X (horizontal)\n"RESET);
                        printf(GREEN"2 - Selon Y (vertical)\n"RESET);
                        printf(ORANGE"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();
                        if (axe == 1)
                            flip_polyline(pln, true, false, 800, 800);
                          else if (axe == 2)
                            flip_polyline(pln, false, true, 800, 800);
                        else
                            printf(YELLOW"\nAnnulé.\n"RESET);
                } break;
            } 
        } break; 
        
        case 'h': {
            path* pth = f->forme;
            if (!pth) {
                printf(RED"\nErreur : le path est introuvable.\n"RESET);
                break;
            }
            printf(MAGENTA"\n========== MODIFIER LE PATH ==========\n"RESET);
            printf(BLUE"1 - Déplacer le path\n"RESET);
            printf(BLUE"2 - Couleur du trait\n"RESET);
            printf(BLUE"3 - Couleur de remplissage\n"RESET);
            printf(BLUE"4 - Fermer/Ouvrir le path\n"RESET);
            printf(BLUE"5 - Inverser selon un axe\n"RESET);
            printf(MAGENTA"\nTouche Entrer pour ANNULER à tout moment !!\n"RESET);
            printf(BLUE"\n->>> Choisissez une option : "RESET);
            int choix = lire_entier();
            switch(choix) {
                case 1: {
                    int dx, dy;
                    printf(YELLOW"===== Déplacer X : ====="RESET"\n"); if (!lire_entier_ou_retour(&dx)) break;
                    printf(YELLOW"===== Déplacer Y : ====="RESET"\n"); if (!lire_entier_ou_retour(&dy)) break;
                    move_path(pth, dx, dy);
                    printf(GREEN"\nPath déplacé de (%d, %d)!\n"RESET, dx, dy);
                } break;
                case 2: printf(BLUE"Nouvelle couleur du trait : "RESET"\n"); 
                        scanf("%15s", pth->line_color); 
                        vider_buffer();
                        printf(GREEN"\nCouleur du trait modifiée.\n"RESET);
                        break;
                case 3: printf(PINK"Nouvelle couleur de remplissage : "RESET"\n"); 
                        scanf("%15s", pth->fill_color); 
                        vider_buffer();
                        printf(GREEN"\nCouleur de remplissage modifiée.\n"RESET); 
                        break;
                case 4: 
                        pth->closed = !pth->closed; 
                        printf(GREEN"\n------------------------\n Le path est maintenant %s.\n------------------------\n"RESET, pth->closed ? "fermé" : "ouvert");
                        break;
                case 5: { 
                        printf(BLUE"\nInverser le path :\n"RESET);
                        printf(MAGENTA"1 - Selon X (horizontal)\n"RESET);
                        printf(MAGENTA"2 - Selon Y (vertical)\n"RESET);
                        printf(RED"->>> Votre choix : "RESET"\n");
                        int axe = lire_entier();

                        if (axe == 1){
                            flip_path(pth, true, false, 800, 800);
                            printf(GREEN"\n========== Path inversé horizontalement ! ==========\n"RESET);
                        } else if (axe == 2) {
                            flip_path(pth, false, true, 800, 800);
                            printf(GREEN"\n========== Path inversé verticalement ! ==========\n"RESET);
                        } else {
                            printf(YELLOW"\nAction Annulé.\n"RESET);
                        }
                    } break;

                    default:
                        printf(YELLOW"\nAction annulée ou choix invalide.\n"RESET);
                        break;
            }
} break;

    }
}   
    
void supprimer_forme() {
    if (nb_formes == 0) {
        printf(YELLOW"\n----------------------------\n Aucune forme à supprimer.\n----------------------------\n"RESET);
        return;
    }

    afficher_formes();
    printf(MAGENTA"\nTouche Entrer -> Annuler\n"RESET);
    printf(BLUE"\n->>> Index de la forme à supprimer (0-%d) : "RESET, nb_formes-1);

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), stdin)) return;
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) == 0) return; 

    int idx = atoi(buffer);
    if (idx < 0 || idx >= nb_formes) {
        printf(RED"\n-----------------\n Index invalide.\n-----------------\n"RESET);
        return;
    }

    switch(formes[idx].type) {
        case 'c': free_circle(formes[idx].forme); break;
        case 'a': free_square(formes[idx].forme); break;
        case 'r': free_rectangle(formes[idx].forme); break;
        case 'l': free_line(formes[idx].forme); break;
        case 'e': free_ellipse(formes[idx].forme); break;
        case 'g': free_polygon(formes[idx].forme); break;
        case 'p': free_polyline(formes[idx].forme); break;
        case 'h': free_path(formes[idx].forme); break;
    }

    for (int i = idx; i < nb_formes-1; i++) formes[i] = formes[i+1];
    nb_formes--;
    printf(GREEN"\n-------------------\n Forme supprimée !\n-------------------\n"RESET);
}



/** @brief Affiche la liste des formes stockées**/
void afficher_formes() {
    if (nb_formes == 0) {
        printf(YELLOW"\n------------------------------------\n Aucune forme n'a encore été créée.\n------------------------------------\n"RESET);
        return;
    }
    printf(CYAN"\n========== LISTE DES FORMES CRÉÉES ==========\n"RESET);
    for (int i = 0; i < nb_formes; i++) {
        printf("[%d] ", i);
        switch (formes[i].type) {
            case 'c': {
                circle* cir = formes[i].forme;
                printf("circle - position=(%d,%d), radius=%d, trait=%s, fond=%s, thickness=%d\n",
                       cir->x, cir->y, cir->radius, cir->line_color, cir->background_color, cir->thickness);
                break;
            }
            case 'a': {
                square* squ = formes[i].forme;
                printf("square - position=(%d,%d), côté=%d, trait=%s, fond=%s, thickness=%d\n",
                       squ->x, squ->y, squ->listed, squ->line_color, squ->background_color, squ->thickness);
                break;
            }
            case 'r': {
                rectangle* rec = formes[i].forme;
                printf("rectangle - position=(%d,%d), largeur=%d, hauteur=%d, trait=%s, fond=%s, thickness=%d\n",
                       rec->x, rec->y, rec->width, rec->height, rec->line_color, rec->background_color, rec->thickness);
                break;
            }
            case 'l': {
                line* lin = formes[i].forme;
                printf("line - de=(%d,%d) à=(%d,%d), couleur=%s, thickness=%d\n",
                       lin->x1, lin->y1, lin->x2, lin->y2, lin->line_color, lin->thickness);
                break;
            }
            case 'e': {
                ellipse* ell = formes[i].forme;
                printf("ellipse - position=(%d,%d), radius-x=%d, radius-y==%d, trait=%s, fond=%s, thickness=%d\n",
                       ell->x, ell->y, ell->radiusx, ell->radiusy, ell->line_color, ell->background_color, ell->thickness);
                break;
            }
            case 'g': {
                polygon* pgn = formes[i].forme;
                printf("polygon - %d points, trait=%s, fond=%s, thickness=%d\n",
                       pgn->nb_points, pgn->line_color, pgn->background_color, pgn->thickness);
                break;
            }
            case 'p': {
                polyline* pln = formes[i].forme;
                printf("polyline - %d points, trait=%s, thickness=%d\n",
                       pln->nb_points, pln->line_color, pln->thickness);
                break;
            }
            case 'h': { 
                path* pth = formes[i].forme;
                printf("path - %d points, trait=%s, remplissage=%s, thickness=%d, %s\n",
                    pth->nb_points,
                    pth->line_color,
                    pth->fill_color,
                    pth->thickness,
                    pth->closed ? "fermé" : "ouvert");
                break;
            }

default:
                printf(RED"\n-----------------\n Forme inconnue.\n-----------------\n"RESET);
                break;
        }
    }
}
