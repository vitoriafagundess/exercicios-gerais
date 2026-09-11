#include <stdio.h>
#include "matrix_utils.h"

int main()
{

    int op, l1, c1, l2, c2;

    scanf("%d %d\n", &l1, &c1);
    int matriz1[l1][c1];
    matrix_read(l1, c1, matriz1);

    scanf("%d %d\n", &l2, &c2);
    int matriz2[l2][c2];
    matrix_read(l2, c2, matriz2);

    do
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: ");

        scanf("%d", &op);
        printf("\n");
        switch (op)
        {
        case 1:
            if (possible_matrix_sum(l1, c1, l2, c2))
            {
                int resultado[l1][c1];
                matrix_add(l1, c1, matriz1, l2, c2, matriz2, resultado);
                matrix_print(l1, c1, resultado);
            }
            else 
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 2:
            if (possible_matrix_sub(l1, c1, l2, c2))
            {
                int result[l1][c1];
                matrix_sub(l1, c1, matriz1, l2, c2, matriz2, result);
                matrix_print(l1, c1, result);
            }
            else 
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 3:
            if (possible_matrix_multiply(c1, l2))
            {
                int resull[l1][c2];
                matrix_multiply(l1, c1, matriz1, l2, c2, matriz2, resull);
                matrix_print(l1, c2, resull);
            }
            else 
            {
               printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            break;
        case 4:
            int v_escalar, m_select;
            scanf("%d %d", &v_escalar, &m_select);
            if (m_select == 1)
            {
                scalar_multiply(l1, c1, matriz1, v_escalar);
                matrix_print(l1, c1, matriz1);
            }
            else if (m_select == 2)
            {
                scalar_multiply(l2, c2, matriz2, v_escalar);
                matrix_print(l2, c2, matriz2);
            }
            break;
        case 5:
        {
            int r1[c1][l1], r2[c2][l2];
            transpose_matrix(l1, c1, matriz1, r1);
            transpose_matrix(l2, c2, matriz2, r2);
            matrix_print(c1, l1, r1);
            matrix_print(c2, l2, r2);
        }

        break;

        case 6:
            break;
        }

    } while (op != 6);
}