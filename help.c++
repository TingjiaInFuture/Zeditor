/**
ZTJ Zeditor 1.0
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
Every single word of it is written by ZTJ without any other open-source code.
There is NO WARRANTY, to the extent permitted by law.
!!Make sure your CMD is using UTF-8, otherwise type 'q' to quit then type"chcp 65001"!!
Type 'h' for help.
For bug reporting instructions, please go to:
<https://github.com/TingjiaInFuture/Zeditor>.

r <filename>        读入文件
w <filename>        保存文件
p {[i] [j]}         打印第i行(至第j行)
d 0 {[i] [j]}       删除第i行(至第j行)
d 1 <i> <j> [k]     删除第i行第j个字符(及其后k个字符)
K <i> <string>      从第i行开始查找string第一次出现的位置
i <i> [<j><string>] 插入新行于第i行(或于其第j个字符后插入string)
k                   检查括号是否匹配,匹配返回1,否则返回0
q                   退出
*/