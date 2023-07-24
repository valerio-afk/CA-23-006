#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include "cit.h"


#define BIRILLI 10
#define N_TIRI 3

#define N_CASELLE 10

#define MASS_CARATTERI 256


#define ASCII_NUM_IDC 48

#define SIMBOLO_STRIKE 'X'
#define SIMBOLO_STRIKE_MINUSC 'x'
#define SIMBOLO_CHIUSURA '/'
#define SIMBOLO_NO_PUNTI '-'


#define e_uno_strike(c) (((c) == SIMBOLO_STRIKE) || ((c)==SIMBOLO_STRIKE_MINUSC))
#define e_una_chiusura(c)  ((c) == SIMBOLO_CHIUSURA)
#define e_niente(c)   ((c) == SIMBOLO_NO_PUNTI)
#define e_un_numero(c) ((c)>=ASCII_NUM_IDC) && ((c)<(ASCII_NUM_IDC+10))

#define ha_fatto_uno_strike(f) ((f).tiri[0]==BIRILLI)
#define ha_fatto_una_chiusura(f)  ((!ha_fatto_uno_strike(f)) && (((f).tiri[0]+(f).tiri[1])==BIRILLI))

#define stampa_linea(lun) per(int i=0;i<=(lun);i++) stampaf("-"); stampaf("\n");

vuoto strsostituiscicarattere(car *,car,car);

struttura casella
{
    senzasegno corto int numero_casella; // 1-10
    senzasegno car tiri[N_TIRI];    
    senzasegno corto int punteggio;
};

struttura partita
{
    struct casella caselle[N_CASELLE];
};

struttura partita inizia_partita()
{
    struttura partita nuova_partita = {0}; 

    per (int i = 0; i<N_CASELLE; i++) nuova_partita.caselle[i].numero_casella = i+1;
    
    
    ritorna nuova_partita; 
}

vuoto imposta_punteggi(struttura partita *p, cost car * sequenza)
{
    int lun = strlung(sequenza);
    int i = 0; 
    int f = 0; 
    int r = 0; 

    per (i = 0; i<lun;i++) 
    {
        se (f < (N_CASELLE-1)) 
        { 
            se (e_un_numero(sequenza[i]) || e_niente(sequenza[i])) 
            {
                se (e_niente(sequenza[i])) p->caselle[f].tiri[r] = 0; 
                altrimenti p->caselle[f].tiri[r] = sequenza [i] - ASCII_NUM_IDC; 

                r++; 
                se (r>1) 
                {
                    f++; 
                    r=0; 
                }
            }
            altrimenti
            {
                se ((r==0) && e_uno_strike(sequenza[i])) 
                {
                    p->caselle[f].tiri[0] = BIRILLI;
                    f++;
                }
                altrimenti
                {
                    se ((r==1) && e_una_chiusura(sequenza[i])) 
                    {
                       
                        p->caselle[f].tiri[1] = BIRILLI - p->caselle[f].tiri[0];

                        f++; 
                        r=0; 
                    }
                    altrimenti 
                    {
                        stampaf("Non capisco il carattere %c alla posizione %i",sequenza[i],i+1);
                        ritorna;
                    }
                }
            }
        }
        altrimenti
        {

            se (e_un_numero(sequenza[i]) || e_niente(sequenza[i])) 
            {
                se (e_niente(sequenza[i])) p->caselle[f].tiri[r] = 0;
                altrimenti p->caselle[f].tiri[r] = sequenza [i] - ASCII_NUM_IDC;
            } 
            altrimenti se(e_uno_strike(sequenza[i])) p->caselle[f].tiri[r] = BIRILLI;
            altrimenti
            {
                se ((r>0)&&(e_una_chiusura(sequenza[i])))   p->caselle[f].tiri[r] = BIRILLI - p->caselle[f].tiri[r-1];
                altrimenti
                {
                    stampaf("Non capisco il carattere %c alla posizione %i",sequenza[i],i+1);
                    ritorna;
                }
            }

            r++; 
        }
    }
}



vuoto calcola_punteggio_casella(struttura casella*casella, senzasegno car *tiri_successivi, senzasegno corto int punteggio_prec)
{
    senzasegno corto int punteggio_casella = punteggio_prec;  

    punteggio_casella += casella->tiri[0] + casella->tiri[1]; 
    se (casella->numero_casella == N_CASELLE) punteggio_casella += casella->tiri[2]; 

    se (ha_fatto_uno_strike(*casella)) punteggio_casella += tiri_successivi[0] + tiri_successivi[1]; 
    altrimenti se (ha_fatto_una_chiusura(*casella)) punteggio_casella += tiri_successivi[0]; 

    casella->punteggio = punteggio_casella; 
}



