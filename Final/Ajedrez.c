//
// Created by PC on 19/11/2020.
//
#include"Ajedrez.h"

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void piece_count(struct piece ***board2,
                 struct gamestate *game) {//Cuenta las piezas blacas y negras disponibles por cada jugador

    int b = 0;
    int n = 0;
    for (int u = 0; u < 16; u++) {
        game->Negras[u] = NULL;
        game->blancas[u] = NULL;
    }

    for (int x = 0; x < 8; x++) {

        for (int y = 0; y < 8; y++) {

            if (board2[x][y] != NULL) {

                if (board2[x][y]->color == 'W') {
                    game->blancas[b] = board2[x][y];
                    b++;
                }

                if (board2[x][y]->color == 'B') {
                    game->Negras[n] = board2[x][y];
                    n++;
                }
            }
        }
    }
}

void save_game(struct piece ***board2, FILE *file) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            struct piece p;
            if (board2[i][j] != NULL) {
                p = *board2[i][j];//se guarda la pieza
            } else {//Lo hace cuando encuentra un Null
                memset(&p, 0, sizeof(p));
            }
            fwrite(&p, sizeof(p), 1, file);
        }
    }
}

void load_game(struct piece ***board2, FILE *file) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // board2[i][j] = malloc(sizeof(struct piece));
            struct piece piece;
            fread(&piece, sizeof(piece), 1, file);
            if (piece.piece_type == 0 && piece.x_axis == 0 && piece.y_axis == 0 && piece.color == 0 && piece.mvs == 0) {
                // pieza no válida
                if (board2[i][j] != NULL) {
                    free(board2[i][j]);
                }
                board2[i][j] = NULL;
            } else {
                if (board2[i][j] == NULL) {
                    board2[i][j] = malloc(sizeof(struct piece));
                }
                *board2[i][j] = piece;
            }
        }
    }
}

void swap(struct piece ***board2, int y, int x, int ny, int nx, int result) {
    struct piece *help;

    if (result == 1) {//si el movimiento que encuntra es valido hace el swap a la posicion
        board2[y][x]->mvs++;
        help = board2[y][x];
        board2[ny][nx] = help;
        board2[ny][nx]->x_axis = nx;
        board2[ny][nx]->y_axis = ny;
        board2[y][x] = NULL;
    }
    if (result == 2) {//Se encuentra una pieza enemiga y se hace el swap
        board2[y][x]->mvs++;
        help = board2[ny][nx];
        board2[ny][nx] = board2[y][x];
        board2[ny][nx]->x_axis = nx;
        board2[ny][nx]->y_axis = ny;
        board2[y][x] = NULL;
        free(help);
    }
}

