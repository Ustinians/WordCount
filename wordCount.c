#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ������������ͳ���ļ��е��ַ���
int count_chars(FILE *fp){
    int count = 0; //��ʼ��������Ϊ0
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    while((ch = fgetc(fp)) != EOF){ //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        count++; //ÿ��ȡһ���ַ�����������1
    }
    return count; //���ؼ�������ֵ
}

//����һ������������ͳ���ļ��еĵ�����
int count_words(FILE *fp){
    int count = 0; //��ʼ��������Ϊ0
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    int in_word = 0; //����һ����־�����������ж��Ƿ��ڵ����ڣ���ʼΪ0�����ڵ����ڣ�
    while((ch = fgetc(fp)) != EOF){ //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        if(ch == ' ' || ch == ',' || ch == '\t' || ch == '\n'){ //��������ո񣬶��ţ��Ʊ�����з�
            if(in_word){ //���֮ǰ�ڵ�����
                count++; //��������1
                in_word = 0; //��־������Ϊ0�����ڵ����ڣ�
            }
        }
        else{ //������������ַ�
            in_word = 1; //��־������Ϊ1���ڵ����ڣ�
        }
    }
    if(in_word){ //����ļ�����ʱ���ڵ�����
        count++; //��������1
    }
    return count; //���ؼ�������ֵ
}

//����������
int main(int argc, char *argv[]){
    FILE *fp; //����һ���ļ�ָ����������ڴ��ļ�
    int result; //����һ�����ͱ��������ڴ洢ͳ�ƽ��

    if(argc != 3){ //��������в���������3�����������������Ʋ������ļ�����
        printf("Usage: wordCount.exe [parameter] [input_file_name]\n"); //��ӡʹ��˵��
        exit(1); //�˳����򣬷��ش�����1
    }

    fp = fopen(argv[2], "r"); //��ֻ��ģʽ��ָ�����ļ��������ļ�ָ�븳��fp
    if(fp == NULL){ //�����ʧ�ܣ��ļ������ڻ���Ȩ�ޣ�
        printf("Error: cannot open file %s\n", argv[2]); //��ӡ������Ϣ
        exit(2); //�˳����򣬷��ش�����2
    }

    if(strcmp(argv[1], "-c") == 0){ //������Ʋ���Ϊ-c����ʾͳ���ַ�����
        result = count_chars(fp); //����count_chars��������������ֵ����result
        printf("Character count: %d\n", result); //��ӡ���
    }
    else if(strcmp(argv[1], "-w") == 0){ //������Ʋ���Ϊ-w����ʾͳ�Ƶ�������
        result = count_words(fp); //����count_words��������������ֵ����result
        printf("Word count: %d\n", result); //��ӡ���
    }
    else{ //������Ʋ����Ȳ���-cҲ����-w����ʾ��Ч������
        printf("Error: invalid parameter %s\n", argv[1]); //��ӡ������Ϣ
        exit(3); //�˳����򣬷��ش�����3
    }

    fclose(fp); //�ر��ļ�

    return 0; //�����������򣬷���0

}
