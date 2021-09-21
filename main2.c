//--------------------------- main.c
//JUL-30-2011, xiaolaba
//last update 2018-NOV-17, xiaolaba

// 2018-NOV-17, library has been update, https://www.teuniz.net/RS-232/
// November 22, 2017 new version

// all function named RS232_ as prefix
// fix the mian.c source code here, fucntion call add prefix "RS232_"
// MODE change from "N81" ro "8N1" 
// upload to Github, include library source code as original author license GNU GPL.

// how to compile
// install minGW, http://sourceforge.net/projects/mingw/files/
// Win10,
// run dosbox.bat,
// command line, set path=c:\MinGW\bin;%path%
// or command line, set_path.bat
// command line, compile.bat
// 
// Gcc, 沒有GDB 除錯資料的編譯 
//   gcc -static -o RS232.exe main.c RS232_xiaolaba.c
// 
//用G++, 包含GDB 除錯資料的編譯 g
//   ++ -g -static -o RS232.exe main.c RS232_xiaolaba.c

// 2021-SEP-21, test DTR / RTS pin control
 
#include <stdio.h> //wordpress 自動去除 < > 及內容, 解決辦法, 前後加空格
#include <stdlib.h>

 
#include "rs232.h" //wordpress 自動轉換雙引號為 半角符號, 無法解決
//原因參考以下
//http://farlee.info/archives/wordpress-format-quote-mark.html
 
//測試用, 打開 com port, 發送3byte資料, 關閉 com port
 
int main()
{
//int RS232_OpenComport(int comport_number, int baudrate, const char * mode)

//RS232_OpenComport(4, 9600, "N81"); //win32/ win64 底下有問題, 需要改library

//** change com port number array with one the first dummy element, or write COM#-1
//** Windows COM PORT number is COM1,COM2, index is -1
//  RS232_OpenComport(6-1, 115200, "8N1"); //win32/ win64 底下有問題, 需要改library

  int comport=3;
  int c;

// 2021-SEP-21, test DTR / RTS pin control

  printf("wanna open COM%d\n", comport);
  //RS232_OpenComport(comport, 115200, "8N1"); //win32/ win64 底下有問題, 需要改library
  if ( (RS232_OpenComport(comport, 115200, "8N1") ) == 1 ) {	
	  printf("Press ENTER to Continue\n"); getchar();
	  exit(-1);		// no comport or error, end the program
  }

  //// com port opened, send byte testing
  RS232_SendByte(comport, 'S');
  char i;
  for(i=0x30;i<0x40;i++){
    RS232_SendByte(comport, i);
  }
 
  //// control output pin, DTR and RTS
  RS232_enableDTR(comport);
  RS232_enableRTS(comport);
  
  printf("enabled DTR & RTS of COM%d\n", comport);
  printf("USB->COM (i.e. CP2102) usually the pin is 0V now, ");
  printf("Press ENTER to Continue\n"); getchar();


  
  RS232_disableDTR(comport);
  RS232_disableRTS(comport);
  
  printf("disabled DTR & RTS of COM%d\n", comport);
  printf("USB->COM (i.e. CP2102) usually the pin is 3.3V now, ");
  printf("Press ENTER to Continue\n"); getchar();
  
  printf("byebye\n");  
  RS232_CloseComport(comport);

}
 
//--------------------------- main.c