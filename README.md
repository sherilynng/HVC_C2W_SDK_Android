# HVC-C2W Android-SDK by OMRON

### 1. SDK contents
  This SDK is used to control the OMRON HVC-C2W from an Android device.
  This SDK supports firmware version V04.02.01 or later.
  Update the firmware if it is outdated.  

### 2. Usage method
  2.1 Use this SDK only after reading AND agreeing to the included "HVC-C2W SDK License Agreement".

  2.2 Registering to the SensingEggProject member's site is required in order to use this SDK.
      http://plus-sensing.omron.co.jp/member/sdk/ (free of charge)

  2.3 An App API key is required in order to access the server and use the Web API, while a unique App ID is required in order to use the camera from the app.
      Apply for them through the "API ley application form" on the SensingEggProject member's site.
      Make sure to set the obtained App ID in the camera through the HVCW_SetAppID function.


### 3. Directory Structure
      doc/
         HVC-C2W_WebAPISpecifications   Cloud server Web API specifications to use HVC-C2W
         HVC-C2W_APISpecifications      API specifications to control HVC-C2W
         HVC-C2WDeveloperGuide          HVC-C2W developer guide
      libs/                             HVC-C2W SDK binary main file
      include/
         HvcwSdkAPI.h                   SDK header file
         HvcwTypedef.h                  TypeDef definitions
         HvcwCommonDef.h                Error code definitions

      sample/
         src/                           JNI sample
            main/
               java/                    java source code
               jni/                     JNI source code
         libs/ 
            jar/
               HVCW.jar                 jar file

         demo/
            base/                       Basic sample demo project (Android Studio)


###[Notes on Usage]
* This source code, binary files and documentation are copyrighted properties of OMRON Corporation.
* Proper operation of this source code or of the binary files is not guaranteed.

### Acknowledgment
  The following freeware is included in this Software.

*****************************************************
OpenH264   http://www.openh264.org
*****************************************************
Copyright (c) 2013, Cisco Systems
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  
*************************************************
FFmpeg  https://www.ffmpeg.org
************************************************
https://www.ffmpeg.org/legal.html

************************************************
LDPC FEC Codes  http://planete-bcast.inrialpes.fr/articlec6d0.html?id_article=16
************************************************

LDPC FEC License
Thursday 6 April 2006. 

This codec is: 
-  Copyright (c) 2002-2006 INRIA - All rights reserved. 
-  Copyright (c) 1995-2003 by Radford M. Neal

It includes large portions of code written by Radford Neal and available here.

The code coming from Radford M. Neal is distributed under the following licence:
Permission is granted for anyone to copy, use, modify, or distribute these programs and accompanying documents for any purpose, provided this copyright notice is retained and prominently displayed, along with a note saying that the original programs are available from Radford Neal’s web page, and note is made of any changes made to these programs. These programs and documents are distributed without any warranty, express or implied. As the programs were written for research purposes only, they have not been tested to the degree that would be advisable in any important application. All use of these programs is entirely at the user’s own risk. 
The code coming from INRIA is distributed under the GNU/LGPL licence, with the following additional requirement:
 This copyright notice must be retained and prominently displayed, along with a note saying that the original programs are available from Vincent Roca’s web page, and note is made of any changes made to these programs.  
This FEC library can therefore freely be used in any program, commercial or not, open-source or not.

==== The curl license =====================================================
COPYRIGHT AND PERMISSION NOTICE

Copyright (c) 1996 - 2015, Daniel Stenberg, daniel@haxx.se.

All rights reserved.

Permission to use, copy, modify, and distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
OF THIRD PARTY RIGHTS. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE 
USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of a copyright holder shall
not be used in advertising or otherwise to promote the sale, use or other
dealings in this Software without prior written authorization of the
copyright holder.
========================================================================

==== OpenSSL License =====================================================
 Copyright (c) 1998-2011 The OpenSSL Project.  All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer. 

 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in
    the documentation and/or other materials provided with the
    distribution.

 3. All advertising materials mentioning features or use of this
    software must display the following acknowledgment:
    "This product includes software developed by the OpenSSL Project
    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"

 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
    endorse or promote products derived from this software without
    prior written permission. For written permission, please contact
    openssl-core@openssl.org.

 5. Products derived from this software may not be called "OpenSSL"
    nor may "OpenSSL" appear in their names without prior written
    permission of the OpenSSL Project.

 6. Redistributions of any form whatsoever must retain the following
    acknowledgment:
    "This product includes software developed by the OpenSSL Project
    for use in the OpenSSL Toolkit (http://www.openssl.org/)"

 THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 OF THE POSSIBILITY OF SUCH DAMAGE.

 This product includes cryptographic software written by Eric Young
 (eay@cryptsoft.com).  This product includes software written by Tim
 Hudson (tjh@cryptsoft.com).
========================================================================

----
OMRON Corporation 
Copyright(C) 2016 OMRON Corporation, All Rights Reserved.
