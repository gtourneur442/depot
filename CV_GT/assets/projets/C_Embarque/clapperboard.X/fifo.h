/* 
 * File:   fifo.h
 * Author: arinfo
 *
 * Created on 17 décembre 2019, 16:18
 */

#ifndef FIFO_H
#define	FIFO_H

#define SIZETAB 50

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef struct FIFO
{
    char tab[SIZETAB];
    int start;
    int size;
}FIFO;

void initFIFO(FIFO *FIFO);
void append(FIFO *fifo, char c);
char pop_front(FIFO *fifo);


#ifdef	__cplusplus
}
#endif

#endif	/* FIFO_H */

