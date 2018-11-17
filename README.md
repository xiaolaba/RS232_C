# RS232_C
test C RS232 library, reference, https://www.teuniz.net/RS-232/  

testing, done  
win10 x64  
modified rs232.c  
changed COM port array, 17 items,   
1st item is dummy for index 0, so index 1 = "\\\\.\\.COM1" and so on  
MinGW used  


~~~
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

  printf("wanna open COM6\n");
  RS232_OpenComport(6, 115200, "8N1"); //win32/ win64 底下有問題, 需要改library

  RS232_SendByte(3, 'S');
  char i;
 
  for(i=0x30;i<0x40;i++){
    RS232_SendByte(3, i);
  }
 
  RS232_CloseComport(4);

}
 
//--------------------------- main.c
~~~
