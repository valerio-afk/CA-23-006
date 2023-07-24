#ifndef _C_IT_
#define _C_IT_

#define inizio main

/***********************
 * 
 * Parole chiave di base
 *
 **********************/


#define cost const
#define doppio double
#define singolo float
#define corto short
#define struttura struct
#define senzasegno unsigned
#define interrompi break
#define continua continue
#define altrimenti else
#define per for
#define lungo long
#define consegno signed
#define confronta switch
#define vuoto void
#define caso case
#define condizionepredefinita default
#define vai goto
#define registro register
#define dimensionedi sizeof
#define definiscitipo typedef
#define car char
#define fai do
#define esterno extern
#define se if
#define ritorna return
#define statico static
#define unione union
#define mentre while
#define vuoto void


#ifdef _STDIO_H
   definiscitipo FILE ARCHIVIO;
   definiscitipo fpos_t posarchivio_t;

   #define DIMTAMP  1024
   #define FDA  (-1) //Fine dell'archivio
   #define NOMEARCHIVIO_MASSIMO    1024
   #define AAPRI_MASSIMO    1024
   #define L_tmpnom        1024  
   #define NIENTE 0
   #define TMP_MASSIMO 26

   /******************************************************************************
   *
   * Adesso traduciamo tutte le funzioni, tipi di dato, nonché strutture 
   * all'interno libreria standard di C (stdio)
   *
   * https://cplusplus.com/reference/cstdio/
   *
   ******************************************************************************/

   /**********************************
   *
   * Operazioni sugli archivi
   *
   **********************************/

   #define cancella remove
   #define rinomina rename
   #define filetemp tmpfile
   #define nometmp tmpnam

   /**********************************
   *
   * Accesso agli archivi
   *
   **********************************/

   #define achiudi fclose
   #define ascarica fflush
   #define aapri fopen
   #define ariapri freopen
   #define impostamemtampone setbuf
   #define impostamemtamponev setvbuf

   /**********************************
   *
   * Ingresso/Uscita formattato
   *
   **********************************/

   #define astampaf fprintf
   #define ascanf fscanf
   #define stampaf printf
   //scanf si salva
   #define snstampaf snprintf
   #define sstampaf sprintf
   //sscanf si salva
   #define vastampaf vfprintf
   #define vascanf vfscanf
   #define vstampaf vprintf
   //vscanf si salva
   #define vsnstampaf vsnprintf
   #define vsstampaf vsprintf
   //vsscanf si salva

   /**********************************
   *
   * Ingresso/Uscita Carattere
   *
   **********************************/

   #define aprendic fgetc
   #define aprendis fgets
   #define amettic fputc
   #define amettis fputs
   #define prendic getc
   #define prendicar getchar
   #define prendis gets
   #define mettic putc
   #define metticar putchar
   #define mettis puts
   #define riprendic ungetc

   /**********************************
   *
   * Ingresso/Uscita Diretto
   *
   **********************************/

   #define aleggi fread
   #define ascrivi fwrite

   /**********************************
   *
   * Posizionamento negli archivi
   *
   **********************************/

   #define aprendipos fgetpos
   #define acerca fseek
   #define aimpostapos fsetpos
   #define adimmi ftell
   #define riavvolgi rewind

   /**********************************
   *
   * Gestione degli errori
   *
   **********************************/

   #define puliscierr clearerr
   #define afda feof //fda = fine dell'archivio
   #define aerrore ferror
   #define serrore perror

#endif


#ifdef _STDLIB_H

   /******************************************************************************
   *
   * Adesso traduciamo tutte le funzioni, tipi di dato, nonché strutture 
   * all'interno libreria standard di C (stdlib)
   *
   * https://cplusplus.com/reference/cstdlib/
   *
   ******************************************************************************/

   /**********************************
   *
   * Conversioni di stringhe
   *
   **********************************/

   #define aindoppio atof
   #define anintero atoi
   #define ainterolungo atol
   #define ainterolungolungo atoll
   #define strindoppio strtod
   #define strinsingolo strtof
   #define strininterolungo strtol
   #define strindoppiolungo strtold
   #define strininterolungolungo strtoll
   #define strininterolungosenzasegno strtoul
   #define strininterlungolungosenzasegno strtoull

   /*************************************
   *
   * Generazione di numeri pseudo-casuali
   *
   *************************************/

   #define	CASU_MASSIMO	2147483647

   #define casuale rand
   #define scasuale srand

   /********************************
   *
   * Gestione della memoria dinamica
   *
   *********************************/

   #define allocac calloc
   #define libera free
   #define allocamemoria malloc
   #define rialloca realloc

   /***************************************
   *
   * Funzioni che comunicano con l'ambiente
   *
   ****************************************/

   #define	USCITA_FALLITA	    1	
   #define	USCITA_CON_SUCCESSO	0

   #define annulla abort
   #define alluscita atexit
   #define all_uscita_rapida at_quick_exit
   #define esci exit
   #define esci_rapidamente quick_exit
   #define prendivaramb getenv
   #define sistema system
   #define _Esci _Exit

   /***********************
   *
   * Ricerca e Ordinamento
   *
   ************************/

   #define ricercabinaria bsearch
   #define ricerca_rapida qsort

   /************************
   *
   * Aritmetica sugli interi
   *
   *************************/

   #define ass abs
   //div non necessario
   #define assl labs
   //ldiv non necessario
   #define assll llabs
   //lldiv non necessario

   /******************************************
   *
   * Caratteri multibyte (possiamo dire byte?)
   *
   ******************************************/

   #define lunmb mblen
   #define mbincarampio
   #define carampiotomb

   /******************************************
   *
   * Stringhe multibyte (possiamo dire byte?)
   *
   ******************************************/

   #define stringambacarampio mbstowcs
   #define stringacarampioamb mbstowcs

   #endif

