#include <stdio.h>
#include "funcionario.h"
#include "empresa.h"



/*
1 -> numero de empresas a ser cadastradas

1 3  -> id da empresa e quantidade de funcionarios a serem cadastrados
25 3000 -> id do funcionario e salario
20 500 -> id do funcionario e salario
25 4700 -> id do funcionario e salario 


*/
/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id)
{
    tEmpresa e;
   
    e.id = id;
    e.qtdFuncionarios = 0;
    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa()
{
    tEmpresa e;
    tFuncionario f;
    int qtd, i, id;
    scanf("%d %d", &id, &qtd);

    e = criaEmpresa(id);

    for(i =0; i < qtd; i++)
    {
        f = leFuncionario();
        e = contrataFuncionarioEmpresa(e,f);
    }

    return e;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
@brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    int i, jaExiste=0;
    for (i= 0; i < empresa.qtdFuncionarios; i++)
    {
        if(getIdFuncionario(funcionario) == getIdFuncionario(empresa.funcionarios[i]))
        {
            jaExiste=1;
        }
            
    }

    if(jaExiste == 1)
    {
        printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
    }
        
    else
    {
        empresa.funcionarios[i] = funcionario;
        empresa.qtdFuncionarios++;
       
    }
     return empresa; 
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa)
{
    // printf("%d %d\n", empresa.id, empresa.qtdFuncionarios);
    printf("Empresa %d:\n", empresa.id);
    for (int i=0; i<empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}

