/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015-2016 by OMRON Corporation                      */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/

#ifndef __HVCWCOMMONDEF_H
#define __HVCWCOMMONDEF_H

/* SDK Error Code */
#define HVCW_SUCCESS                 1               /* Process success                 */
#define HVCW_INVALID_PARAM           2               /* Invalid parameter               */
#define HVCW_NOT_READY               3               /* Process preparation not done    */
#define HVCW_BUSY                    4               /* Process cannot be handled       */
#define HVCW_NOT_SUPPORT             5               /* Requested process not supported */
#define HVCW_TIMEOUT                 6               /* Transmission timeout            */
#define HVCW_NOT_FOUND               7               /* Process target not found        */
#define HVCW_FAILURE                 8               /* Other error                     */
#define HVCW_NOT_INITIALIZE          11              /* SDK not initialized             */
#define HVCW_DISCONNECTED            12              /* Camera disconnected             */
#define HVCW_NOHANDLE                20              /* Handle error                    */
#define HVCW_NO_FACE                 30              /* No face detected                */
#define HVCW_PLURAL_FACES            31              /* Multiple faces detected         */
#define HVCW_INVALID_RECEIVEDATA     40              /* Invalid data received           */
#define HVCW_NOFILE                  50              /* The file does not exist         */
#define HVCW_SD_NOT_INSERT           61              /* SD card not inserted            */
#define HVCW_SD_READ                 62              /* SD card read error              */

#endif /* __HVCWCOMMONDEF_H */
