#include <stdio.h>
#include <string.h>
#include "data.h"
#include "lesao.h"
#include "paciente.h"
int main(){
    Paciente pacientes[100];
    int qtdPacientes = 0;
    char tipo;
    scanf(" %c", &tipo);
    while(tipo != 'F'){
        if(tipo == 'P'){
            pacientes[qtdPacientes] = lerPaciente();
            qtdPacientes++;
        } else if(tipo == 'L'){
            Lesao l = lerLesao();
            char cartaoDaLesao[19];
            getCartaoSusLesao(l, cartaoDaLesao);
            for(int i=0;i<qtdPacientes;i++){
                char cartaoDoPaciente[19];
                getCartaoSusPaciente(pacientes[i], cartaoDoPaciente);
                if(strcmp(cartaoDoPaciente, cartaoDaLesao)==0){
                    pacientes[i] = vinculaLesaoPaciente(pacientes[i], l);
                    break;
                }
            }
        }
        scanf(" %c", &tipo);
    }
    printf("TOTAL PACIENTES: %d\n", qtdPacientes);
    if(qtdPacientes==0){
        printf("MEDIA IDADE (ANOS): -\n");
    } else {
        Data dataBase = criaData(12,9,2023);
        int soma=0;
        for(int i=0;i<qtdPacientes;i++) soma += calculaIdadePaciente(pacientes[i], dataBase);
        printf("MEDIA IDADE (ANOS): %d\n", soma/qtdPacientes);
    }
    int totalLesoes=0, totalCirurgias=0;
    for(int i=0;i<qtdPacientes;i++){
        totalLesoes += getNumLesoesPaciente(pacientes[i]);
        totalCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
    }
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for(int i=0;i<qtdPacientes;i++) imprimePaciente(pacientes[i]);
    return 0;
}