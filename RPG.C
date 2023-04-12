#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declarar variables
    char nombre[20];
    int hp, arma, daño_arma, situacion_1, situacion_2;
    int op, op_1, op_2, Monedas;

    // Pedir el nombre del héroe o heroína
    printf("Ingresa el nombre de tu héroe o heroína: ");
    scanf("%s", nombre);

    // Definir la vida del héroe o HP
    hp = 200;
    Monedas = 100;

    // Pedir que el héroe o heroína elija entre 3 armas
    printf("\nElige un arma: \n");
    printf("1. Hacha (daño: 50)\n");
    printf("2. Espada (daño: 40)\n");
    printf("3. Arco (daño: 30)\n");
    printf("Elige una opción: ");
    scanf("%d", &arma);

    // Guardar el daño del arma elegida por el héroe o heroína
    switch (arma) {
        case 1:
            daño_arma = 50;
            break;
        case 2:
            daño_arma = 40;
            break;
        case 3:
            daño_arma = 30;
            break;
        default:
            printf("Opción inválida. Se usará el hacha como arma.\n");
            daño_arma = 50;
            arma = 1;
            break;
    }

    // Generar dos situaciones aleatorias
    srand(time(NULL));
    situacion_1 = rand() % 5 + 1;
    situacion_2 = rand() % 5 + 1;
   
    printf("\nlas situaciones son: %d\n",situacion_1);
    printf("\nlas situaciones son: %d\n",situacion_2);


    switch (situacion_1) {
        case 1:
            printf("\nTe encuentras con un Golem de Piedra.\n");
            printf("¿Qué quieres hacer?\n");
            printf("1. Pelear\n");
            printf("2. Huir\n");
            printf("Elige una opción: ");
            scanf("%d", &op_1);
            if (op_1 == 1) {
                printf("¡Has derrotado al Golem de Piedra con tu %s!\n", arma == 1 ? "hacha" : arma == 2 ? "espada" : "arco");
                printf("Pierdes 10 puntos de vida.\n");
                hp -= 10;
            } else if (op_1 == 2) {
                printf("Has logrado escapar, pero has perdido 20 puntos de vida.\n");
                hp -= 20;
            } else {
                printf("Opción inválida. Has perdido 10 puntos de vida.\n");
                hp -= 10;
            }
            break;
        case 2:
            printf("\nTe encuentras con una manada de lobos.\n");
            printf("¿Qué quieres hacer?\n");
            printf("1. Pelear\n");
            printf("2. Huir\n");
        printf("Elige una opción: ");
        scanf("%d", &op_1);
        if (op_1 == 1) {
            printf("¡Has derrotado a los lobos con tu %s!\n", arma == 1 ? "hacha" : arma == 2 ? "espada" : "arco");
            printf("Ganas 20 monedas.\n");
            Monedas += 20;
        } else if (op_1 == 2) {
            printf("Has logrado escapar, pero has perdido 5 puntos de vida.\n");
            hp -= 5;
         } else {
            printf("Opción inválida. Has perdido 5 puntos de vida.\n");
            hp -= 5;
          }
          break;
        case 3:
          printf("\nTe encuentras con un comerciante.\n");
          printf("¿Qué quieres hacer?\n");
          printf("1. Comprar\n");
          printf("2. Vender\n");
          printf("3. No hacer nada\n");
        printf("Elige una opción: ");
        scanf("%d", &op_1);
        if (op_1 == 1) {
            printf("El comerciante tiene estas opciones:\n");
            printf("1. Poción de salud (+50 HP) - 30 monedas\n");
            printf("2. Mejora de arma (+10 daño) - 50 monedas\n");
            printf("3. Poción de maná (+20 daño al arma) - 20 monedas\n");
            printf("Elige una opción: ");
            scanf("%d", &op_2);
            switch (op_2) {
                case 1:
                    if (Monedas >= 30) {
                        printf("Compraste una poción de salud. +50 HP\n");
                        hp += 50;
                        Monedas -= 30;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                case 2:
                    if (Monedas >= 50) {
                        printf("Compraste una mejora de arma. +10 daño al arma\n");
                        daño_arma += 10;
                        Monedas -= 50;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                case 3:
                    if (Monedas >= 20) {
                        printf("Compraste una poción de maná. +20 daño al arma\n");
                        daño_arma += 20;
                        Monedas -= 20;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                default:
                    printf("Opción inválida.\n");
                    break;
            }
        } else if (op_1 == 2) {
            printf("El comerciante te ofrece:\n");
            printf("1. Poción de salud (+50 HP) - 10 monedas\n");
            printf("2. Arma usada (-10 daño) - 20 monedas\n");
            printf("3. Poción de maná (+10 daño al arma) - 15 monedas\n");
            printf("Elige una opción: ");
            scanf("%d", &op_2);
            switch (op_2) {
            case 2:
                if (Monedas >= 50) {
                    printf("Compraste una mejora de arma. +10 de daño\n");
                    daño_arma += 10;
                    Monedas -= 50;
                } else {
                    printf("No tienes suficientes monedas.\n");
                }
                break;
            case 3:
                if (Monedas >= 20) {
                    printf("Compraste una poción de maná. +20 de daño al arma\n");
                    daño_arma += 20;
                    Monedas -= 20;
                } else {
                    printf("No tienes suficientes monedas.\n");
                }
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } else if (op_1 == 2) {
        printf("El comerciante no está interesado en comprar nada.\n");
    } else if (op_1 == 3) {
        printf("No haces nada.\n");
    } else {
        printf("Opción inválida.\n");
    }
    break;
    case 4:
    printf("\nTe encuentras con una bruja.\n");
    printf("¿Qué quieres hacer?\n");
    printf("1. Pedir ayuda\n");
    printf("2. Atacarla\n");
    printf("Elige una opción: ");
    scanf("%d", &op_1);
    if (op_1 == 1) {
        if (Monedas >= 50) {
            printf("La bruja te ayuda a recuperar tus puntos de vida. +30 HP\n");
            hp += 30;
            Monedas -= 50;
        } else {
            printf("No tienes suficientes monedas.\n");
        }
    } else if (op_1 == 2) {
        printf("Atacas a la bruja, pero ella es más poderosa de lo que pensabas.\n");
        printf("Pierdes 40 puntos de vida.\n");
        hp -= 40;
    } else {
        printf("Opción inválida.\n");
    }
    break;
case 5:
    printf("\nTe encuentras con un tesoro.\n");
    printf("¿Qué quieres hacer?\n");
    printf("1. Tomarlo\n");
    printf("2. Dejarlo\n");
    printf("Elige una opción: ");
    scanf("%d", &op_1);
    if (op_1 == 1) {
        printf("Obtienes 50 monedas.\n");
        Monedas += 50;
    } else if (op_1 == 2) {
        printf("No tomas el tesoro.\n");
    } else {
        printf("Opción inválida.\n");
    }
    break;
default:
    printf("No pasa nada interesante.\n");
    break;
}

// Imprimir la vida y las monedas del héroe o heroína
printf("\n%s tiene %d puntos de vida y %d monedas.\n", nombre, hp, Monedas);

      switch (situacion_1) {
        case 1:
            printf("\nTe encuentras con un Golem de Piedra.\n");
            printf("¿Qué quieres hacer?\n");
            printf("1. Pelear\n");
            printf("2. Huir\n");
            printf("Elige una opción: ");
            scanf("%d", &op_1);
            if (op_1 == 1) {
                printf("¡Has derrotado al Golem de Piedra con tu %s!\n", arma == 1 ? "hacha" : arma == 2 ? "espada" : "arco");
                printf("Pierdes 10 puntos de vida.\n");
                hp -= 10;
            } else if (op_1 == 2) {
                printf("Has logrado escapar, pero has perdido 20 puntos de vida.\n");
                hp -= 20;
            } else {
                printf("Opción inválida. Has perdido 10 puntos de vida.\n");
                hp -= 10;
            }
            break;
        case 2:
            printf("\nTe encuentras con una manada de lobos.\n");
            printf("¿Qué quieres hacer?\n");
            printf("1. Pelear\n");
            printf("2. Huir\n");
        printf("Elige una opción: ");
        scanf("%d", &op_1);
        if (op_1 == 1) {
            printf("¡Has derrotado a los lobos con tu %s!\n", arma == 1 ? "hacha" : arma == 2 ? "espada" : "arco");
            printf("Ganas 20 monedas.\n");
            Monedas += 20;
        } else if (op_1 == 2) {
            printf("Has logrado escapar, pero has perdido 5 puntos de vida.\n");
            hp -= 5;
         } else {
            printf("Opción inválida. Has perdido 5 puntos de vida.\n");
            hp -= 5;
          }
          break;
        case 3:
          printf("\nTe encuentras con un comerciante.\n");
          printf("¿Qué quieres hacer?\n");
          printf("1. Comprar\n");
          printf("2. Vender\n");
          printf("3. No hacer nada\n");
        printf("Elige una opción: ");
        scanf("%d", &op_1);
        if (op_1 == 1) {
            printf("El comerciante tiene estas opciones:\n");
            printf("1. Poción de salud (+50 HP) - 30 monedas\n");
            printf("2. Mejora de arma (+10 daño) - 50 monedas\n");
            printf("3. Poción de maná (+20 daño al arma) - 20 monedas\n");
            printf("Elige una opción: ");
            scanf("%d", &op_2);
            switch (op_2) {
                case 1:
                    if (Monedas >= 30) {
                        printf("Compraste una poción de salud. +50 HP\n");
                        hp += 50;
                        Monedas -= 30;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                case 2:
                    if (Monedas >= 50) {
                        printf("Compraste una mejora de arma. +10 daño al arma\n");
                        daño_arma += 10;
                        Monedas -= 50;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                case 3:
                    if (Monedas >= 20) {
                        printf("Compraste una poción de maná. +20 daño al arma\n");
                        daño_arma += 20;
                        Monedas -= 20;
                    } else {
                        printf("No tienes suficientes monedas.\n");
                    }
                    break;
                default:
                    printf("Opción inválida.\n");
                    break;
            }
        } else if (op_1 == 2) {
            printf("El comerciante te ofrece:\n");
            printf("1. Poción de salud (+50 HP) - 10 monedas\n");
            printf("2. Arma usada (-10 daño) - 20 monedas\n");
            printf("3. Poción de maná (+10 daño al arma) - 15 monedas\n");
            printf("Elige una opción: ");
            scanf("%d", &op_2);
            switch (op_2) {
            case 2:
                if (Monedas >= 50) {
                    printf("Compraste una mejora de arma. +10 de daño\n");
                    daño_arma += 10;
                    Monedas -= 50;
                } else {
                    printf("No tienes suficientes monedas.\n");
                }
                break;
            case 3:
                if (Monedas >= 20) {
                    printf("Compraste una poción de maná. +20 de daño al arma\n");
                    daño_arma += 20;
                    Monedas -= 20;
                } else {
                    printf("No tienes suficientes monedas.\n");
                }
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } else if (op_1 == 2) {
        printf("El comerciante no está interesado en comprar nada.\n");
    } else if (op_1 == 3) {
        printf("No haces nada.\n");
    } else {
        printf("Opción inválida.\n");
    }
    break;
    case 4:
    printf("\nTe encuentras con una bruja.\n");
    printf("¿Qué quieres hacer?\n");
    printf("1. Pedir ayuda\n");
    printf("2. Atacarla\n");
    printf("Elige una opción: ");
    scanf("%d", &op_1);
    if (op_1 == 1) {
        if (Monedas >= 50) {
            printf("La bruja te ayuda a recuperar tus puntos de vida. +30 HP\n");
            hp += 30;
            Monedas -= 50;
        } else {
            printf("No tienes suficientes monedas.\n");
        }
    } else if (op_1 == 2) {
        printf("Atacas a la bruja, pero ella es más poderosa de lo que pensabas.\n");
        printf("Pierdes 40 puntos de vida.\n");
        hp -= 40;
    } else {
        printf("Opción inválida.\n");
    }
    break;
case 5:
    printf("\nTe encuentras con un tesoro.\n");
    printf("¿Qué quieres hacer?\n");
    printf("1. Tomarlo\n");
    printf("2. Dejarlo\n");
    printf("Elige una opción: ");
    scanf("%d", &op_1);
    if (op_1 == 1) {
        printf("Obtienes 50 monedas.\n");
        Monedas += 50;
    } else if (op_1 == 2) {
        printf("No tomas el tesoro.\n");
    } else {
        printf("Opción inválida.\n");
    }
    break;
default:
    printf("No pasa nada interesante.\n");
    break;
}

// Imprimir la vida y las monedas del héroe o heroína
printf("\n%s tiene %d puntos de vida y %d monedas.\n", nombre, hp, Monedas);
printf("*******");
printf("graacis por jugar");
printf("*******");

return 0;
  
}