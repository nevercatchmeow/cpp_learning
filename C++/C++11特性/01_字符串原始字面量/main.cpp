/*
    定义原始字面量：
        定义方式：R"xxx(原始字符串)xxx"，()两边的字符串可省略。
        作用：直接表示字符串的原始含义，而不进行转义或连接操作。

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>

void test()
{
#if 0
    // "\G"转义。
    std::string str1 = "E:\Github\test.txt";
    std::cout << str1 << std::endl;

    // 避免"\G"转义。
    std::string str2 = "E:\\Github\\test.txt";
    std::cout << str2 << std::endl;

    // 使用"\"连接符连接长字符串。
    std::string str3 = "<html>\
        <head>\
        <title>\
        海贼王\
        </title>\
        </head>\
        <body>\
        <p>\
        我是要成为海贼王的男人！\
        </p>\
        </body>\
        </html>";
    std::cout << str3 << std::endl;
#else
    std::string str1 = R"kevin(E:\Github\test.txt)kevin";
    std::cout << str1 << std::endl;

    std::string str2 = R"(<html>
        <head>
        <title>
        海贼王
        </title>
        </head>
        <body>
        <p>
        我是要成为海贼王的男人！
        </p>
        </body>
        </html>)";
    std::cout << str2 << std::endl;
#endif
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}