#include <stdio.h>
#define TAM 5  

int main() {
    int codigos[TAM];
    float precios[TAM];
    int codigo_mayor = 0, codigo_menor = 0;
    float precio_mayor, precio_menor;

    printf("Ingrese %d productos, se solicitara el codigo y precio:\n\n", TAM);

    for (int i = 0; i < TAM; i++) {
        do {
            printf("Ingrese el codigo de barras (1-999999999): ");
            scanf("%d", &codigos[i]);
            if (codigos[i] < 1 || codigos[i] > 999999999) {
                printf("Error. El codigo de barras debe estar entre 1 y 999999999.\n");
            }
        } while (codigos[i] < 1 || codigos[i] > 999999999);
        do {
            printf("Ingrese el precio: ");
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error. El precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);

        printf("\n");
    }
    printf("\nCodigo\t\tPrecio\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d\t\t%.2f\n", codigos[i], precios[i]);
    }
    precio_mayor = precios[0];
    precio_menor = precios[0];
    codigo_mayor = codigos[0];
    codigo_menor = codigos[0];

    for (int i = 1; i < TAM; i++) {
        if (precios[i] > precio_mayor) {
            precio_mayor = precios[i];
            codigo_mayor = codigos[i];
        }
        if (precios[i] < precio_menor) {
            precio_menor = precios[i];
            codigo_menor = codigos[i];
        }
    }
    printf("\nMas caro: [%d] %.2f\n", codigo_mayor, precio_mayor);
    printf("Mas barato: [%d] %.2f\n", codigo_menor, precio_menor);

    return 0;
}