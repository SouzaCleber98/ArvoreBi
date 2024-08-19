
#ifndef ARVOREBINARIA_ARVOREBINARIA_H
#define ARVOREBINARIA_ARVOREBINARIA_H

// Constantes
struct no {
    struct no *esquerda;
    int dado;
    struct no *direita;
};

// Variáveis
extern struct no *inicio;
extern struct no *anterior;

// Protótipos
void inicializar();
void finalizar(struct no *quem);
void adicionar(struct no *aonde, struct no *quem);
struct no *novoNo(int dado);
struct no *buscar(struct no * aonde, int dado);
void excluir(int dado);

#endif //ARVOREBINARIA_ARVOREBINARIA_H
