/* 
 * File:   usb.h
 * Author: arinfo
 *
 * Created on 16 décembre 2019, 12:00
 */

#ifndef USB_H
#define	USB_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

//#include "functions.h"
//#include "fifo.h"

#define INITIALISATION 0
#define SEND 1
#define RECEIVE 2
#define ANSER 3

#ifdef	__cplusplus
extern "C" {
#endif

    //void initUART();
    void dataSend();
    void sentenceSend(char sentence[]);
    char catchSentence();
    void dialogToRemote();
    //void dialogToRemoteFIFO();


#ifdef	__cplusplus
}
#endif

#endif	/* USB_H */

