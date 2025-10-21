#ifndef SHAPES_H
#define SHAPES_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_COLOR 16 
#define MAX_SHAPES 100 


typedef struct {
    int x;
    int y;
} Point;

/**
 * @struct Carre
 * @brief Représente un carré avec ses propriétés géométriques et graphiques.
 */
typedef struct {
    int x;                  /**< Coordonnée X du coin supérieur gauche */
    int y;                  /**< Coordonnée Y du coin supérieur gauche */
    int listed;               /**< Longueur du côté du carré */
    char line_color[16]; /**< Couleur du contour */
    char background_color[16];  /**< Couleur de remplissage */
    int thickness;          /**< Épaisseur du trait du contour */
} square;

/**
 * @brief Crée un nouveau carré.
 *
 * Alloue dynamiquement une structure carre et initialise ses attributs
 * avec les valeurs passées en paramètres.
 *
 * @param x Coordonnée X du coin supérieur gauche
 * @param y Coordonnée Y du coin supérieur gauche
 * @param listed Longueur du côté (doit être > 0)
 * @param line_color Couleur du contour (ex : "red", "#ef2e2eff")
 * @param background_color Couleur de remplissage (ex : "blue", "#1619e3ff")
 * @param thickness Épaisseur du contour
 * @return Pointeur vers le carré créé, ou NULL en cas d’erreur d’allocation ou de paramètre invalide
 */
square* create_square(int x, int y, int listed, const char* line_color, const char* background_color, int thickness); 

/**
 * @brief Déplace le carré selon un vecteur de translation.
 *
 * Modifie les coordonnées du coin supérieur gauche du carré
 * en fonction des décalages donnés.
 *
 * @param squ Pointeur vers le carré
 * @param dx Déplacement horizontal
 * @param dy Déplacement vertical
 */
void move_square(square* squ, int dx, int dy); 

/**
 * @brief Change la couleur du contour du carré.
 * @param squ Pointeur vers le carré
 * @param color Nouvelle couleur du contour
 */
void change_color_square_line(square* squ, const char* color);

/**
 * @brief Change la couleur de remplissage du carré.
 * @param squ Pointeur vers le carré
 * @param couleur Nouvelle couleur de fond
 */
void change_background_color_square(square* squ, const char* color); 

/**
 * @brief Libère la mémoire allouée pour le carré.
 * @param squ Pointeur vers le carré à libérer
 */
void free_square(square* squ); 

/**
 * @brief Vérifie si le carré est entièrement visible dans le viewport.
 *
 * @param squ Pointeur vers le carré
 * @param width_viewport Largeur du viewport
 * @param height_viewport Hauteur du viewport
 * @return true si le carré est valide et contenu dans la zone, false sinon
 */
bool check_square(const square* squ, int width_viewport, int height_viewport); 
void flip_square(square* squ, bool flipX, bool flipY, int width, int height);


typedef struct {
    int x;                  /**< Coordonnée X du centre */
    int y;                  /**< Coordonnée Y du centre */
    int radius;              /**< Rayon du cercle */
    char line_color[16]; /**< Couleur du contour */
    char background_color[16];  /**< Couleur de remplissage */
    int thickness;          /**< Épaisseur du trait du contour */
} circle;

/**
 * @brief Crée un nouveau cercle.
 * 
 * Alloue dynamiquement une structure cercle et initialise ses propriétés
 * selon les paramètres fournis.
 *
 * @param x Coordonnée X du centre
 * @param y Coordonnée Y du centre
 * @param radius Rayon du cercle (doit être > 0)
 * @param color_line Couleur du contour (ex : "red", "#FF0000")
 * @param background_color Couleur de remplissage (ex : "blue", "#0000FF")
 * @param thickness Épaisseur du contour
 * @return Pointeur vers le cercle créé, ou NULL en cas d’erreur d’allocation ou de paramètre invalide
 */
circle* create_circle(int x, int y, int radius, const char* color_line, const char* background_color, int thickness); 

/**
 * @brief Déplace le cercle selon un vecteur de translation.
 * @param cir Pointeur vers le cercle
 * @param dx Déplacement horizontal
 * @param dy Déplacement vertical
 */
void move_circle(circle* cir, int dx, int dy); 

/**
 * @brief Change la couleur du contour du cercle.
 * @param cir Pointeur vers le cercle
 * @param color Nouvelle couleur du contour
 */
void change_color_line(circle* cir, const char* color); 

/**
 * @brief Change la couleur de remplissage du cercle.
 * @param cir Pointeur vers le cercle
 * @param color Nouvelle couleur de fond
 */
void change_background_color(circle* cir, const char* color); 

/**
 * @brief Libère la mémoire allouée pour le cercle.
 * @param c Pointeur vers le cercle à libérer
 */
void free_circle(circle* cir); // on libère la mémoire du cercle 

/**
 * @brief Vérifie si le cercle est entièrement contenu dans le viewport.
 * 
 * @param cir Pointeur vers le cercle
 * @param width_viewport Largeur du viewport
 * @param height_viewport Hauteur du viewport
 * @return true si le cercle est valide et visible dans la zone, false sinon
 */
bool check_circle(const circle* cir, int width_viewport, int height_viewport); 
void flip_circle(circle* cir, bool flipX, bool flipY, int width, int height); 


