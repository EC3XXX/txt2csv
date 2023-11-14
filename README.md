# txt2csv
transfer "txt with spaces and tabs" to "csv with ','" files


简单快捷的非标准txt转csv小工具

Easy and fast txt2csv transfer tool

可以下载spacemix.c查看源码，也可以直接使用spacemix.exe进行转换。

can check sourcecode by downloading spacemix.c file or use spacemix.exe as tool directly

将待转换的txt文件命名为test.txt放在和工具同一路径下，运行可执行文件即可得到output.csv文件。

name your target file as test.txt and put with this tool together, run .exe, then you can get output.csv file.


以下例：
Example:

test.txt:

1   234        34343    111

343  222 4 1

567 765 4343             888

asbs sss   epq j

转换后：
After transfer:

output.csv:

1,234,34343,111

343,222,4,1

567,765,4343,888

asbs,sss,epq,j


重要的提示：

Important:

重要的文件请注意备份，避免因程序或其他原因造成不必要的麻烦与损失

Backup important files to avoid unnecessary troubles

该工具为学习与实验性质的工具，且有独特的使用场景，因该工具造成的一切后果由使用者自行承担

This tool is experimental and academic use only with special occasion, all consequences shall be borne by the user


注意：

Tips:

1. 没有test.txt文件会报错
1. error occurs when missing 'test.txt' file

2. 生成的output.csv文件会将旧文件覆盖
2. old 'output.csv' file will be replaced by the new one

3. 过程中会生成temp_spacemix.txt作为临时文件，运行结束后自动删除，请注意不要自行创建同名文件
3. temp file 'temp_spacemix.txt' will be created during transfer, and deleted at last, please do not create 'temp_spacemix.txt' by yourself

4. 不要在转换同时打开test.txt文件，会使程序无法读取
4. please do not open 'test.txt' before programme starts, it will prevent file reading
