#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个函数，用于统计文件中的字符数
int count_chars(FILE *fp) {
    int count = 0; //初始化计数器为0
    char ch; //定义一个字符变量，用于存储读取的字符
    while ((ch = fgetc(fp)) != EOF) { //循环读取文件中的每个字符，直到遇到文件结束符
        count++; //每读取一个字符，计数器加1
    }
    return count; //返回计数器的值
}

//定义一个函数，用于统计文件中的单词数
int count_words(FILE *fp) {
    int count = 0; //初始化计数器为0
    char ch; //定义一个字符变量，用于存储读取的字符
    int in_word = 0; //定义一个标志变量，用于判断是否在单词内，初始为0（不在单词内）
    while ((ch = fgetc(fp)) != EOF) { //循环读取文件中的每个字符，直到遇到文件结束符
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') { //如果遇到空格，逗号，换行符或制表符
            if (in_word) { //如果之前在单词内
                count++; //计数器加1
                in_word = 0; //标志变量置为0（不在单词内）
            }
        } else { //如果遇到其他字符
            in_word = 1; //标志变量置为1（在单词内）
        }
    }
    if (in_word) { //如果文件结束时还在单词内
        count++; //计数器加1
    }
    return count; //返回计数器的值
}

//主函数
int main(int argc, char *argv[]) {
    if (argc != 3) { //如果参数个数不等于3（包括程序名）
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]); //打印使用方法
        return -1; //返回-1表示错误退出
    }
    FILE *fp = fopen(argv[2], "r"); //打开输入文件，以只读模式
    if (fp == NULL) { //如果打开失败
        printf("Cannot open file %s\n", argv[2]); //打印错误信息
        return -1; //返回-1表示错误退出
    }
    if (strcmp(argv[1], "-c") == 0) { //如果第二个参数为-c（表示统计字符数）
        int chars = count_chars(fp); //调用count_chars函数，得到字符数
        printf("Character count: %d\n", chars); //打印结果
    } else if (strcmp(argv[1], "-w") == 0) { //如果第二个参数为-w（表示统计单词数）
        int words = count_words(fp); //调用count_words函数，得到单词数
        printf("Word count: %d\n", words); //打印结果
    } else { //如果第二个参数既不是-c也不是-w（表示参数错误）
        printf("Invalid parameter: %s\n", argv[1]); //打印错误信息
        return -1; //返回-1表示错误退出
    }
    fclose(fp); //关闭文件
    return 0; //返回0表示正常退出
}

