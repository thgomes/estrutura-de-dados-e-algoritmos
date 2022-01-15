typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int fila_cheia (fila *f) {
    if ((f->u + 1) % f->N == f->p)
        return 1;
    else
        return 0;
}

int enfileira (fila *f, int x) {
    if (fila_cheia(f))
        if (!redimensiona(f))
            return 0;
    f->dados[f->p] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}