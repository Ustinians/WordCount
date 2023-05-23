#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个函数，用于统计文件中的字符数
int count_chars(FILE *fp){
    int count = 0; //初始化计数器为0
    char ch; //定义一个字符变量，用于存储读取的字符
    while((ch = fgetc(fp)) != EOF){ //循环读取文件中的每个字符，直到遇到文件结束符
        count++; //每读取一个字符，计数器加1
    }
    return count; //返回计数器的值
}

//定义一个函数，用于统计文件中的单词数
int count_words(FILE *fp){
    int count = 0; //初始化计数器为0
    char ch; //定义一个字符变量，用于存储读取的字符
    int in_word = 0; //定义一个标志变量，用于判断是否在单词内，初始为0（不在单词内）
    while((ch = fgetc(fp)) != EOF){ //循环读取文件中的每个字符，直到遇到文件结束符
        if(ch == ' ' || ch == ',' || ch == '\t' || ch == '\n'){ //如果遇到空格，逗号，制表符或换行符
            if(in_word){ //如果之前在单词内
                count++; //计数器加1
                in_word = 0; //标志变量置为0（不在单词内）
            }
        }
        else{ //如果遇到其他字符
            in_word = 1; //标志变量置为1（在单词内）
        }
    }
    if(in_word){ //如果文件结束时还在单词内
        count++; //计数器加1
    }
    return count; //返回计数器的值
}

//定义主函数
int main(int argc, char *argv[]){
    FILE *fp; //定义一个文件指针变量，用于打开文件
    int result; //定义一个整型变量，用于存储统计结果

    if(argc != 3){ //如果命令行参数不等于3（包括程序名，控制参数和文件名）
        printf("Usage: wordCount.exe [parameter] [input_file_name]\n"); //打印使用说明
        exit(1); //退出程序，返回错误码1
    }

    fp = fopen(argv[2], "r"); //以只读模式打开指定的文件，并将文件指针赋给fp
    if(fp == NULL){ //如果打开失败（文件不存在或无权限）
        printf("Error: cannot open file %s\n", argv[2]); //打印错误信息
        exit(2); //退出程序，返回错误码2
    }

    if(strcmp(argv[1], "-c") == 0){ //如果控制参数为-c（表示统计字符数）
        result = count_chars(fp); //调用count_chars函数，并将返回值赋给result
        printf("Character count: %d\n", result); //打印结果
    }
    else if(strcmp(argv[1], "-w") == 0){ //如果控制参数为-w（表示统计单词数）
        result = count_words(fp); //调用count_words函数，并将返回值赋给result
        printf("Word count: %d\n", result); //打印结果
    }
    else{ //如果控制参数既不是-c也不是-w（表示无效参数）
        printf("Error: invalid parameter %s\n", argv[1]); //打印错误信息
        exit(3); //退出程序，返回错误码3
    }

    fclose(fp); //关闭文件

    return 0; //正常结束程序，返回0

}
