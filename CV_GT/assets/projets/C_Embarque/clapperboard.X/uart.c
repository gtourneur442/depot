#include "uart.h"

/*void initUART()
{
    TRISFbits.TRISF12=0;
    TRISFbits.TRISF13=1;
    
    U4RXR=0b1001; //RPF13 = UART_RX
    RPF12R=0b0010; //RPF12 = UART_TX
    
    U4MODEbits.ON = 1;
    U4MODEbits.SIDL = 0;
    U4MODEbits.IREN = 0;
    U4MODEbits.RTSMD = 0;
    U4MODEbits.UEN = 0b00;
    U4MODEbits.WAKE = 0;
    U4MODEbits.LPBACK = 0;
    U4MODEbits.ABAUD = 0;
    U4MODEbits.RXINV= 0;
    U4MODEbits.BRGH = 0;
    U4MODEbits.PDSEL = 0b00;
    U4MODEbits.STSEL = 0;
    
    U4STAbits.URXEN = 1;
    U4STAbits.UTXEN = 1;
    U4STAbits.UTXBRK = 0;
    
    U4BRG=25;
}*/

void dataSend()
{
    U4TXREG='A';
    
}

void sentenceSend(char sentence[])
{
    int x = 0;
    while(sentence[x] != '\0')
    {
        U4TXREG=sentence[x];
        while(U4STAbits.TRMT != 1);
        x++;
    }
}

char catchSentence()
{
    char c='\0';
    while(U4STAbits.URXDA!=0)
    {
        c = U4RXREG;
    }
    return c;
}

void dialogToRemote(char sentence[])
{
    static int state=SEND;
    static char anser[]="Good.\n\r";
    static char ch='\0';
    static char receive[100]="";
    static char receive_char[]="";
    static int receive_length=0;
    switch(state){
            case SEND:
                state = RECEIVE;
                sentenceSend(sentence);
                receive_length=0;
                break;
            case RECEIVE:
                ch=catchSentence();
                if (ch!='\0')
                {
                    if(ch!='\r')
                    {
                        receive_char[0]=ch;
                        receive_char[1]='\0';
                        sentenceSend(receive_char);
                        receive[receive_length]=ch;
                        receive[receive_length+1]='\0';
                        receive_length=receive_length+1;
                    }    
                    else
                    {   
                        receive_char[0]='\n';
                        receive_char[1]=ch;
                        receive_char[2]='\0';
                        sentenceSend(receive_char);
                        receive[receive_length]='\n';
                        receive[receive_length+1]=ch;
                        receive[receive_length+2]='\0';
                        //sentanceSend(receive);
                        state = ANSER;
                    }
                }
                break;
            case ANSER:
                state = RECEIVE;
                sentenceSend(anser);
                break;
            default:
                sentenceSend("ERROR!");
                break;
        }
}

/*void dialogToRemoteFIFO()
{
    static int state=INITIALISATION;
    static char hello[]="Hello there! you are ok?\n\r";
    static char anser[]="Good.\n\r";
    static char ch='\0';
    static FIFO fifo;
    static char receive_char[]="";
    switch(state){
        case INITIALISATION:
            initFIFO(&fifo);
            state = SEND;
            break;
        case SEND:
            state = RECEIVE;
            sentanceSend(hello);
            break;
        case RECEIVE:
            ch=catchSentance();
            if (ch!='\0')
            {
                if(ch!='\r')
                {
                    receive_char[0]=ch;
                    receive_char[1]='\0';
                    sentanceSend(receive_char);
                    append(&fifo,ch);
                }    
                else
                {   
                    receive_char[0]='\n';
                    receive_char[1]=ch;
                    receive_char[2]='\0';
                    sentanceSend(receive_char);
                    append(&fifo,'\n');
                    append(&fifo,ch);
                    receive_char[0]='\0';
                    receive_char[1]='\0';
                    receive_char[2]='\0';
                    //sentanceSend(receive);
                    receive_char[0]=pop_front(&fifo);
                    while(receive_char[0] != '\0')
                    {
                        sentanceSend(receive_char);
                        receive_char[0]=pop_front(&fifo);
                    }
                    state = ANSER;
                }
            }
            break;
        case ANSER:
            state = RECEIVE;
            sentanceSend(anser);
            break;
        default:
            sentanceSend("ERROR!");
            break;
    }
}*/