int torre(struct piece *piece, int x, int y, struct piece ***board2) {//Movimientos validos de la torre

    int filasT = piece->y_axis;
    int columnaT = piece->x_axis;

    if (x == piece->x_axis && y < piece->y_axis && y <= 7) {//Movimiento hacia arriba

        int conto = 0;
        filasT = filasT - 1;
        int bandera = 0;

        while (bandera == 0) {
            if (filasT >= 0) {
                if (board2[filasT][columnaT] == NULL) {
                    filasT--;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                    //conto++;
                }
            }
            if (filasT == -1)bandera = 1;
        }

        int max_idx_y = piece->y_axis - conto;

        int ret2 = 0;
        if (board2[max_idx_y - 1][columnaT] != NULL) {
            ret2 = conto + 1;
            int h = ret2;
            ret2 = piece->y_axis - h;
        }

        if (x == piece->x_axis && y >= max_idx_y)return 1;
        if (board2[ret2][x] != NULL) {

            if (x == piece->x_axis && y == ret2 && board2[ret2][x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (x == piece->x_axis && y > piece->y_axis && y <= 7) {//Movimiento hacia abajo

        int conto = 0;
        filasT = filasT + 1;
        int bandera = 0;

        while (bandera == 0) {
            if (filasT >= 0 && filasT <= 7) {
                if (board2[filasT][columnaT] == NULL) {
                    filasT++;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                    //conto++;
                }
            }
            if (filasT == 8)bandera = 1;
        }

        int max_idx_y = piece->y_axis + conto;
        int ret2 = 0;
        if (board2[max_idx_y + 1][columnaT] != NULL) {
            ret2 = max_idx_y + 1;
        }

        if (x == piece->x_axis && y <= max_idx_y)return 1;

        if (board2[ret2][x] != NULL) {

            if (x == piece->x_axis && y == ret2 && board2[ret2][x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (y == piece->y_axis && x < piece->x_axis && x <= 7) {//Movimiento hacia la izquierda

        int conto = 0;
        int bandera = 0;
        columnaT = columnaT - 1;

        while (bandera == 0) {
            if (columnaT >= 0) {
                if (board2[filasT][columnaT] == NULL) {
                    columnaT--;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                }
            }
            if (columnaT == -1)bandera = 1;
        }

        int max_idx_x = piece->x_axis - conto;
        int ret2 = 0;

        if (board2[filasT][columnaT] != NULL) {

            ret2 = columnaT - 1;
        }

        if (y == piece->y_axis && x >= max_idx_x)return 1;

        if (board2[y][ret2] != NULL) {

            if (y == piece->y_axis && x == ret2 && board2[y][ret2]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (y == piece->y_axis && x > piece->x_axis && x <= 7) {//Movimiento hacia la derecha

        int conto = 0;
        int bandera = 0;
        columnaT = columnaT + 1;

        while (bandera == 0) {
            if (columnaT >= 0 && columnaT <= 7) {
                if (board2[filasT][columnaT] == NULL) {
                    columnaT++;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                }
            }
            if (columnaT == 8)bandera = 1;
        }

        int max_idx_x = piece->x_axis + conto;
        int ret2 = 0;

        if (board2[filasT][columnaT] != NULL) {
            ret2 = columnaT;
        }

        if (y == piece->y_axis && x <= max_idx_x)return 1;

        if (board2[y][ret2] != NULL) {
            if (y == piece->y_axis && x == ret2 && board2[y][ret2]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int reyna(struct piece *piece, int x, int y, struct piece ***board2) {


    int filasT = piece->y_axis;
    int columnaT = piece->x_axis;

    if (x == piece->x_axis && y < piece->y_axis && y <= 7) {//Movimiento hacia arriba

        int conto = 0;
        filasT = filasT - 1;
        int bandera = 0;

        while (bandera == 0) {
            if (filasT >= 0) {
                if (board2[filasT][columnaT] == NULL) {
                    filasT--;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                    //conto++;
                }
            }
            if (filasT == -1)bandera = 1;
        }

        int max_idx_y = piece->y_axis - conto;

        int ret2 = 0;
        if (board2[max_idx_y - 1][columnaT] != NULL) {
            ret2 = conto + 1;
            int h = ret2;
            ret2 = piece->y_axis - h;
        }

        if (x == piece->x_axis && y >= max_idx_y)return 1;
        if (board2[ret2][x] != NULL) {

            if (x == piece->x_axis && y == ret2 && board2[ret2][x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (x == piece->x_axis && y > piece->y_axis && y <= 7) {//Movimienti hacia abajo

        int conto = 0;
        filasT = filasT + 1;
        int bandera = 0;

        while (bandera == 0) {
            if (filasT >= 0 && filasT <= 7) {
                if (board2[filasT][columnaT] == NULL) {
                    filasT++;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                    //conto++;
                }
            }
            if (filasT == 8)bandera = 1;
        }

        int max_idx_y = piece->y_axis + conto;

        int ret2 = 0;
        if (board2[max_idx_y + 1][columnaT] != NULL) {
            ret2 = max_idx_y + 1;
        }

        if (x == piece->x_axis && y <= max_idx_y)return 1;

        if (board2[ret2][x] != NULL) {

            if (x == piece->x_axis && y == ret2 && board2[ret2][x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (y == piece->y_axis && x < piece->x_axis && x <= 7) {//Movimineto hacia la derecha
        int conto = 0;
        int bandera = 0;
        columnaT = columnaT - 1;

        while (bandera == 0) {
            if (columnaT >= 0) {
                if (board2[filasT][columnaT] == NULL) {
                    columnaT--;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;
                }
            }
            if (columnaT == -1)bandera = 1;
        }

        int max_idx_x = piece->x_axis - conto;
        int ret2 = 0;

        if (board2[filasT][columnaT] != NULL) {
            ret2 = columnaT - 1;
        }

        if (y == piece->y_axis && x >= max_idx_x)return 1;

        if (board2[y][ret2] != NULL) {

            if (y == piece->y_axis && x == ret2 && board2[y][ret2]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (y == piece->y_axis && x > piece->x_axis && x <= 7) {//Movimiento hacia la izquierda


        int conto = 0;
        int bandera = 0;
        columnaT = columnaT + 1;

        while (bandera == 0) {
            if (columnaT >= 0 && columnaT <= 7) {
                if (board2[filasT][columnaT] == NULL) {
                    columnaT++;
                    conto++;
                }
                if (board2[filasT][columnaT] != NULL) {
                    bandera = 1;

                }


            }

            if (columnaT == 8)bandera = 1;
        }
        int max_idx_x = piece->x_axis + conto;
        int ret2 = 0;


        if (board2[filasT][columnaT] != NULL) {
            ret2 = columnaT;
        }
        if (y == piece->y_axis && x <= max_idx_x)return 1;


        if (board2[y][ret2] != NULL) {
            if (y == piece->y_axis && x == ret2 && board2[y][ret2]->color != piece->color)return 2;
            else {
                return 0;
            }

        } else {
            return 0;
        }


    }

    if (piece->x_axis < x && piece->y_axis > y) {



        int bandera = 0;
        int filas = piece->y_axis - 1;
        int columna = piece->x_axis + 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas >= 0 && columna <= 7) {

                if (board2[filas][columna] == NULL) {
                    columna++;
                    filas--;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {
                    bandera = 1;
                }
            }
            if (columna == 8 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis - conto;
        int max_dx_x = piece->x_axis + conto;

        int ret2x = 0;
        int ret2y = 0;

        if (max_dx_x < 7 && max_dx_y > 0) {
            if (board2[max_dx_y - 1][max_dx_x + 1] != NULL) {
                ret2x = max_dx_x + 1;
                ret2y = max_dx_y - 1;
            }
        }


        if (x <= max_dx_x && y >= max_dx_y)return 1;

        if (board2[ret2y][ret2x] != NULL) {
            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (piece->y_axis < y && piece->x_axis < x) {

        int bandera = 0;
        int filas = piece->y_axis + 1;
        int columna = piece->x_axis + 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas <= 7 && columna <= 7) {
                //printf("cont:%i\n",conto);
                if (board2[filas][columna] == NULL) {
                    columna++;
                    filas++;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {
                    bandera = 1;
                }
            }
            if (columna == 8 || filas == 8)bandera = 1;
        }


        int max_dx_y = piece->y_axis + conto;
        int max_dx_x = piece->x_axis + conto;

        int ret2x = 0;
        int ret2y = 0;

        if (max_dx_y < 7 && max_dx_x < 7) {
            if (board2[max_dx_y + 1][max_dx_x + 1] != NULL) {
                ret2x = max_dx_x + 1;
                ret2y = max_dx_y + 1;
            }
        }


        if (x <= max_dx_x && x > 0 && y <= max_dx_y && y > 0)return 1;
        if (board2[ret2y][ret2x] != NULL) {
            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        }
    }

    if (x < piece->x_axis && y > piece->y_axis) {

        int bandera = 0;
        int filas = piece->y_axis + 1;
        int columna = piece->x_axis - 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas <= 7 && columna >= 0) {
                if (board2[filas][columna] == NULL) {
                    columna--;
                    filas++;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {

                    bandera = 1;
                }
            }
            if (columna == 8 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis + conto;
        int max_dx_x = piece->x_axis - conto;
        int ret2x = 0;
        int ret2y = 0;

        if (max_dx_y < 7 && max_dx_x > 0) {
            if (board2[max_dx_y + 1][max_dx_x - 1] != NULL) {
                ret2x = max_dx_x - 1;
                ret2y = max_dx_y + 1;
            }
        }



        if (x >= max_dx_x && y <= max_dx_y)return 1;
        if (board2[ret2y][ret2x] != NULL) {

            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (x < piece->x_axis && y < piece->y_axis) {

        int bandera = 0;
        int filas = piece->y_axis - 1;
        int columna = piece->x_axis - 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas >= 0 && columna >= 0) {
                if (board2[filas][columna] == NULL) {
                    columna--;
                    filas--;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {

                    bandera = 1;
                }
            }
            if (columna == -1 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis - conto;
        int max_dx_x = piece->x_axis - conto;
        int ret2x = 0;
        int ret2y = 0;
        if (max_dx_y > 0 && max_dx_x > 0) {
            if (board2[max_dx_y - 1][max_dx_x - 1] != NULL) {
                ret2x = max_dx_x - 1;
                ret2y = max_dx_y - 1;
            }
        }


        if (x >= max_dx_x && y >= max_dx_y)return 1;
        if (board2[ret2y][ret2x] != NULL) {

            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int alfil(struct piece *piece, int x, int y, struct piece ***board2) {

    if (piece->x_axis < x && piece->y_axis > y) {



        int bandera = 0;
        int filas = piece->y_axis - 1;
        int columna = piece->x_axis + 1;
        int conto = 0;
        while (bandera == 0) {
            if (filas >= 0 && columna <= 7) {


                if (board2[filas][columna] == NULL) {
                    columna++;
                    filas--;
                    conto++;
                }

                if (board2[filas][columna] != NULL) {
                    bandera = 1;
                }
            }
            if (columna == 8 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis - conto;
        int max_dx_x = piece->x_axis + conto;

        int ret2x = 0;
        int ret2y = 0;

        if (max_dx_x < 7 && max_dx_y > 0) {
            if (board2[max_dx_y - 1][max_dx_x + 1] != NULL) {
                ret2x = max_dx_x + 1;
                ret2y = max_dx_y - 1;
            }
        }


        if (x <= max_dx_x && y >= max_dx_y)return 1;

        if (board2[ret2y][ret2x] != NULL) {
            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (piece->y_axis < y && piece->x_axis < x) {

        int bandera = 0;
        int filas = piece->y_axis + 1;
        int columna = piece->x_axis + 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas <= 7 && columna <= 7) {
                //printf("cont:%i\n",conto);
                if (board2[filas][columna] == NULL) {
                    columna++;
                    filas++;
                    conto++;
                }

                if (board2[filas][columna] != NULL) {
                    bandera = 1;
                }
            }

            if (columna == 8 || filas == 8)bandera = 1;
        }


        int max_dx_y = piece->y_axis + conto;
        int max_dx_x = piece->x_axis + conto;

        int ret2x = 0;
        int ret2y = 0;

        if (max_dx_y < 7 && max_dx_x < 7) {
            if (board2[max_dx_y + 1][max_dx_x + 1] != NULL) {
                ret2x = max_dx_x + 1;
                ret2y = max_dx_y + 1;
            }
        }


        if (x <= max_dx_x && x > 0 && y <= max_dx_y && y > 0)return 1;

        if (board2[ret2y][ret2x] != NULL) {
            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        }
    }

    if (x < piece->x_axis && y > piece->y_axis) {

        int bandera = 0;
        int filas = piece->y_axis + 1;
        int columna = piece->x_axis - 1;
        int conto = 0;
        while (bandera == 0) {
            if (filas <= 7 && columna >= 0) {
                if (board2[filas][columna] == NULL) {
                    columna--;
                    filas++;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {

                    bandera = 1;
                }
            }
            if (columna == 8 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis + conto;
        int max_dx_x = piece->x_axis - conto;
        int ret2x = 0;
        int ret2y = 0;
        if (max_dx_y < 7 && max_dx_x > 0) {
            if (board2[max_dx_y + 1][max_dx_x - 1] != NULL) {
                ret2x = max_dx_x - 1;
                ret2y = max_dx_y + 1;
            }
        }



        if (x >= max_dx_x && y <= max_dx_y)return 1;
        if (board2[ret2y][ret2x] != NULL) {

            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (x < piece->x_axis && y < piece->y_axis) {

        int bandera = 0;
        int filas = piece->y_axis - 1;
        int columna = piece->x_axis - 1;
        int conto = 0;

        while (bandera == 0) {
            if (filas >= 0 && columna >= 0) {


                if (board2[filas][columna] == NULL) {
                    columna--;
                    filas--;
                    conto++;
                }
                if (board2[filas][columna] != NULL) {

                    bandera = 1;
                }
            }

            if (columna == -1 || filas == -1)bandera = 1;
        }


        int max_dx_y = piece->y_axis - conto;
        int max_dx_x = piece->x_axis - conto;
        int ret2x = 0;
        int ret2y = 0;
        if (max_dx_y > 0 && max_dx_x > 0) {
            if (board2[max_dx_y - 1][max_dx_x - 1] != NULL) {
                ret2x = max_dx_x - 1;
                ret2y = max_dx_y - 1;
            }
        }

        if (x >= max_dx_x && y >= max_dx_y)return 1;

        if (board2[ret2y][ret2x] != NULL) {
            if (x == ret2x && y == ret2y && board2[ret2y][ret2x]->color != piece->color)return 2;
            else {
                return 0;
            }
        } else {
            return 0;
        }

    } else {
        return 0;
    }
}

int Black_Pawn(struct piece *piece, int x, int y, struct piece ***board2) {

    if (piece->piece_type == 'P') {


        if (y == piece->y_axis + 1 && x == piece->x_axis + 1 && x >= 0 && y >= 0 && x <= 7 && y <= 7) {
            if (board2[y][x] == NULL)return 0;//commer derecha
            if (board2[y][x] != NULL && board2[y][x]->color != piece->color)return 2;
            if (board2[y][x] != NULL && board2[y][x]->color == piece->color)return 0;

        }

        if (y == piece->y_axis + 1 && x == piece->x_axis - 1 && x >= 0 && y >= 0 && x <= 7 && y <= 7) {
            if (board2[y][x] == NULL)return 0;//comer izquierda
            if (board2[y][x]->color != piece->color)return 2;
            if (board2[y][x]->color == piece->color)return 0;
        }

        if (piece->mvs == 0) {
            if (y == piece->y_axis + 2 && y > piece->y_axis && board2[y][x] == NULL && y <= 7 &&
                x == piece->x_axis)
                return 1;
            if (y == piece->y_axis + 1 && y > piece->y_axis && board2[y][x] == NULL && y <= 7 &&
                x == piece->x_axis)
                return 1;//dos movimientos si el peon no se ha movido
            else {
                return 0;
            }
        }

        if (piece->mvs > 0) {
            if (y == piece->y_axis + 1 && y > piece->y_axis && y <= 7 && board2[y][x] == NULL &&
                x == piece->x_axis)//Un movimiento hacia arriba si ya se movio
                return 1;
            else {
                return 0;
            }
        }
    }
}

int is_king_safe(struct piece ***board2, struct gamestate *game, int opt) {//Función que verifica si el rey está en jaque

    int y_w_king=0;
    int x_w_king=0;
    int x_b_king=0;
    int y_b_king=0;
    int Is_safe=0;
    for (int i = 0; i < 8; i++)
    {
        for (int i2 = 0; i2 < 8; i2++)
        {
            if(board2[i][i2]!=NULL){
                if (board2[i][i2]->piece_type=='K')
                {
                    x_b_king=board2[i][i2]->x_axis;
                    y_b_king=board2[i][i2]->y_axis;

                }
                if (board2[i][i2]->piece_type=='k')
                {
                    x_w_king=board2[i][i2]->x_axis;
                    y_w_king=board2[i][i2]->y_axis;
                }
            }
        }

    }

    if(game->turn==1){

        int a=0;
        int count=0;
        while (game->Negras[count]!=NULL && count<16)
        {   //printf("cont %i\n",count);

            if(game->Negras[count]->piece_type=='P'){

                //  puts("entre P");
                a=Black_Pawn(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //  printf("a es %i \n",a);
            }
            if(game->Negras[count]->piece_type=='T'){
                //puts("entre T");
                a=torre(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }

            if(game->Negras[count]->piece_type=='C'){
                //puts("entre C");
                a=caballo(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }

            if(game->Negras[count]->piece_type=='R'){
                //puts("entre R");
                a=reyna(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //   printf("a es %i \n",a);
            }
            if(game->Negras[count]->piece_type=='A'){
                //puts("entre A");
                a=alfil(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }
            if(game->Negras[count]->piece_type=='K'){
                //puts("entre k");

                a=king(board2[game->Negras[count]->y_axis][game->Negras[count]->x_axis],x_w_king,y_w_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }
            count++;
        }
        return a;

    }

    if (game->turn==2)
    {
        int count=0;
        int a=0;
        while (game->blancas[count]!=NULL && count<16)
        {

            if(game->blancas[count]->piece_type=='p'){
                //puts("entre negras");

                int a=White_Pawn(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }
            if(game->blancas[count]->piece_type=='t'){
                //puts("entre negras");
                int a=torre(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2 );
                if(a==2) return 3;
                //printf("a es %i \n",a);
            }

            if(game->blancas[count]->piece_type=='c'){
                //    puts("entre negras");
                int a=caballo(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2  );
                if(a==2)return 3;
                // printf("a es %i \n",a);
            }
            if(game->blancas[count]->piece_type=='r'){
                //puts("entre negras");
                int a=reyna(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }
            if(game->blancas[count]->piece_type=='a'){
                //puts("entre negras");
                int a=alfil(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2  );
                if(a==2)return 3;
                // printf("a es %i \n",a);
            }
            if(game->blancas[count]->piece_type=='k'){
                //puts("entre negras");
                int a=king(board2[game->blancas[count]->y_axis][game->blancas[count]->x_axis],x_b_king,y_b_king,board2 );
                if(a==2)return 3;
                //printf("a es %i \n",a);
            }

            count++;
        }

        return a;
    }







}



void print_board(struct piece ***board2) {//Función que imprime el tablero de ajedrez

    for (int a = 0;
         a < 9; a++) {//Se recorre el tablero y dependiendo si encuentra una pieza o un espacio vacio los imprime

        puts("\n");
        printf("%iY", a);
        for (int b = 0; b < 8; b++) {
            if (a < 8) {
                if (board2[a][b] == NULL && a < 8) {
                    printf(" X- ");
                } else if (a < 8 && board2[a][b] != NULL) {
                    printf(" %c- ", board2[a][b]->piece_type);
                }
            }

            if (a == 8) {
                printf(" X%i ", b);
            }
        }
    }
}


int White_Pawn(struct piece *piece, int x, int y, struct piece ***board2) {
    //Esta funcion recibe la referencia de una pieza y  verifica si la coordenada deseada es valida para moverse retorna 0 para movs no validos 1 para movs validos y 2 para comer piezas


    if (piece->piece_type == 'p') {

        if (y == piece->y_axis - 1 && x == piece->x_axis + 1 && x >= 0 && y >= 0 && x <= 7 && y <= 7) {
            if (board2[y][x] == NULL)return 0;//commer derecha
            if (board2[y][x] != NULL && board2[y][x]->color != piece->color)return 2;
            if (board2[y][x] != NULL && board2[y][x]->color == piece->color)return 0;
        }

        if (y == piece->y_axis - 1 && x == piece->x_axis - 1 && x >= 0 && y >= 0 && x <= 7 && y <= 7) {
            if (board2[y][x] == NULL)return 0;//comer izquierda
            if (board2[y][x]->color != piece->color)return 2;
            if (board2[y][x]->color == piece->color)return 0;
        }

        if (piece->mvs == 0) {
            if (y == piece->y_axis - 2 && y < piece->y_axis && board2[y][x] == NULL && y >= 0 &&
                x == piece->x_axis)
                return 1;
            if (y == piece->y_axis - 1 && y < piece->y_axis && board2[y][x] == NULL && y >= 0 &&
                x == piece->x_axis)
                return 1;//dos movimientos si el peon no se ha movido

            else {
                return 0;
            }
        }

        if (piece->mvs > 0) {
            if (y == piece->y_axis - 1 && y < piece->y_axis && y >= 0 && board2[y][x] == NULL &&
                x == piece->x_axis)
                return 1;

            else {
                return 0;
            }
        }
    }
}


int caballo(struct piece *piece, int x, int y, struct piece ***board2) {//Movimiento del caballo

    if (piece->piece_type == 'c' || piece->piece_type == 'C') {


        if (x > 7 || x < 0 || y > 7 || y < 0)return 0;

        if (x == piece->x_axis - 2 && y == piece->y_axis - 1) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis + 1 && y == piece->y_axis - 2) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis - 1 && y == piece->y_axis - 2) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->piece_type != piece->piece_type)return 2;
            }
        }

        if (x == piece->x_axis - 2 && y == piece->y_axis + 1) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis - 2 && y == piece->y_axis - 1) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis + 2 && y == piece->y_axis - 1) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis + 2 && y == piece->y_axis + 1) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis + 1 && y == piece->y_axis + 2) {
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }

        if (x == piece->x_axis - 1 && y == piece->y_axis + 2) {

            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color)return 2;
            }
        }
    }
}


int king(struct piece *piece, int x, int y, struct piece ***board2) {//Movimiento del rey
    if (piece->piece_type == 'k' || piece->piece_type == 'K') {


        if (x > 7 || x < 0 || y > 7 || y < 0)return 0;

        if (piece->x_axis + 1 == x && piece->y_axis == y) {
            //uno hacia derecha
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }
        if (piece->x_axis - 1 == x && piece->y_axis == y) {
            //izquierda
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis == x && piece->y_axis + 1 == y) {
            //uno para arriba
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis == x && piece->y_axis - 1 == y) {
            //uno para abajo-
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis + 1 == x && piece->y_axis + 1 == y) {
            //diagonal derecha
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis - 1 == x && piece->y_axis + 1 == y) {
            //diagonal izquierda
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis + 1 == x && piece->y_axis - 1 == y) {
            //diagonal para abajo derecha
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        }

        if (piece->x_axis - 1 == x && piece->y_axis - 1 == y) {
            //diagonal para abajo izquierda
            if (board2[y][x] == NULL)return 1;
            if (board2[y][x] != NULL) {
                if (board2[y][x]->color == piece->color)return 0;
                if (board2[y][x]->color != piece->color) return 1;
            }
        } else {
            return 0;
        }
    }
}

void init_game(struct piece ***board2) {

    //esta funcion recibe un apuntador triple o un arreglo de apuntadores dobles osea un arreglo de 2D que guarda referencias a nuestras piezas

    for (int a = 0; a < 8; a++) {

        for (int b = 0; b < 8; b++) {

            if (a == 0 && b == 0 || a == 0 && b == 7) {

                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->piece_type = 'T';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;//Torres
            }

            if (a == 0 && b == 1 || a == 0 && b == 6) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->piece_type = 'C';
                caster->mvs = 0;//caballos
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;
            }

            if (a == 0 && b == 2 || a == 0 && b == 5) {
                //alfiles
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->mvs = 0;
                caster->piece_type = 'A';
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;
            }

            if (a == 0 && b == 3) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->piece_type = 'R';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //rey
            }

            if (a == 0 && b == 4) {

                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->piece_type = 'K';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //reyna
            }
            if (a == 1) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'B';
                caster->piece_type = 'P';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //peones
            }

            if (a == 6) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->piece_type = 'p';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //peones
            }

            if (a == 7 && b == 0 || a == 7 && b == 7) {

                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->piece_type = 't';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;//Torres
            }

            if (a == 7 && b == 1 || a == 7 && b == 6) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->piece_type = 'c';
                caster->mvs = 0;//caballos
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;

            }

            if (a == 7 && b == 2 || a == 7 && b == 5) {
                //alfiles

                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->mvs = 0;
                caster->piece_type = 'a';
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster;
            }

            if (a == 7 && b == 3) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->piece_type = 'k';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //reye
            }

            if (a == 7 && b == 4) {
                struct piece *caster = malloc(sizeof(struct piece));
                caster->color = 'W';
                caster->piece_type = 'r';
                caster->mvs = 0;
                caster->y_axis = a;
                caster->x_axis = b;
                *(board2[a] + b) = caster; //reyna
            }

            if (a == 2 || a == 3 || a == 4 || a == 5) {
                *(board2[a] + b) = NULL;
            }
        }
    }
}

void copiar_tablero(struct piece ***source, struct piece ***destination) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (source[i][j] != NULL) {
                destination[i][j] = malloc(sizeof(struct piece));
                *destination[i][j] = *source[i][j];
            } else {
                if (destination[i][j] != NULL) {
                    free(destination[i][j]);
                    destination[i][j] = NULL;
                }
            }
        }
    }
}


struct piece ***create_empty_board() {
    struct piece ***board = malloc(sizeof(struct piece **) * 8);
    for (int i = 0; i < 8; ++i) {
        board[i] = malloc(sizeof(struct piece *) * 8);
        for (int j = 0; j < 8; ++j) {
            board[i][j] = NULL;
        }
    }

    return board;
}



void coppy_board(struct piece ***board2,struct piece ***target){
    puts("entre a la funcion cppy");
    for (int i = 0; i < 8; i++)
    {
        for (int i2 = 0; i2 < 8; i2++)
        {
            if(board2[i][i2]!=NULL){
                printf("pieza %c\n",board2[i][i2]->piece_type);
                struct piece * caster=malloc(sizeof(struct piece));
                caster->piece_type=board2[i][i2]->piece_type;
                caster->mvs=board2[i][i2]->mvs;
                caster->color= board2[i][i2]->color;
                caster->x_axis=board2[i][i2]->x_axis;
                caster->y_axis=board2[i][i2]->y_axis;
                *(target[i]+i2)=caster;
            }
            if (board2[i][i2]==NULL)
            {
                target[i][i2]==NULL;
            }

        }

    }





}

void clean_board(struct piece ***board2){

    for (int i = 0; i < 8; i++)
    {
        for (int i2 = 0; i2 < 8; i2++)
        {
            if(board2[i][i2]!=NULL){
                free(board2[i][i2]);
                board2[i][i2]=NULL;
            }
        }

    }


}