#ifdef _ASSERT_H

   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro assert.h
   *
   * https://github.com/openbsd/src/blob/master/include/assert.h
   *
   ******************************************************************************/

   #define asserzione_statica _Static_assert

   /*INIZIO*/
   /* IL CODICE A SEGURIE E' STATO RIADATTATO DAL LINK GITHUB SOPRACITATO 
      RILASCIATO SOTTO LICENZA BSD
   */
   #ifdef NDEBUG
   # define	asserisci(e)	((void)0)
   # define	_asserisci(e)	((void)0)
   #else
   # define	_asserisci(e)	assert(e)
   # if __ISO_C_VISIBLE >= 1999
   #  define	asserisci(e)	((e) ? (void)0 : __assert2(__FILE__, __LINE__, __func__, #e))
   # else
   #  define	asserisci(e)	((e) ? (void)0 : __assert(__FILE__, __LINE__, #e))
   # endif
   #endif
   /*FINE*/

   #endif

#ifdef _COMPLEX_H
   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro complex.h
   *
   * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/complex.h.html
   *
   ******************************************************************************/

   #define complesso _Complex

   #define cass cabs 
   #define casss cabsf
   #define cassl cabsl
   //cacos si salva
   #define cacoss cacosf
   #define cacosiper cacosh
   #define cacosipers cacoshf
   #define cacosiperl cacoshl
   //carg si salva
   #define cargs cargf
   //cargl si salva
   #define casen casin
   #define casens casinf
   #define casenl casinl
   #define caseniper casinh
   #define casenipers casinhf
   #define caseniperl casinhl
   //catan si salva
   #define catans catanf
   #define cataniper catanh
   #define catanipers catanhf
   #define cataniperl catanhl
   //catanl si salva
   //ccos si salva
   #define ccoss ccosf
   #define ccosiper ccosh
   #define ccosipers ccoshf
   #define ccosiperl ccoshl
   //ccosl si salva
   #define cesp cexp
   #define cesps cexpf
   #define cespl cexpl
   //cimag si salva
   #define cimags cimagf
   //cimagl si salva
   //clog si salva
   #define clogs clogf
   //clogl si salva
   #define coniug conj
   #define coniugs conjf
   #define coniugl conjl
   #define cpot cpow
   #define cpots cpowf
   #define cpotl cpowl
   #define cproiez cproj
   #define cproiezs cprojf
   #define cproiezl cprojl
   #define creale creal
   #define creales crealf
   #define crealel creall
   #define csen csin
   #define csens csinf
   #define csenl csinl
   #define cradq csqrt
   #define cradqs csqrtf
   #define cradql csqrtl
   //ctan si salva
   #define ctans ctanf
   #define ctaniper ctanh
   #define ctanipers ctanhf
   //ctanl si salva

#endif

#ifdef _MATH_H
   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro math.h
   *
   * https://cplusplus.com/reference/cmath/?kw=math.h
   *
   ******************************************************************************/

   #define	MAT_ERRNUM	1
   #define	MAT_ERRECCEZ	2
   #define	math_errhandling	MAT_ERRECCEZ

   #define INFINITO INFINITY
   #define NUN NAN // NUN - Non-un-numero
   #define VALORE_ENORME HUGE_VAL
   #define VALORE_ENORMES ((singolo)VALORE_ENORME)
   #define VALORE_ENORMEL ((lungo doppio)VALORE_ENORME)

   #define VM_MSF_VELOCE FP_FAST_FMA    //VM=Virgola Mobile - MSF = Moltiplicazione-Somma Fusa
   #define VM_MSFS_VELOCE FP_FAST_FMAF
   #define VM_MSFL_VELOCE FP_FAST_FMAL

   #define VM_INFINITO FP_INFINITE
   #define VM_NAN FP_NAN
   #define VM_NORMALE FP_NORMAL
   #define VM_QUASINORMALE FP_SUBNORMAL
   #define VM_ZERO FP_ZERO

   #define VM_ILOGB0 FP_ILOGB0
   #define VM_ILOGBNUN FP_ILOGBNAN

   definiscitipo double_t doppio_t;
   definiscitipo float_t singolo_t;


   //cos si salva
   #define sen sin
   //tan si salva
   //acos si salva
   #define asen asin
   //atan/atan2 si salvano
   #define cosiper cosh
   #define seniper sinh
   #define taniper tanh
   #define acosiper acosh
   #define aseniper asinh
   #define ataniper atanh

   #define esp exp
   #define fresp frexp
   #define ldesp ldexp
   //log/log10 si salvano
   //modf si salva
   #define esp2 exp2
   #define espm1 expm1
   //ilogb si salva
   //log1p si salva
   //log2 si salva
   //logb si salva
   //scalbn/scalbln si salvano

   #define pot pow
   #define radq sqrt
   #define radc cbrt
   #define ipot hypot
   #define fde erf //fde=funzione degli errori
   #define fdec erfc
   //tgamma/lgamma si salvano

   #define arrotecc ceil
   #define arrotdif floor
   #define smod fmod
   #define tronc trunc
   #define arrotonda round
   #define arrotondal lround
   #define arrotondall llround
   #define arrotondaint rint
   #define arrotondaintl lrint
   #define arrotondaintll llrint
   #define resto reminder
   #define restquo remquo
   #define copiasegno copysign
   #define nun nan
   #define nuns nanf
   #define nunl nanl
   #define prossimodopo nextafter
   #define prossimoverso nexttoward
   #define sdiffpos fdim
   #define smass fmax
   #define smin fmin
   #define ass abs
   #define lass labs
   #define llass llabs
   #define sass fabs
   //div/ldiv/lldiv si salvano
   #define msf fma
   #define classificas fpclassify
   #define efinito isfinite
   #define einf isinf
   #define enun isnan
   #define enormale isnormal
   #define segnobit signbit