vuoto calcola_punteggio(struttura partita *p)
{
    struttura casella  *casella_corrente;
    senzasegno car tiri_successivi[2]; 
    senzasegno corto int punteggio_prec = 0; 

    per (int i=0;i<N_CASELLE;i++)
    {
        memimposta(tiri_successivi,0, dimensionedi(tiri_successivi)); 

        casella_corrente = &p->caselle[i]; 
        se (casella_corrente->numero_casella < N_CASELLE) 
        {
            tiri_successivi[0] = p->caselle[i+1].tiri[0]; 

            se (p->caselle[i+1].numero_casella < N_CASELLE)
                tiri_successivi[1] = ha_fatto_uno_strike(p->caselle[i+1]) ? p->caselle[i+2].tiri[0] : p->caselle[i+1].tiri[1];
            altrimenti tiri_successivi[1] = p->caselle[i+1].tiri[1];
        }

        se (casella_corrente->numero_casella > 1) punteggio_prec = p->caselle[i-1].punteggio;

        calcola_punteggio_casella(casella_corrente, tiri_successivi, punteggio_prec);
    }
}


car stampa_tiro(senzasegno car *tiri,senzasegno int idc, bool ultima_casella)
{
    se (ultima_casella == falso)
    {
        se ((idc != 1) && (tiri[idc] == BIRILLI)) ritorna SIMBOLO_STRIKE;
        altrimenti se ((idc==1) && (tiri[idc-1]==BIRILLI) ) ritorna ' ';
        altrimenti se ((idc>0) && (tiri[idc-1]+tiri[idc]==BIRILLI) ) ritorna SIMBOLO_CHIUSURA;
        altrimenti se (tiri[idc] == 0) ritorna SIMBOLO_NO_PUNTI;
        altrimenti ritorna tiri[idc] + ASCII_NUM_IDC;
    }
    altrimenti
    {
        se (tiri[idc] == 0) ritorna SIMBOLO_NO_PUNTI;
        altrimenti se (tiri[idc] == BIRILLI) ritorna SIMBOLO_STRIKE;
        altrimenti ritorna tiri[idc] + ASCII_NUM_IDC;
    }
}



vuoto stampa_casella(struttura casella *f, car*memoria, dimensione_t lun_memoria)
{
    snstampaf(memoria, lun_memoria,"%c %c",stampa_tiro(f->tiri,0,falso),stampa_tiro(f->tiri,1,falso));
}



vuoto stampa_partita (struttura partita*p)
{
    car linea1[MASS_CARATTERI]; 
    car linea2[MASS_CARATTERI]; 
    car str[10], str2[10]; 
    struttura casella * casella_corrente; 

    
    memimposta(linea1,0,dimensionedi(linea1)); 
    memimposta(linea2,0,dimensionedi(linea2));

    per (int i=0;i<N_CASELLE;i++)
    {
        casella_corrente = &p->caselle[i]; 

        
        se (casella_corrente->numero_casella < N_CASELLE) stampa_casella(casella_corrente,str,dimensionedi(str)); 
        altrimenti 
        {
            se (ha_fatto_una_chiusura(*casella_corrente)) 
            {
                stampa_casella(casella_corrente,str,dimensionedi(str)); 
                sstampaf(str2," %c",stampa_tiro(casella_corrente->tiri,2,vero)); 

                strcat(str,str2); 
            }
            altrimenti se(casella_corrente->tiri[0] == BIRILLI) 
            {
                sstampaf(str,"%c %c %c",stampa_tiro(casella_corrente->tiri,0,vero), 
                                       stampa_tiro(casella_corrente->tiri,1,vero), 
                                       stampa_tiro(casella_corrente->tiri,2,falso)); 


            }
            altrimenti stampa_casella(casella_corrente,str,dimensionedi(str)); 
        }

        sstampaf(str2,"|"); 
        strcat(str,str2); 
        strcat(linea1,str); 

        se (casella_corrente->numero_casella == N_CASELLE) snstampaf(str,sizeof(str),"%5d|",casella_corrente->punteggio);
        altrimenti snstampaf(str,dimensionedi(str),"%3d|",casella_corrente->punteggio);

        strcat(linea2,str);
    }

    
    strsostituiscicarattere(linea1,'0',SIMBOLO_NO_PUNTI);

    stampa_linea(strlung(linea1));
    
    per(int i=0;i<N_CASELLE;i++) stampaf("| %d ",i+1);
    stampaf(" |\n");
    
    stampa_linea(strlung(linea1)); 
    stampaf("|%s\n",linea1); 

    stampa_linea(strlung(linea1)); 
    stampaf("|%s\n",linea2); 
    stampa_linea(strlung(linea1));   
}


int inizio()
{
    cost car * mia_partita = "9-XX9-7/XX8-6/XX9";
    struttura partita valerio = inizia_partita();

    imposta_punteggi(&valerio, mia_partita);
    calcola_punteggio(&valerio);
    stampa_partita(&valerio);

    ritorna 0;
}


vuoto strsostituiscicarattere(car *str,car c1,car c2)
{
    per(int i=0;str[i];i++) se(str[i]==c1) str[i]=c2; 
}