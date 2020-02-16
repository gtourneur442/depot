#include "fifo.h"

void initFIFO(FIFO *fifo)
{
    fifo->start=0;
    fifo->size=0;
}

void append(FIFO *fifo, char c)
{
    int new_val_pos=(fifo->start+fifo->size)%SIZETAB;
    fifo->tab[new_val_pos]=c;
    fifo->size++;
}

char pop_front(FIFO *fifo)
{
    if(fifo->size==0)
    {
        return '\0';
    }
    else
    {
        char last_val=fifo->tab[fifo->start];
        fifo->start=(fifo->start+1)%SIZETAB;
        fifo->size--;
        return last_val;
    }
}