#endif


#ifdef _CTYPE_H
   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro ctype.h
   *
   * https://cplusplus.com/reference/cctype/?kw=ctype.h
   *
   ******************************************************************************/

   #define ealnum isalnum
   #define ealfa isalpha
   #define evuoto isblank
   #define ectrl iscntrl
   #define ecifra isdigit
   #define egrafico isgraph
   #define emiuscolo islower
   #define estampabile isprint
   #define epunt ispunct
   #define espazio isspace
   #define emaiuscolo isupper
   #define ecifraesa isxdigit

   #define inminuscolo tolower
   #define inmaiuscolo toupper

#endif


#ifdef	_ERRNO_H

   /**
   * La libreria di base di C richiede tre definizioni all'interno di ERRNO
   * Le altre dipendono da implementazione/sistema operativo.
   * https://en.wikipedia.org/wiki/Errno.h
   */

   //EDOM si salva
   #define EINTERVALLO ERANGE
   #define ESEQIL EILSEQ  //sequenza illegale


#endif


#if defined(_FENV_H_) || defined(_GLIBCXX_FENV_H)

   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro fenv.h
   *
   * https://cplusplus.com/reference/cfenv/
   *
   ******************************************************************************/

   definiscitipo fenv_t samb_t;
   definiscitipo fexcept_t seccezione_t;

   #define SA_DIVPERZERO FE_DIVBYZERO
   #define SA_INESATTO FE_INEXACT
   #define SA_INVALIDO FE_INVALID
   #define SA_ECCESSO FE_OVERFLOW	
   #define SA_DIFETTO FE_UNDERFLOW
   #define SA_TUTTE_ECCEZIONI FE_ALL_EXCEPT



   #define SA_VERSOGIU FE_DOWNWARD	
   #define SA_ALPIUVICINO FE_TONEAREST	
   #define SA_VERZOLOZERO FE_TOWARDZERO	
   #define SA_VERSOSU FE_UPWARD


   #define SA_AMB_PREDEFINITO FE_DFL_ENV

   /***********************************************
   * 
   * Eccezioni sui numeri singoli a virgola mobile
   * 
   ***********************************************/
   #define sapuliscieccezione feclearexcept //sa = singolo ambiente
   #define salanciaeccezione feraiseexcept
   #define saprendicontrassegnoeccezione fegetexceptflag
   #define saimpostcontrassegnoaeccezione fesetexceptflag

   /*********************************
   * 
   * Direzione dell'arrotondamento
   * 
   ********************************/

   #define saprendiarrotondamento fegetround
   #define saimpostaarrotondamento fesetround

   /*************************************************************************************
   * 
   * Restante delle funzioni sull'ambiente riguardante i numeri singoli a virgola mobile
   * 
   ************************************************************************************/

   #define saprendiamb fegetenv
   #define saimpostaamb fesetenv
   #define satrattietieccezione feholdexcept
   #define saaggiornaamb feupdateenv
   #define saprovaeccezione fetestexcept

#endif

#if defined(_LIBC_LIMITS_H_) || defined(_GCC_LIMITS_H_) || defined(_PPC_LIMITS_H_) 

   /*******************************************
   * 
   *  Impostiamo le costanti in limits.h 
   *  https://cplusplus.com/reference/climits/
   * 
   *******************************************/
   #define CAR_CIFREBINARIE CHAR_BIT
   #define CAR_MIN SCHAR_MIN
   #define CAR_MASS SCHAR_MAX
   #define CARSS_MASS UCHAR_MAX
   #define MB_LUN_MASS MB_LEN_MAX
   #define CORTO_MIN SHRT_MIN
   #define CORTO_MASS SHRT_MAX
   #define CORTOSS_MASS USHRT_MAX
   #define INT_MASS INT_MAX
   #define INTSS_MASS UINT_MAX
   #define LUNGO_MIN LONG_MIN
   #define LUNGO_MASS LONG_MAX
   #define LUNGOSS_MASS ULONG_MAX
   #define LLUNGO_MIN LLONG_MIN
   #define LLUNGO_MASS LLONG_MAX
   #define LLUNGOSS_MASS ULLONG_MAX

#endif



#ifdef _SIGNAL_H

   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro stignal.h
   *
   ******************************************************************************/

   definiscitipo sig_atomic_t seg_atomico_t;

   #define segnale signal
   #define lancia raise

   #define SEGABRT SIGABRT
   #define SEGVMSE SIGFPE
   #define SEGILL SIGILL
   #define SEGINT SIGINT
   #define SEGVSEG SIGSEGV
   #define SEGTERM SIGTERM
   #define SEG_PRED SIG_DFL
   #define SEG_IGN SIG_IGN
   #define SEG_ERR SIG_ERR

#endif

   
#if defined(_STDARG_H) || defined(_ANSI_STDARG_H_) || defined(__need___va_list)

   definiscitipo va_list av_lista; //av=argomenti variabili

   #define av_inizia(v,l) va_start(v,l)
   #define av_fine(v) va_end(v)
   #define av_arg(v,l) va_arg(v,l)
   #define av_copia(d,s) va_copy(d,s)


#endif

#ifdef _STDALIGN_H

   #ifndef __cplusplus

      #define allineacome _Alignas
      #define allineamentodi _Alignof

   #endif

#endif  /* stdalign.h */


