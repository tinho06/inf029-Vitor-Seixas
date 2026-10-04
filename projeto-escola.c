#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 3

typedef struct data{
    int dia;
    int mes;
    int ano;
    
    }data;

typedef struct aluno{
    char cpf_aluno[12];
    char matricula_aluno[60];
    char nome_aluno[60];
    data nascimento_aluno;

    }aluno;

typedef struct professor{
    char cpf_prof[12];
    char matricula_prof[60];
    char nome_prof[60];
    data nascimento_prof;
    
    }professor;

typedef struct disciplina{
    char codigo[60];
    int semestre;
    char nome_dis[60];
    professor prof_da_disciplina;

    }disciplina;

void cadastra_aluno(aluno a0[], int i1){

    printf("nome do aluno:\n");
    fgets(a0[i1].nome_aluno, sizeof(a0[i1].nome_aluno), stdin);
    printf("matricula do aluno:\n");
    scanf("%s", a0[i1].matricula_aluno);
    printf("cpf do aluno:\n");
    scanf("%s", a0[i1].cpf_aluno);
    getchar();
}
               
void cadastra_prof(professor p0[], int j1){
    
    printf("nome do professor:\n");
    fgets(p0[j1].nome_prof, sizeof(p0[j1].nome_prof), stdin);
    printf("matricula do professor:\n");
    scanf("%s", p0[j1].matricula_prof);
    printf("cpf do professor:\n");
    scanf("%s", p0[j1].cpf_prof);
    getchar();
}                        
                
void cadastra_disciplina(disciplina d0[], int k1){

    printf("nome da disciplina:\n");
    fgets(d0[k1].nome_dis, sizeof(d0[k1].nome_dis), stdin);
    printf("codigo da disciplina:\n");
    scanf("%s", d0[k1].codigo);
    printf("semestre da disciplina:\n");
    scanf("%d", &d0[k1].semestre);
    getchar();
    cadastra_prof(&d0[k1].prof_da_disciplina, 0); 
}

void exclui_dis(int exclusao_dis0, int k2, disciplina d2[]){
        
        disciplina auxd;

        for(int i0 = exclusao_dis0; i0 < k2 && i0 + 1 < k2; i0++){
            auxd = d2[i0 + 1];
            d2[i0 + 1] = d2[i0];
            d2[i0] = auxd; 
        }
            
    }

void exclui_prof(int exclusao_prof0, int j2, professor p2[]){
        
        professor auxp;

        for(int i0 = exclusao_prof0; i0 < j2 && i0 + 1 < j2; i0++){
            auxp = p2[i0 + 1];
            p2[i0 + 1] = p2[i0];
            p2[i0] = auxp; 
        }
            
    }

void exclui_aluno(int exclusao_aluno0, int i2, aluno a2[]){
        
        aluno auxa;

        for(int i0 = exclusao_aluno0; i0 < i2 && i0 + 1 < i2; i0++){
            auxa = a2[i0 + 1];
            a2[i0 + 1] = a2[i0];
            a2[i0] = auxa; 
        }
            
    }   

int valida_aluno(int i4){
    int nao_sei1 = 0;
    if(i4 == 0){
        nao_sei1 = 1; /*vazio*/
    }
    else if(i4 == CAPACIDADE){
        nao_sei1 = 2; /*cheio*/
    }
    return nao_sei1;

}

int valida_prof(int j4){
    int nao_sei2 = 0;
    if(j4 == 0){
        nao_sei2 = 1; /*vazio*/
    }
    else if(j4 == CAPACIDADE){
        nao_sei2 = 2; /*cheio*/
    }
    return nao_sei2;

}

int valida_dis(int k4){
    int nao_sei3 = 0;
    if(k4 == 0){
        nao_sei3 = 1; /*vazio*/
    }
    else if(k4 == CAPACIDADE){
        nao_sei3 = 2; /*cheio*/
    }
    return nao_sei3;

}

