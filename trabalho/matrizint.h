#ifndef MATRIZ_INT_H
#define MATRIZ_INT_H

#include<iostream>

typedef struct{
    // Atributos
    int **valores; 
    int nLinhas;
    int nColunas;
    
    // Operação Construtora
    void inicializa(int linhas , int colunas){
        if (linhas > 0 && colunas > 0) {
            nLinhas = linhas; 
            nColunas = colunas;
            valores = new int*[linhas];
            for(int i=0; i<linhas; i++)
                valores[i] = new int[colunas];
        } else {
            nLinhas = 0;
            nColunas = 0;
        }
    }
    
    void inicializaComZero(int linhas , int colunas){
        inicializa(linhas, colunas);
        for(int i=0; i<nLinhas; i++)
            for(int j=0; j<nColunas; j++)
                valores[i][j] = 0;
    }
    
    // Operação Modificadora
    void atualizaMatriz(int linha, int coluna, int valor){
        if(( (linha >= 0) && (linha < nLinhas) )  && 
           ( (coluna>= 0) && (coluna< nColunas) ))
            valores[linha][coluna] = valor;
    }
    
    // Operação Analisadora
    int acessaMatriz(int linha, int coluna){
        if(( (linha >= 0) && (linha < nLinhas) ) && 
           ( (coluna>= 0) && (coluna< nColunas) ))
            return valores[linha][coluna];
        else
            return -1;
    }
    
    // Operação Analisadora
    void exibeMatriz(){ 
        for(int i=0; i < nLinhas; i++){
            for(int j=0; j < nColunas; j++)
                std::cout << valores[i][j] << " ";
            std::cout << "\n";
        }
    }
    
    // Operação Produtora
    int somaLinhaMatriz(int linha){
        int soma=0;
        for(int j=0; j < nColunas; j++)
            soma = soma + valores[linha][j];
        return soma;
    }
    
    // Operação Produtora
    int somaColunaMatriz(int coluna){
        int soma=0;
        for(int i=0; i < nLinhas; i++)
            soma = soma + valores[i][coluna];
        return soma;
    }
    
    // Operação Destrutora
    void finaliza(){
        if (valores){
            for(int i=0; i<nLinhas; i++)
                delete[] valores[i];
            delete[] valores;
            valores = NULL;
        }
    }
}tMatrizInt;

tMatrizInt produtoMatrizInt(const tMatrizInt &matriz1, const tMatrizInt &matriz2){
    tMatrizInt produto;
    produto.inicializa(0, 0);         
    if( matriz1.nColunas == matriz2.nLinhas ){         
		produto.inicializa(matriz1.nLinhas, matriz2.nColunas);         
        for(int i=0; i < matriz1.nLinhas; i++){
            for(int j=0; j < matriz2.nColunas; j++){ 
                produto.valores[i][j]=0;
                for(int k=0; k < matriz1.nColunas; k++){
                    produto.valores[i][j] += matriz1.valores[i][k] * matriz2.valores[k][j];
                } 
            }
        }
    }
    return produto; 
}
#endif