#ifdef _STDINT_H

   /******************************************************************************
   *
   * Adesso traduciamo tutto quello che ci sta dentro stdint.h
   *
   ******************************************************************************/

   definiscitipo intmax_t intmass_t;
   definiscitipo int_least8_t int_almeno8_t;
   definiscitipo int_least16_t int_almeno16_t;
   definiscitipo int_least32_t int_almeno32_t;
   definiscitipo int_least64_t int_almeno64_t;
   definiscitipo int_fast8_t int_veloce8_t;
   definiscitipo int_fast16_t int_veloce16_t;
   definiscitipo int_fast32_t int_veloce32_t;
   definiscitipo int_fast64_t int_veloce64_t;

   definiscitipo uintmax_t intssmass_t;
   definiscitipo uint8_t intss8_t;
   definiscitipo uint16_t intss16_t;
   definiscitipo uint32_t intss32_t;
   definiscitipo uint64_t intss64_t;
   definiscitipo uint_least8_t intss_almeno8_t;
   definiscitipo uint_least16_t intss_almeno16_t;
   definiscitipo uint_least32_t intss_almeno32_t;
   definiscitipo uint_least64_t intss_almeno64_t;
   definiscitipo uint_fast8_t intss_veloce8_t;
   definiscitipo uint_fast16_t intss_veloce16_t;
   definiscitipo uint_fast32_t intss_veloce32_t;
   definiscitipo uint_fast64_t intss_veloce64_t;
   definiscitipo uintptr_t intssptr_t;

   #define INTMASS_MIN INTMAX_MIN
   #define INTMASS_MASS INTMAX_MASS
   #define INTSSMASS_MASS UINTMAX_MAX

   #define INT8_MASS INT8_MAX
   #define INT16_MASS INT16_MAX
   #define INT32_MASS INT32_MAX
   #define INT64_MASS INT64_MAX

   #define INTSS8_MASS UINT8_MAX
   #define INTSS16_MASS UINT16_MAX
   #define INTSS32_MASS UINT32_MAX
   #define INTSS64_MASS UINT64_MAX

   #define INT_ALMENO8_MIN INT_LEAST8_MIN
   #define INT_ALMENO16_MIN INT_LEAST16_MIN
   #define INT_ALMENO32_MIN INT_LEAST32_MIN
   #define INT_ALMENO64_MIN INT_LEAST64_MIN

   #define INT_ALMENO8_MASS INT_LEAST8_MAX
   #define INT_ALMENO16_MASS INT_LEAST16_MAX
   #define INT_ALMENO32_MASS INT_LEAST32_MAX
   #define INT_ALMENO64_MASS INT_LEAST64_MAX

   #define INTSS_ALMENO8_MASS UINT_LEAST8_MAX
   #define INTSS_ALMENO16_MASS UINT_LEAST16_MAX
   #define INTSS_ALMENO32_MASS UINT_LEAST32_MAX
   #define INTSS_ALMENO64_MASS UINT_LEAST64_MAX

   #define INT_VELOCE8_MIN INT_LEAST8_MIN
   #define INT_VELOCE16_MIN INT_LEAST16_MIN
   #define INT_VELOCE32_MIN INT_LEAST32_MIN
   #define INT_VELOCE64_MIN INT_LEAST64_MIN

   #define INT_VELOCE8_MASS INT_LEAST8_MAX
   #define INT_VELOCE16_MASS INT_LEAST16_MAX
   #define INT_VELOCE32_MASS INT_LEAST32_MAX
   #define INT_VELOCE64_MASS INT_LEAST64_MAX

   #define INTSS_ALMENO8_MASS UINT_LEAST8_MAX
   #define INTSS_ALMENO16_MASS UINT_LEAST16_MAX
   #define INTSS_ALMENO32_MASS UINT_LEAST32_MAX
   #define INTSS_ALMENO64_MASS UINT_LEAST64_MAX

   #define INT_VELOCE8_MIN INT_FAST8_MIN
   #define INT_VELOCE16_MIN INT_FAST16_MIN
   #define INT_VELOCE32_MIN INT_FAST32_MIN
   #define INT_VELOCE64_MIN INT_FAST64_MIN

   #define INT_VELOCE8_MASS INT_FAST8_MAX
   #define INT_VELOCE16_MASS INT_FAST16_MAX
   #define INT_VELOCE32_MASS INT_FAST32_MAX
   #define INT_VELOCE64_MASS INT_FAST64_MAX

   #define INTSS_VELOCE8_MASS UINT_FAST8_MAX
   #define INTSS_VELOCE16_MASS UINT_FAST16_MAX
   #define INTSS_VELOCE32_MASS UINT_FAST32_MAX
   #define INTSS_VELOCE64_MASS UINT_FAST64_MAX

   #define INTPTR_MASS INTPTR_MAX
   #define INTSSPTR_MASS UINTPTR_MAX

   #define DIMENSIONE_MASSIMA SIZE_MAX
   #define PTRDIFF_MASSIMA PTRDIFF_MAX
   
   #define SEGN_ATOMICO_MIN SIG_ATOMIC_MIN
   #define SEGN_ATOMICO_MASS SIG_ATOMIC_MAX

   #define CARAMPIO_MIN WCHAR_MIN
   #define CARAMPIO_MASS WCHAR_MAX

   #define INTAMPIO_MIN WINT_MIN
   #define INTAMPIO_MASS WINT_MAX

   #define INTMASS_C(c) INTMAX_C(c)
   #define INTSSMASS_C(c) UINTMAX_C(c)
   #define INTSS8_C(c) UINT8_C(c)
   #define INTSS16_C(c) UINT16_C(c)
   #define INTSS32_C(c) UINT32_C(c)
   #define INTSS64_C(c) UINT64_C(c)

#endif


