#ifndef MATRIZ_FLOAT_H
#define MATRIZ_FLOAT_H

#include<iostream>

typedef struct{
    // Atributos
    float **valores; 
    int nLinhas;
    int nColunas;
    
    // Operação Construtora
    void inicializa(int linhas , int colunas){
        if (linhas > 0 && colunas > 0) {
            nLinhas = linhas; 
            nColunas = colunas;
            valores = new float*[linhas];
            for(int i=0; i<linhas; i++)
                valores[i] = new float[colunas];
        } else {
            nLinhas = 0;
            nColunas = 0;
        }
    }
    
    void inicializaComZero(int linhas , int colunas){
        inicializa(linhas, colunas);
        for(int i=0; i<nLinhas; i++)
            for(int j=0; j<nColunas; j++)
                valores[i][j] = 0.0f;
    }
    
    // Operação Modificadora
    void atualizaMatriz(int linha, int coluna, float valor){
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
            return -1.0f;
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
    float somaLinhaMatriz(int linha){
        float soma=0.0;
        for(int j=0; j < nColunas; j++)
            soma = soma + valores[linha][j];
        return soma;
    }
    
    // Operação Produtora
    float somaColunaMatriz(int coluna){
        float soma=0;
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
}tMatrizFloat;

tMatrizFloat produtoMatrizFloat(const tMatrizFloat & matriz1, const tMatrizFloat & matriz2){
    tMatrizFloat produto;
    if( matriz1.nColunas == matriz2.nLinhas ){         
        for(int i=0; i < matriz1.nLinhas; i++){
            for(int j=0; j < matriz2.nColunas; j++){ 
                produto.valores[i][j]=0;
                for(int k=0; k < matriz1.nColunas; k++){
                    produto.valores[i][j] += matriz1.valores[i][k] * matriz2.valores[k][j];
                } 
            }
        }
        produto.nLinhas=matriz1.nLinhas;
        produto.nColunas=matriz2.nColunas; 
    }else{
        produto.nLinhas=produto.nColunas=0;
    }
    return produto; 
}
#endif