void lista_aluno(aluno a3[], int i3){

    int contA = 0;
    if (i3 == 0){
        printf("nenhum aluno cadastrado");
    
    }
    
    else{

        for (int limite = 0; limite < i3; limite ++ ){
            printf("%d- %s\n%s\n%s\n\n", contA, a3[limite].nome_aluno, a3[limite].cpf_aluno, a3[limite].matricula_aluno);
            contA++;
        }

    }


}

void lista_prof(professor p3[], int j3){

    int contP = 0;
    if (j3 == 0){
        printf("nenhum professor cadastrado");
    
    }
    
    else{

        for (int limite = 0; limite < j3; limite ++ ){
            printf("%d- %s\n%s\n%s\n\n", contP, p3[limite].nome_prof, p3[limite].cpf_prof, p3[limite].matricula_prof);
            contP++;
        }

    }


}

void lista_dis(disciplina d3[], int k3){

    int contD = 0;
    if (k3 == 0){
        printf("nenhuma disciplina cadastrada");
    
    }
    
    else{

        for (int limite = 0; limite < k3; limite ++ ){
            printf("%d- %s\nCodigo: %s\nSemestre: %d\nProfessor: %s %s %s\n\n", contD, d3[limite].nome_dis, d3[limite].codigo, d3[limite].semestre, d3[limite].prof_da_disciplina.nome_prof, d3[limite].prof_da_disciplina.matricula_prof, d3[limite].prof_da_disciplina.cpf_prof);
            contD++;
        }

    }


}