#ifdef _INTTYPES_H

   definiscitipo imaxdiv_t imassdiv_t;

   /************************************************************************
   *
   * Questa sezione è stata ispirata dal file inttypes.h sotto licenza GCC
   *
   *************************************************************************/


   /* Notazione Decimale  */

   # define STAd8		"d"
   # define STAd16		"d"
   # define STAd32		"d"
   # define STAd64		__PRI64_PREFIX "d"

   # define STAdALMENO8	"d"
   # define STAdLALMENO6	"d"
   # define STAdALMENO32	"d"
   # define STAdALMENO64	__PRI64_PREFIX "d"

   # define STAdVELOCE8	"d"
   # define STAdVELOCE16	__PRIPTR_PREFIX "d"
   # define STAdVELOCE32	__PRIPTR_PREFIX "d"
   # define STAdVELOCE64	__PRI64_PREFIX "d"


   # define STAi8		"i"
   # define STAi16		"i"
   # define STAi32		"i"
   # define STAi64		__PRI64_PREFIX "i"

   # define STAiALMENO8	"i"
   # define STAiALMENO16	"i"
   # define STAiALMENO32	"i"
   # define STAiALMENO64	__PRI64_PREFIX "i"

   # define STAiVELOCE8	"i"
   # define STAiVELOCE16	__PRIPTR_PREFIX "i"
   # define STAiVELOCE32	__PRIPTR_PREFIX "i"
   # define STAiVELOCE64	__PRI64_PREFIX "i"

   /* Notazione Ottale  */
   # define STAo8		"o"
   # define STAo16		"o"
   # define STAo32		"o"
   # define STAo64		__PRI64_PREFIX "o"

   # define STAoALMENO8	STA
   # define STAoALMENO16	"o"
   # define STAoALMENO32	"o"
   # define STAoALMENO64	__PRI64_PREFIX "o"

   # define STAoVELOCE8	"o"
   # define STAoVELOCE16	__PRIPTR_PREFIX "o"
   # define STAoVELOCE32	__PRIPTR_PREFIX "o"
   # define STAoVELOCE64	__PRI64_PREFIX "o"

   /* Interi senza segno */
   # define STAu8		"u"
   # define STAu16		"u"
   # define STAu32		"u"
   # define STAu64		__PRI64_PREFIX "u"

   # define STAuALMENO8	"u"
   # define STAuALMENO16	"u"
   # define STAuALMENO32	"u"
   # define STAuALMENO64	__PRI64_PREFIX "u"

   # define STAuveloce8	"u"
   # define STAuveloce16	__PRIPTR_PREFIX "u"
   # define STAuveloce32	__PRIPTR_PREFIX "u"
   # define STAuveloce64	__PRI64_PREFIX "u"

   /* Notazione esadecimale (minuscola)  */
   # define STAe8		"x"
   # define STAe16		"x"
   # define STAe32		"x"
   # define STAe64		__PRI64_PREFIX "x"

   # define STAeALMENO8	"x"
   # define STAeALMENO16	"x"
   # define STAeALMENO32	"x"
   # define STAeALMENO64	__PRI64_PREFIX "x"

   # define STAeVELOCE8	"x"
   # define STAeVELOCE16	__PRIPTR_PREFIX "x"
   # define STAeVELOCE32	__PRIPTR_PREFIX "x"
   # define STAeVELOCE64	__PRI64_PREFIX "x"

   /* Notazione esadecimale (maiuscola)   */
   # define STAE8		"X"
   # define STAE16		"X"
   # define STAE32		"X"
   # define STAE64		__PRI64_PREFIX "X"

   # define STAXALMENO8	"X"
   # define STAXALMENO16	"X"
   # define STAXALMENO32	"X"
   # define STAXALMENO64	__PRI64_PREFIX "X"

   # define STAXVELOCE8	"X"
   # define STAXVELOCE16	__PRIPTR_PREFIX "X"
   # define STAXVELOCE32	__PRIPTR_PREFIX "X"
   # define STAXVELOCE64	__PRI64_PREFIX "X"


   /* Blocchi per stampare `intmass_t' and `intmassimoss_t'.  */
   # define STAdMASSIMO	__PRI64_PREFIX "d"
   # define STAiMASSIMO	__PRI64_PREFIX "i"
   # define STAoMASSIMO	__PRI64_PREFIX "o"
   # define STAssMASSIMO	__PRI64_PREFIX "u"
   # define STAeMASSIMO	__PRI64_PREFIX "x"
   # define STAEMASSIMO	__PRI64_PREFIX "X"


   /* Blocchi per stampare `intptr_t' and `intptrss_t'.  */
   # define STAdPTR	__PRIPTR_PREFIX "d"
   # define STAiPTR	__PRIPTR_PREFIX "i"
   # define STAoPTR	__PRIPTR_PREFIX "o"
   # define STAssPTR	__PRIPTR_PREFIX "u"
   # define STAePTR	__PRIPTR_PREFIX "x"
   # define STAEPTR	__PRIPTR_PREFIX "X"


   /* Notazione decimale con segno  */


   # define SCNdALMENO8	"hhd"
   # define SCNdALMENO16	"hd"
   # define SCNdALMENO32	"d"
   # define SCNdALMENO64	__PRI64_PREFIX "d"

   # define SCNdVELOCET8	"hhd"
   # define SCNdVELOCET16	__PRIPTR_PREFIX "d"
   # define SCNdVELOCET32	__PRIPTR_PREFIX "d"
   # define SCNdVELOCET64	__PRI64_PREFIX "d"

   # define SCNiALMENO8	"hhi"
   # define SCNiALMENO16	"hi"
   # define SCNiALMENO32	"i"
   # define SCNiALMENO64	__PRI64_PREFIX "i"

   # define SCNiVELOCE8	"hhi"
   # define SCNiVELOCE16	__PRIPTR_PREFIX "i"
   # define SCNiVELOCE32	__PRIPTR_PREFIX "i"
   # define SCNiVELOCE64	__PRI64_PREFIX "i"

   /* notazione deciamle senza segno  */
   # define SCNss8		"hhu"
   # define SCNss16		"hu"
   # define SCNss32		"u"
   # define SCNss64		__PRI64_PREFIX "u"

   # define SCNssALMENO8	"hhu"
   # define SCNssALMENO16	"hu"
   # define SCNssALMENO32	"u"
   # define SCNssALMENO64	__PRI64_PREFIX "u"

   # define SCNssVELOCE8	"hhu"
   # define SCNssVELOCE16	__PRIPTR_PREFIX "u"
   # define SCNssVELOCE32	__PRIPTR_PREFIX "u"
   # define SCNssVELOCE64	__PRI64_PREFIX "u"

   /* Notazione ottale  */

   # define SCNoALMENO8	"hho"
   # define SCNoALMENO16	"ho"
   # define SCNoALMENO32	"o"
   # define SCNoALMENO64	__PRI64_PREFIX "o"

   # define SCNoVELOCE8	"hho"
   # define SCNoVELOCE16	__PRIPTR_PREFIX "o"
   # define SCNoVELOCE32	__PRIPTR_PREFIX "o"
   # define SCNoVELOCE64	__PRI64_PREFIX "o"

   /* Notazione esadecimale */
   # define SCNe8		"hhx"
   # define SCNe16		"hx"
   # define SCNe32		"x"
   # define SCNe64		__PRI64_PREFIX "x"

   # define SCNeALMENO8	"hhx"
   # define SCNeALMENO16	"hx"
   # define SCNeALMENO32	"x"
   # define SCNeALMENO64	__PRI64_PREFIX "x"

   # define SCNeVELOCE8	"hhx"
   # define SCNeVELOCE16	__PRIPTR_PREFIX "x"
   # define SCNeVELOCE32	__PRIPTR_PREFIX "x"
   # define SCNeVELOCE64	__PRI64_PREFIX "x"


   /* Macros for scanning `intmax_t' and `uintmax_t'.  */
   # define SCNdMASSIMO	__PRI64_PREFIX "d"
   # define SCNiMASSIMO	__PRI64_PREFIX "i"
   # define SCNoMASSIMO	__PRI64_PREFIX "o"
   # define SCNssMASSIMO	__PRI64_PREFIX "u"
   # define SCNeMASSIMO	__PRI64_PREFIX "x"

   /* Macros for scaning `intptr_t' and `uintptr_t'.  */
   # define SCNssPTR	__PRIPTR_PREFIX "u"
   # define SCNePTR	__PRIPTR_PREFIX "x"

   #define imassass imaxass
   #define imassdiv imaxdiv
   #define strinimass strtoimax
   #define strinssmass strtoumax
   #define carampioinimass wcstoimax
   #define carampioinssmass wcstoumax

