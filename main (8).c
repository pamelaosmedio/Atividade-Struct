#include <stdio.h>


struct Projeto {
    int numero;
    float saldo;
};


int obter_indice_projeto(struct Projeto projetos[], int num_projetos, int num_projeto) {
    for (int i = 0; i < num_projetos; i++) {
        if (projetos[i].numero == num_projeto) {
            return i;
        }
    }

    return -1;
}

int main() {
    int num_projetos;
    printf("Digite o numero de projetos: ");
    scanf("%d", &num_projetos);

    struct Projeto projetos[num_projetos];

   
    for (int i = 0; i < num_projetos; i++) {
        printf("Digite o numero do projeto %d: ", i+1);
        scanf("%d", &projetos[i].numero);
        projetos[i].saldo = 0.0;
    }

    char tipo_despesa;
    int num_projeto;
    float valor;
    int indice_projeto;
      while (1) {
        printf("Digite o número do projeto (ou zero para sair): ");
        scanf("%d", &num_projeto);
        if (num_projeto == 0) {
            break;
        }
  

        printf("Digite o valor: ");
        scanf("%f", &valor);

        printf("Digite o tipo de despesa (R para receita, D para despesa): ");
        scanf(" %c", &tipo_despesa);

        indice_projeto = obter_indice_projeto(projetos, num_projetos, num_projeto);

        
        if (indice_projeto == -1) {
            printf("Projeto não encontrado!\n");
        } else {
           
            if (tipo_despesa == 'R') {
                projetos[indice_projeto].saldo += valor;
            } else if (tipo_despesa == 'D') {
                projetos[indice_projeto].saldo -= valor;
            } else {
                printf("Tipo de despesa inválido!\n");
            }
        }
    }

  
    printf("Saldo final dos projetos:\n");
    for (int i = 0; i < num_projetos; i++) {
        printf("Projeto %d: %.2f\n", projetos[i].numero, projetos[i].saldo);
    }

    return 0;
}