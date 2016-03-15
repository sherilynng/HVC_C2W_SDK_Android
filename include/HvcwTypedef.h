/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015-2016 by OMRON Corporation                      */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/

#ifndef __HVCWTYPEDEF_H
#define __HVCWTYPEDEF_H

typedef     signed char         HVCW_CHAR;       /* 8-bit character                     */
typedef     unsigned char       HVCW_UINT8;      /* 8-bit unsigned character type       */
typedef     unsigned char       HVCW_BYTE;       /* 8-bit unsigned character type       */
typedef     signed short        HVCW_INT16;      /* 16-bit signed short integer type    */
typedef     unsigned short      HVCW_UINT16;     /* 16-bit unsigned short integer type  */
typedef     signed int          HVCW_BOOL;       /* 32-bit signed integer type          */
typedef     signed int          HVCW_INT32;      /* 32-bit signed integer type          */
typedef     unsigned int        HVCW_UINT32;     /* 32-bit unsigned integer type        */
typedef     void                HVCW_VOID;       /* void                                */

#ifndef     FALSE
    #define     FALSE               0
#endif

#ifndef     TRUE
    #define     TRUE                1
#endif

#ifndef     NULL
    #define     NULL                0
#endif

#endif /* __HVCWTYPEDEF_H */