#endif


#ifdef _LOCALE_H
   /*****************************************************
   * 
   * Informazioni sulla localizzazione
   * https://cplusplus.com/reference/clocale/?kw=locale.h
   *
   *******************************************************/
   #define impostalocalizzazione setlocale
   #define convlocalizzazione localeconv

   #define LC_TUTTI LC_ALL
   #define LC_RACCOGLIERE LC_COLLATE
   #define LC_TIPOC LC_CTYPE
   #define LC_VALUTA LC_MONETARY
   #define LC_NUMERICO LC_NUMERIC
   #define LC_TEMPO LC_TIME

   #endif


   #ifdef _SETJMP_H

   definiscitipo jmp_buf salto_tampone;

   #define saltolungo longjmp
   #define impostasalto(e) setjmp(e)

#endif

#if defined(_FLOAT_H___) || defined (_GLIBCXX_CFLOAT) || defined(_LIBCPP_FLOAT_H)
   /*****************************************************
   * 
   * Traduciamo float.h che contiene solo un insieme di macro
   * https://cplusplus.com/reference/cfloat/
   *
   *******************************************************/

   #include<flaot.h>

   #define SINGOLO_BASE FLT_RADIX

   #define SINGOLO_CIFRE_MANT FLT_MANT_DIG
   #define DOPPIO_CIFRE_MANT DBL_MANT_DIG
   #define DOPPIOL_CIFRE_MANT LDBL_MANT_DIG

   #define SINGOLO_CIFRE FLT_DIG
   #define DOPPIO_CIFRE DBL_DIG
   #define DOPPIOL_CIFRE LDBL_DIG

   #define SINGOLO_ESP_MIN FLT_MIN_EXP
   #define DOPPIO_ESP_MIN DBL_MIN_EXP
   #define DOPPIOL_ESP_MIN LDBL_MIN_EXP

   #define SINGOLO_ESP_MIN_10  FLT_MIN_10_EXP
   #define DOPPIO_ESP_MIN_10  DBL_MIN_10_EXP
   #define DOPPIOL_ESP_MIN_10 LDBL_MIN_10_EXP

   #define SINGOLO_ESP_MASS FLT_MAX_EXP
   #define DOPPIO_ESP_MASS DBL_MAX_EXP
   #define DOPPIOL_ESP_MASS LDBL_MAX_EXP

   #define SINGOLO_MASS FLT_MAX
   #define DOPPIO_MASS DBL_MAX
   #define DOPPIOL_MASS LDBL_MAX

   #define SINGOLO_EPSILON FLT_EPSILON
   #define DOPPIO_EPSILON DBL_EPSILON
   #define DOPPIOL_EPSILON LDBL_EPSILON

   #define SINGOLO_MIN FLT_MIN
   #define DOPPIO_MIN DBL_MIN
   #define DOPPIOL_MIN LDBL_MIN

   #define SINGOLO_ARROTONDAMENTO FLT_ROUNDS

   #define SINGOLO_METODO_VAL FLT_EVAL_METHOD

   #define CIFRE_DECIMALI DECIMAL_DIG

