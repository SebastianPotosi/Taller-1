#include <stdio.h>;

int main() {
    int ascensor = 0; // El ascensor empieza en el piso 0 (planta baja)
    int opcion, piso, destino;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Llamar ascensor\n");
        printf("2. Seleccionar piso\n");
        printf("3. Mostrar piso actual\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el piso desde donde llama al ascensor (0-9): ");
                scanf("%d", &piso);

                if (ascensor == piso) {
                    printf("El ascensor ya se encuentra en el piso %d.\n", piso);
                } else {
                    printf("Ascensor en piso %d.\n", ascensor);
                    while (ascensor != piso) {
                        if (ascensor < piso) {
                            ascensor++;
                            printf("Ascensor en piso %d.\n", ascensor);
                        } else {
                            ascensor--;
                            printf("Ascensor en piso %d.\n", ascensor);
                        }
                    }
                    printf("El ascensor ha llegado al piso %d.\n", piso);
                }
                break;
            case 2:
                printf("Ingrese el piso al que desea ir (0-9): ");
                scanf("%d", &destino);

                if (ascensor == destino) {
                    printf("El ascensor ya se encuentra en el piso %d.\n", destino);
                } else {
                    printf("Ascensor en piso %d.\n", ascensor);
                    if (ascensor < destino) {
                        for (int i = ascensor + 1; i <= destino; i++) {
                            printf("Ascensor en piso %d.\n", i);
                        }
                    } else {
                        for (int i = ascensor - 1; i >= destino; i--) {
                            printf("Ascensor en piso %d.\n", i);
                        }
                    }
                    ascensor = destino;
                    printf("El ascensor ha llegado al piso %d.\n", destino);
                }
                break;
            case 3:
                switch(ascensor) {
                    case 0:
                        printf("El ascensor se encuentra en la planta baja.\n");
                        break;
                    case 1:
                        printf("El ascensor se encuentra en el primer piso.\n");
                        break;
                    case 2:
                        printf("El ascensor se encuentra en el segundo piso.\n");
                        break;
                    case 3:
                        printf("El ascensor se encuentra en el tercer piso.\n");
                        break;
                    default:
                        printf("El ascensor se encuentra en el piso %d.\n", ascensor);
                        break;
                }
                break;
            case 4:
                printf("Hasta luego.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