int main(){

    disciplina d1[CAPACIDADE];
    professor p1[CAPACIDADE];
    aluno a1[CAPACIDADE];
    int opcao_menu;
    int opcao_cadastro_prof2;
    int opcao_cadastro_aluno2;
    int opcao_cadastro_dis2;
    int opcao_cadastro;
    int menu_listar;
    int atualizacao_aluno;
    int atualizacao_prof;
    int atualizacao_dis;
    int exclusao_aluno;
    int exclusao_prof;
    int exclusao_dis;
    int aluno_valido;
    int prof_valido;
    int dis_valido;
    int sair_menu = 0;
    int ii = 0;
    int jj = 0;
    int kk = 0;

    while(!sair_menu){
        printf("menu:\n0- Cadastro\n1- Relatorios:\n2- sair\n");
        scanf("%d", &opcao_menu);

        switch(opcao_menu){

            case 0:
                printf("0- Cadastro de aluno\n1- Cadastro de professor\n2- Cadastro de disciplina\n3- voltar\n");
                scanf("%d", &opcao_cadastro);
                getchar();

                switch(opcao_cadastro){
                    case 0:
                        printf("1- incluir aluno\n2- atualizar aluno\n3- excluir aluno:\n");
                        scanf("%d", &opcao_cadastro_aluno2);
                        getchar();
                        switch(opcao_cadastro_aluno2){
                        
                            case 1:
                                aluno_valido = valida_aluno(ii);
                                if(aluno_valido < 2){
                                    cadastra_aluno(a1, ii);
                                    ii++;
                                    break;
                                }

                                else{
                                    printf("limite de alunos atingido!");
                                    break;
                                }

                            case 2:
                                aluno_valido = valida_aluno(ii);
                                if(aluno_valido != 1){
                                    printf("digite o numero correspondente ao aluno que deseja atualizar:\n");
                                    lista_aluno(a1, ii);
                                    scanf("%d", &atualizacao_aluno);
                                    getchar();
                                    cadastra_aluno(a1, atualizacao_aluno);
                                    break;
                                }
                                
                                else{
                                    printf("nenhum aluno cadastrado");
                                }

                                break;
                            case 3:
                                aluno_valido = valida_aluno(ii);
                                if (aluno_valido != 1){
                                    printf("digite o numero correspondente ao aluno que deseja excluir:\n");
                                    lista_aluno(a1, ii);
                                    scanf("%d", &exclusao_aluno);
                                    exclui_aluno(exclusao_aluno, ii, a1);
                                    ii--;
                                    break;
                                }
                                
                                else{
                                    printf("nenhum aluno cadastrado");
                                    break;
                                }

                                }
                        break;
                    
                    case 1:
                        printf("1- incluir professor\n2- atualizar professor\n3- excluir professor:\n");
                        scanf("%d", &opcao_cadastro_prof2);
                        getchar();
                        switch(opcao_cadastro_prof2){
                        
                            case 1:
                                prof_valido = valida_prof(jj);
                                if(prof_valido < 2){
                                    cadastra_prof(p1, jj);
                                    jj++;
                                    break;
                                }

                                else{
                                    printf("limite de professores atingido!");
                                    break;
                                }

                            case 2:
                                prof_valido = valida_prof(jj);
                                if(prof_valido != 1){
                                    printf("digite o numero correspondente ao professor que deseja atualizar:\n");
                                    lista_prof(p1, jj);
                                    scanf("%d", &atualizacao_prof);
                                    getchar();
                                    cadastra_prof(p1, atualizacao_prof);
                                    break;
                                }
                                
                                else{
                                    printf("nenhum professor cadastrado");
                                    break;
                                }

                                break;
                            case 3:
                                prof_valido = valida_prof(jj);
                                if (prof_valido != 1){
                                    printf("digite o numero correspondente ao professor que deseja excluir:\n");
                                    lista_prof(p1, jj);
                                    scanf("%d", &exclusao_prof);
                                    exclui_prof(exclusao_prof, jj, p1);
                                    jj--;
                                    break;
                                }
                                
                                else{
                                    printf("nenhum professor cadastrado");
                                    break;
                                }

                                }
                        break;
                        
                        
                        

                    case 2:
                        printf("1- incluir disciplina\n2- atualizar disciplina\n3- excluir disciplina:\n");
                        scanf("%d", &opcao_cadastro_dis2);
                        getchar();
                        switch(opcao_cadastro_dis2){
                        
                            case 1:
                                dis_valido = valida_dis(kk);
                                if(dis_valido < 2){
                                    cadastra_disciplina(d1, kk);
                                    kk++;
                                    break;
                                }

                                else{
                                    printf("limite de disciplinas atingido!");
                                    break;
                                }

                            case 2:
                                dis_valido = valida_dis(kk);
                                if(dis_valido != 1){
                                    printf("digite o numero correspondente a disciplina que deseja atualizar:\n");
                                    lista_dis(d1, kk);
                                    scanf("%d", &atualizacao_dis);
                                    getchar();
                                    cadastra_disciplina(d1, atualizacao_dis);
                                    break;
                                }
                                
                                else{
                                    printf("nenhuma disciplina cadastrada");
                                    break;
                                }

                                break;
                            case 3:
                                dis_valido = valida_dis(kk);
                                if (dis_valido != 1){
                                    printf("digite o numero correspondente a disciplina que deseja excluir:\n");
                                    lista_dis(d1, kk);
                                    scanf("%d", &exclusao_dis);
                                    exclui_dis(exclusao_dis, kk, d1);
                                    kk--;
                                    break;
                                }
                                
                                else{
                                    printf("nenhuma disciplina cadastrada");
                                    break;
                                }

                                }
                        break;
                        
                        
                        

                }
                break;
            
            case 1:
                printf("1- listar alunos\n2- listar professores\n3- listar disciplinas\n");
                scanf("%d", &menu_listar);
                switch(menu_listar){
                    case 1:
                        lista_aluno(a1, ii);
                        break;

                    case 2:
                        lista_prof(p1, jj);
                        break;

                    case 3:
                        lista_dis(d1, kk);
                        break;
                }
                break;
            case 2:
            sair_menu = 1;
            break;
        }

    }

    return 0;

}
