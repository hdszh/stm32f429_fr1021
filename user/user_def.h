#ifndef _USER_DEFINE_
#define _USER_DEFINE_

//#include <intrinsics.h>

//定义数据类型，便于在不同单片机上移植
typedef	unsigned char	U8;       /* 8bit unsigned  */
typedef	  signed char	S8;       /* 8bit   signed  */
typedef	unsigned short	U16;      /* 16bit unsigned */
typedef	signed short	S16;      /* 16bit   signed */
typedef	unsigned int	U32;      /* 32bit unsigned */
typedef	signed int      S32;      /* 32bit   signed */
typedef	double          DB;



#define CHIP_ABS(X)         ((X)<0 ? (-X) : (X))
#define CHIP_MAX(X,Y)       ((X)>=(Y) ? (X) : (Y))
#define CHIP_MIN(X,Y)       ((X)<=(Y) ? (X) : (Y)) 
#define CHIP_LSB(X)         ((X & 0xFF))
#define CHIP_MSB(Y)         ((Y>>8)& 0xFF)
#define CHIP_MAKEWORD(X,Y)  ((X<<8)+(Y))
#define CHIP_INRANGE(X,Y,Z) (((X<=Y) && (Y<=Z))||((Z<=Y) && (Y<=X)) ? 1 : 0)  

#define ABS(X)         ((X)<0 ? (-X) : (X))
#define MAX(X,Y)       ((X)>=(Y) ? (X) : (Y))
#define MIN(X,Y)       ((X)<=(Y) ? (X) : (Y)) 
#define LSB(X)         ((X & 0xFF))
#define MSB(Y)         ((Y>>8)& 0xFF)
#define MAKEWORD(X,Y)  ((X<<8)+(Y))
#define INRANGE(X,Y,Z) (((X<=Y) && (Y<=Z))||((Z<=Y) && (Y<=X)) ? 1 : 0)  

#ifndef   STM32F429_439xx
#define   STM32F429_439xx
#endif

#ifndef   USE_STDPERIPH_DRIVER
#define   USE_STDPERIPH_DRIVER
#endif


#ifdef __cplusplus
extern "C" {
#endif
  
#define _NOP()   __no_operation()   
  

#ifdef __cplusplus
     }
#endif

#endif