rem //-----------------
rem compile.bat
rem //-----------------
rem �p�G���� -static �ﶵ, Windows ����, ��������
rem path = c:\MinGW\bin ��
rem �ƻs libgcc_s_dw2-1.dll �쥻��Ƨ�
rem JUL/31/2011, xiaolaba
 
rem ��Gcc, �S��GDB ������ƪ��sĶ
gcc -static -o Test_DTR_RTS.exe main2.c RS232_xiaolaba.c
 
rem ��G++, �]�tGDB ������ƪ��sĶ
g++ -g -static -o Test_DTR_RTS_gdb.exe main2.c RS232_xiaolaba.c