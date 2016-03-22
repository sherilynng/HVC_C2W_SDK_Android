# HVC-C2W Android-SDK by OMRON

### 1. SDK内容
  Android端末からオムロン製HVC-C2Wを制御するためのSDKを提供します。
  本SDKはファームウェアのバージョンV04.02.01以降対応しております。
  ファームウェアのバージョンが古い場合はアップデートしてください。

### 2. ご利用方法
  2.1 同梱の「HVC-C2W SDK使用許諾契約」をお読み頂き、
      同意いただける場合のみ本SDKをご利用頂けます。

  2.2 本SDKをご利用頂くにはSensingEggProjectメンバーサイトへの　
      メンバー登録（無料）が必要です。
      http://plus-sensing.omron.co.jp/member/sdk/

  2.3 WebAPIを使用してサーバにアクセスするためにはApiKey、アプリからカメラ
      を使用するにはアプリ固有のAppIDが必要となります。
      どちらもSensingEggProjcetメンバーサイト内の「APIキー申請フォーム」より
      ご申請下さい。
      尚、AppIDはHVCW_SetAppID関数にてカメラにご設定下さい。


### 3. ディレクトリ構成
      doc/
         HVC-C2W_WebAPI仕様書      HVC-C2Wを使用する為のクラウドサーバWebAPI仕様書
         HVC-C2W_API仕様書         HVC-C2Wを制御する為のAPI仕様書
         HVC-C2W開発者ガイド       HVC-C2Wの開発者ガイド
      libs/                        HVC-C2W SDKバイナリファイル本体
      include/
         HvcwSdkAPI.h              SDKヘッダファイル
         HvcwTypedef.h             TypeDef定義
         HvcwCommonDef.h           エラーコード定義

      sample/
         src/                      JNIサンプル
            main/
               java/               javaソースコード
               jni/                JNIソースコード
         libs/
            jar/
               HVCW.jar            jarファイル

         demo/
            base/                  基本サンプルデモプロジェクト(Android Studio)


###[ご使用にあたって]
* 本ソースコード、バイナリファイルおよびドキュメントの著作権はオムロンに帰属します。
* 本ソースコード及びバイナリファイルは動作を保証するものではありません。

### 謝辞
  本ソフトウェアには、以下フリーウェアソフトウェアが含まれています。

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
オムロン株式会社  
Copyright(C) 2015 OMRON Corporation, All Rights Reserved.