#endif

#ifdef _ISO646_H
   #define e_     &&
   #define e_uguale  &=
   #define bite  &
   #define bito   |
   #define compl   ~
   #define non     !
   #define non_uguale  !=
   #define o_      ||
   #define o_uguale   |=
   #define dis_esclusiva     ^
   #define dis_esclusiva_uguale  ^=


#endif

#ifdef _STDBOOL_H
   #define vero 1
   #define falso 0
#endif

#if defined(_STDDEF_H) || defined(_STDDEF_H_) || defined(_ANSI_STDDEF_H) || defined(__STDDEF_H__) || defined(_TIME_H) || defined (_STDIO_H)
   #define scostamentodi(TYPE, MEMBER) offsetof(TYPE, MEMBER)

   
   
   definiscitipo size_t dimensione_t;

   #ifdef _STDDEF_H
      definiscitipo ptrdiff_t diffptr_t;
      definiscitipo nullptr_t ptrnullo_t;
      definiscitipo max_align_t alineamento_mass_t;
   #endif

   #define in_intero to_integer
#endif


#ifdef _STRING_H

   // Funzioni di copia
   #define memcopia memcpy	
   #define memsposta memmove	
   #define strcopia strcpy	
   #define strncopia strncpy

   //le funzioni strcat e strncat possono rimanere tali
   //anche le funzioni memcmp, strcmp, strncmp

   //Funzioni residue di confronto

   #define strracc strcoll
   #define strtrasf strxfrm

   //Funzioni di ricerca

   #define memcar memchr
   #define strcar strchr
   #define strcpos strcspn
   #define strppos strpbrk
   #define strcultimo strrchr
   #define strporz strspn
   
   //strstr puo rimanere
   #define strsimbolo strtok

   //Altre funzioni
   #define memimposta memset
   #define strerrore strerror
   #define strlung strlen
   
#endif

