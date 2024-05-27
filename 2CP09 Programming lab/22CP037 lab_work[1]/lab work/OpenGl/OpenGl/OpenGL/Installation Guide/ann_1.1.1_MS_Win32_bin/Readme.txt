1. copy ANN.dll to C:\windows\system32
2. copy ANN.lib to c:\program files\microsoft visual studio.net\vc7\lib
3. copy all the header files of ANN sub directory into c:\program files\microsoft visual studio.net\vc7\include
4. Create new project into .NET using VC++ 32bit console application
5. change project properties --> linker --> input --> addtional libraries : ANN.lib