/**
 * @brief Crée une nouvelle ellipse.
 * 
 * @param x Coordonnée X du centre ou du coin inférieur gauche
 * @param y Coordonnée Y du centre ou du coin inférieur gauche
 * @param radiusx Rayon horizontal de l'ellipse
 * @param radiusy Rayon vertical de l'ellipse
 * @param line_color Couleur du contour
 * @param background_color Couleur de remplissage
 * @param thickness Épaisseur du contour
 * @return Pointeur vers l'ellipse créée, ou NULL en cas d'erreur d’allocation
 */

/**
 * @struct Ellipse
 * @brief Représente une ellipse.
 */
typedef struct {
    int x;                  /** Coordonnée X du centre */
    int y;                  /** Coordonnée Y du centre */
    int radiusx;             /** Rayon horizontal */
    int radiusy;             /** Rayon vertical */
    char line_color[16]; /** Couleur du contour (ex. "black", "#000000") */
    char background_color[16];  /** Couleur de remplissage (ex. "white", "#FFFFFF") */
    int thickness;          /** Épaisseur du contour */
} ellipse;

 ellipse* create_ellipse(int x, int y, int radiusx, int radiusy, const char* line_color, const char* background_color, int thickness);

/**
 * @brief Libère la mémoire allouée pour l'éllipse.
 * @param e Pointeur vers l'éllipse à libérer
 */
void free_ellipse(ellipse* ell); // on libère la mémoire d'éllipse 
void move_ellipse(ellipse* ell, int dx, int dy);
void flip_ellipse(ellipse* ell, bool flipX, bool flipY, int width, int height);


typedef struct {
    int x1, y1;
    int x2, y2;
    char line_color[15];
    int thickness;
} line;

line* create_line(int x1, int y1, int x2, int y2, const char* line_color, int thickness);
void free_line(line* lin);
void move_line(line* lin, int dx1, int dy1, int dx2, int dy2);
void flip_line(line* lin, bool flipX, bool flipY, int width, int height);

/** @brief tableau de points formant le polygone
 * @brief nombre de points
 * @brief couleur du contour
 * @brief couleur de remplissage
 * @brief épaisseur du trait
 * @struct polygon
 * @brief Représente un polygone avec ses propriétés géométriques et graphiques.
 */
typedef struct {
    Point* points;
    int nb_points;
    char line_color[MAX_COLOR];
    char background_color[MAX_COLOR];
    int thickness;
} polygon;

polygon* create_polygon(Point* points, int nb_points, const char* line_color, const char* background_color, int thickness);
void free_polygon(polygon* pgn);
void move_polygon(polygon* pgn, int dx, int dy);
void flip_polygon(polygon* pgn, bool flipX, bool flipY, int width, int height);

typedef struct {
    Point* points;                      /**< Tableau de points formant la polyligne */
    int nb_points;                      /**< Nombre de points de la polyligne */
    char line_color[MAX_COLOR];         /**< Couleur du trait */
    int thickness;                      /**< Épaisseur du trait */
} polyline;


 polyline* create_polyline(Point* points, int nb_points, const char* line_color, int thickness);

void free_polyline(polyline* pln);
void move_polyline(polyline* pln, int dx, int dy);
void flip_polyline(polyline* pln, bool flipX, bool flipY, int width, int height); 



/** @struct rectangle */
typedef struct {
    int x;
    int y;
    int width;
    int height;
    char line_color[15];
    char background_color[15];
    int thickness;
} rectangle;


rectangle* create_rectangle(int x, int y, int width, int height,
                            const char* line_color,
                            const char* background_color,
                            int thickness);


void free_rectangle(rectangle* rec);
void move_rectangle(rectangle* rec, int dx, int dy);
void flip_rectangle(rectangle* rec, bool flipX, bool flipY, int width, int height);

/**
 * @struct Path
 * @brief Représente un chemin SVG (path), c’est-à-dire une suite de segments pouvant être fermés ou remplis.
 */
typedef struct {
    Point* points;                      /**< Tableau de points formant le chemin */
    int nb_points;                      /**< Nombre total de points du chemin */
    char line_color[MAX_COLOR];         /**< Couleur du contour */
    char fill_color[MAX_COLOR];         /**< Couleur de remplissage */
    int thickness;                      /**< Épaisseur du contour */
    int closed;                         /**< 1 si le chemin est fermé (Z), 0 sinon */
} path;

/**
 * @brief Crée un nouveau chemin (path) à partir d’un ensemble de points.
 * @param points Tableau des points formant le chemin.
 * @param nb_points Nombre total de points (au moins 2).
 * @param line_color Couleur du contour (nom ou code hexadécimal).
 * @param fill_color Couleur de remplissage (nom ou code hexadécimal).
 * @param thickness Épaisseur du contour.
 * @param closed Indique si le chemin est fermé (1) ou ouvert (0).
 * @return Un pointeur vers la structure path nouvellement créée, ou NULL en cas d’erreur.
 */
path* create_path(Point* points, int nb_points, const char* line_color, const char* fill_color, int thickness, int closed);

/**
 * @brief Libère la mémoire allouée pour le chemin.
 * @param pth Pointeur vers la structure path à libérer.
 * @note move_path pour déplacer le path de dx, dy.
 */
void free_path(path* pth);
void move_path(path* pth, int dx, int dy);
void flip_path(path* pth, bool flipX, bool flipY, int width, int height);

void flip_points(Point* points, int nb_points, bool flipX, bool flipY, int width, int height);

#endif