#if defined (_STDATOMIC_H) || defined(_THREADS_H)

   //Thread viene tradotto come sottoprocesso (sproc abbreviato)

   definiscitipo thrd_t sproc_t;
   definiscitipo thrd_start_t sproc_fun_t;

   #define sproc_crea thrd_create
   #define sproc_uguali thrd_equal
   #define sproc_corrente thrd_current
   #define sproc_sospendi thrd_sleep
   #define sproc_lascia thrd_yield
   #define sproc_esci thrd_exit
   #define sproc_esci thrd_exit
   #define sproc_separa thrd_detach
   #define sproc_aspetta thrd_join

   #define sproc_successo thrd_success
   #define sproc_nomem thrd_nomem
   #define sproc_tempo_scad thrd_timedout
   #define sproc_occupato thrd_busy
   #define sproc_errore thrd_error

   #define ATOMICO_BOOL_SENZA_BLOCCo ATOMIC_BOOL_LOCK_FREE
   #define ATOMICO_CAR_SENZA_BLOCCO ATOMIC_CHAR_LOCK_FREE     
   #define ATOMICO_CAR16_SENZA_BLOCCO ATOMIC_CHAR16_T_LOCK_FREE 
   #define ATOMICO_CAR32_SENZA_BLOCCO ATOMIC_CHAR32_T_LOCK_FREE 
   #define ATOMICO_CARAMPIO_SENZA_BLOCCO ATOMIC_WCHAR_T_LOCK_FREE  
   #define ATOMICO_CORTO_SENZA_BLOCCO ATOMIC_SHORT_LOCK_FREE    
   #define ATOMICO_INT_SENZA_BLOCCO ATOMIC_INT_LOCK_FREE      
   #define ATOMICO_LUNGO_SENZA_BLOCCO ATOMIC_LONG_LOCK_FREE     
   #define ATOMICO_LLUNGO_SENZA_BLOCCO ATOMIC_LLONG_LOCK_FREE    
   #define ATOMICO_PUNTATORE_SENZA_BLOCCO ATOMIC_POINTER_LOCK_FREE  
   #define ATOMICO_CAR8_SENZA_BLOCCO ATOMIC_CHAR8_T_LOCK_FREE  

   #define atomico_senza_blocco atomic_is_lock_free
   #define atomico_conserva atomic_store
   #define atomico_conserva_esplicito atomic_store_explicit

   #define ordine_memoria_rilassato    memory_order_relaxed,
   #define ordine_memoria_consuma    memory_order_consume,
   #define ordine_memoria_acquisisci    memory_order_acquire,
   #define ordine_memoria_rilascia    memory_order_release,
   #define ordine_memoria_acq_ril    memory_order_acq_rel,
   #define ordine_memoria_seq_cst    memory_order_seq_cst //sequenzialmente consistente

   #define atomico_carica atomic_load
   #define atomico_carica_esplicito atomic_load_explicit

   #define atomico_scambia atomic_exchange
   #define atomico_scambia_esplicito atomic_exchange_explicit

   #define atomico_confronto_scambia_debole atomic_compare_exchange_weak
   #define atomico_confronto_scambia_forte atomic_compare_exchange_strong
   #define atomico_confronto_scambia_esplicito_debole atomic_compare_exchange_weak_explicit
   #define atomico_confronto_scambia_esplicito_forte atomic_compare_exchange_strong_explicit

   #define atomico_addizione atomic_fetch_add
   #define atomico_addizione_esplicito atomic_fetch_add_explicit

   #define atomico_sottrazione atomic_fetch_sub
   #define atomico_sottrazione_esplicito atomic_fetch_sub_explicit

   #define atomico_o_logico atomic_fetch_or
   #define atomico_o_logico_esplicito atomic_fetch_or_explicit

   #define atomico_e_logico atomic_fetch_and
   #define atomico_e_logico_esplicito atomic_fetch_and_explicit

   #define atomico_disgiunzione_esclusiva atomic_fetch_xor
   #define atomico_disgiunzione_esclusiva_esplicito atomic_fetch_xor_explicit

   #define atomico_imposta_contrassegno atomic_flag_test_and_set
   #define atomico_imposta_contrassegno_esplicito atomic_flag_test_and_set_explicit

   #define atomico_pulisci_contrassegno atomic_flag_clear
   #define atomico_pulisci_contrassegno_esplicito atomic_flag_clear_explicit

   #define atomico_inizializza atomic_init
   #define ATOMICO_VAR_INIZIALIZZA(VALORE) ATOMIC_VAR_INIT(VALORE)
   #define ATOMICO_INIZIALIZZA_CONTRASSEGNO ATOMIC_FLAG_INIT

   #define distruggi_dipendenza(VALORE) kill_dependency(valore)

   #define atomico_recinto_sottoprocesso atomic_thread_fence
   #define atomico_recinto_segnale atomic_signal_fence

   definiscitipo _Atomic _Bool   atomico_bool;
   definiscitipo _Atomic char atomico_car;
   definiscitipo _Atomic signed char   atomico_cscar;
   definiscitipo _Atomic unsigned char atomico_sscar;
   definiscitipo _Atomic short   atomico_corto;
   definiscitipo _Atomic unsigned short   atomico_sscorto;
   definiscitipo _Atomic int  atomico_int;
   definiscitipo _Atomic unsigned int  atomico_ssint;
   definiscitipo _Atomic long atomico_lungo;
   definiscitipo _Atomic unsigned long atomico_sslungo;
   definiscitipo _Atomic long long  atomico_llungo;
   definiscitipo _Atomic unsigned long long  atomico_ssllungo;
   definiscitipo _Atomic char8_t atomico_car8_t;
   definiscitipo _Atomic char16_t   atomico_car16_t;
   definiscitipo _Atomic char32_t   atomico_car32_t;
   definiscitipo _Atomic wchar_t atomico_carampio_t;
   definiscitipo _Atomic int_least8_t  atomico_int_almeno8_t;
   definiscitipo _Atomic uint_least8_t atomico_ssint_almeno8_t;
   definiscitipo _Atomic int_least16_t atomico_int_almeno16_t;
   definiscitipo _Atomic uint_least16_t   atomico_ssint_almeno16_t;
   definiscitipo _Atomic int_least32_t atomico_int_almeno32_t;
   definiscitipo _Atomic uint_least32_t   atomico_ssint_almeno32_t;
   definiscitipo _Atomic int_least64_t atomico_int_almeno64_t;
   definiscitipo _Atomic uint_least64_t   atomico_ssint_almeno64_t;
   definiscitipo _Atomic int_fast8_t   atomico_int_veloce8_t;
   definiscitipo _Atomic uint_fast8_t  atomico_ssint_veloce8_t;
   definiscitipo _Atomic int_fast16_t  atomico_int_veloce16_t;
   definiscitipo _Atomic uint_fast16_t atomico_ssint_veloce16_t;
   definiscitipo _Atomic int_fast32_t  atomico_int_veloce32_t;
   definiscitipo _Atomic uint_fast32_t atomico_ssint_veloce32_t;
   definiscitipo _Atomic int_fast64_t  atomico_int_veloce64_t;
   definiscitipo _Atomic uint_fast64_t atomico_ssint_veloce64_t;
   definiscitipo _Atomic intptr_t   atomico_ptrint_t;
   definiscitipo _Atomic uintptr_t  atomico_ptrssint_t;
   definiscitipo _Atomic size_t  atomico_dimensione_t;
   definiscitipo _Atomic ptrdiff_t  atomico_diffptr_t;
   definiscitipo _Atomic intmax_t   atomico_intmass_t;
   definiscitipo _Atomic uintmax_t  atomico_ssintmass_t;

   //mutex sta per mutual exclusion - mutua esclusione (mutesc abbreviato)

   definiscitipo mtx_t mutesc_t;

   #define mutesc_inizializza mtx_init
   #define mutesc_blocca mtx_lock
   #define mutesc_sblocca mtx_unlock
   #define mutesc_blocco_temporizzato mtx_timedlock
   #define mutesc_tenta_blocco mtx_trylock
   #define mutesc_distruggi mtx_destroy


   #define mutesc_semplice mtx_plain
   #define mutesc_ricorsivo mtx_recursive
   #define mutesc_temporizzato mtx_timed
   #define chiama_una_volta call_once

   //condizioni

   #define cnd_inizializza cnd_init
   #define cnd_segnale cnd_signal
   #define cnd_trasmetti cnd_broadcast
   #define cnd_aspetta cnd_wait
   #define cnd_aspetta_temporizzato cnd_timedwait
   #define cnd_distruggi cnd_destroy

   //tss=thread-specific storage --- spazio specifico per il sottoprocesso sss

   #define sproc_locale thread_local
   #define SSS_MASS_ITERAZIONI 


   definiscitipo tss_t sss_t;
   definiscitipo tss_dtor_t sss_distruttore_t;

   #define sss_crea tss_create
   #define sss_scrivi tss_get
   #define sss_leggi tss_set
   #define sss_cancella tss_delete

#endif

#ifdef _TIME_H

   #define orologio clock
   #define difftempo difftime
   #define creatempo mktime
   #define tempo time
   #define strdata asctime
   #define gmtdata gmtime
   #define tempolocale localtime
   #define strfdata strftime
   #define CICLI_AL_SECONDO CLOCKS_PER_SEC

   definiscitipo clock_t orologio_t;
   definiscitipo time_t tempo_t;

#endif

#endif