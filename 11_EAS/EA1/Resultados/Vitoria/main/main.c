#include <stdio.h>
#include "emprestimo.h"
#include "usuario.h"
#include "livro.h"

#define MAX_TAM_LIVRO  3
#define MAX_TAM_USUARIO 20
#define MAX_TAM_EMPRESTIMO 100
int main()
{
    Livro livr[MAX_TAM_LIVRO];
    Usuario usuario[MAX_TAM_USUARIO];
    Emprestimo emprest[MAX_TAM_EMPRESTIMO];
    int qtd_livr= 0;
    int qtd_usuario = 0;
    int qtd_emprest = 0;

    char identificador;
    

    scanf("%c\n", &identificador);
    
    while (identificador != 'F')
    {
        if(identificador == 'L')
        {
            if(qtd_livr < MAX_TAM_LIVRO )
            {
                livr[qtd_livr] = leLivro();
                qtd_livr++;
            }
            else 
                leLivro();
        }
        else if(identificador == 'U')
        {
            if(qtd_usuario < MAX_TAM_USUARIO )
            {
                usuario[qtd_usuario] = leUsuario();
                qtd_usuario++;
            }
            else 
                leUsuario();
        }
        else if(identificador == 'E')
        {
            Data d;
            char cod[MAX_TAM_COD_LIVRO];
            char matri[MAX_TAM_MATRICULA_USUARIO];
            
            scanf("%[^\n]\n", cod);
            scanf("%[^\n]\n", matri);
            d = leData();
            
            int posLivro = -1;
            int posUsu = -1;
            int qtdEmpLivro = 0;
            int qtdEmpUsua = 0;
            int duplicado = 0;


            for(int i =0; i<qtd_livr; i++)
            {
                if(comparaCodigoLivro(livr[i], cod))
                {
                    posLivro = i;
                } 
            }
            for (int j=0; j<qtd_usuario; j++)
            {
                if(comparaMatriculaUsuario(usuario[j],matri))
                {
                    posUsu = j;
                }
            }
            
                for(int k = 0; k < qtd_emprest; k++)
            {
                if(comparaCodLivroEmprestimo(emprest[k], cod))
                {
                    qtdEmpLivro++;
                }

                if(comparaCodUsuarioEmprestimo(emprest[k], matri))
                {
                    qtdEmpUsua++;
                }

                if(comparaCodLivroEmprestimo(emprest[k], cod) &&
                   comparaCodUsuarioEmprestimo(emprest[k], matri) &&
                   comparaData(getDataEmprestimo(emprest[k]), d))
                {
                    duplicado = 1;
                }
            }

            if(posLivro != -1 && posUsu != -1 && qtd_emprest < MAX_TAM_EMPRESTIMO)
            {
                if(qtdEmpLivro < obterQuantidadeExemplaresLivro(livr[posLivro]) &&
                   qtdEmpUsua < obterLimiteEmprestimosUsuario(usuario[posUsu]) &&
                   duplicado == 0)
                {
                    emprest[qtd_emprest] = criaEmprestimo(d, cod, matri);
                    qtd_emprest++;
                }
            }
        
        }

        scanf("%c\n", &identificador);
    }
    
    printf("- - - EMPRESTIMOS - - -\n");
    for(int i = 0; i < qtd_emprest; i++)
    {
        imprimeEmprestimo(emprest[i]);
        printf("\n");
    }

    return 0;

}