rem //-----------------
rem compile.bat
rem //-----------------
rem �p�G���� -static �ﶵ, Windows ����, ��������
rem path = c:\MinGW\bin ��
rem �ƻs libgcc_s_dw2-1.dll �쥻��Ƨ�
rem JUL/31/2011, xiaolaba
 
rem ��Gcc, �S��GDB ������ƪ��sĶ
gcc -static -o RS232.exe main.c RS232_xiaolaba.c
 
rem ��G++, �]�tGDB ������ƪ��sĶ
g++ -g -static -o RS232_db.exe main.c RS232_xiaolaba.c