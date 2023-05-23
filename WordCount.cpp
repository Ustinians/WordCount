#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ������������ͳ���ļ��е��ַ���
int count_chars(FILE *fp) {
    int count = 0; //��ʼ��������Ϊ0
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    while ((ch = fgetc(fp)) != EOF) { //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        count++; //ÿ��ȡһ���ַ�����������1
    }
    return count; //���ؼ�������ֵ
}

//����һ������������ͳ���ļ��еĵ�����
int count_words(FILE *fp) {
    int count = 0; //��ʼ��������Ϊ0
    char ch; //����һ���ַ����������ڴ洢��ȡ���ַ�
    int in_word = 0; //����һ����־�����������ж��Ƿ��ڵ����ڣ���ʼΪ0�����ڵ����ڣ�
    while ((ch = fgetc(fp)) != EOF) { //ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�������
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') { //��������ո񣬶��ţ����з����Ʊ��
            if (in_word) { //���֮ǰ�ڵ�����
                count++; //��������1
                in_word = 0; //��־������Ϊ0�����ڵ����ڣ�
            }
        } else { //������������ַ�
            in_word = 1; //��־������Ϊ1���ڵ����ڣ�
        }
    }
    if (in_word) { //����ļ�����ʱ���ڵ�����
        count++; //��������1
    }
    return count; //���ؼ�������ֵ
}

//������
int main(int argc, char *argv[]) {
    if (argc != 3) { //�����������������3��������������
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]); //��ӡʹ�÷���
        return -1; //����-1��ʾ�����˳�
    }
    FILE *fp = fopen(argv[2], "r"); //�������ļ�����ֻ��ģʽ
    if (fp == NULL) { //�����ʧ��
        printf("Cannot open file %s\n", argv[2]); //��ӡ������Ϣ
        return -1; //����-1��ʾ�����˳�
    }
    if (strcmp(argv[1], "-c") == 0) { //����ڶ�������Ϊ-c����ʾͳ���ַ�����
        int chars = count_chars(fp); //����count_chars�������õ��ַ���
        printf("Character count: %d\n", chars); //��ӡ���
    } else if (strcmp(argv[1], "-w") == 0) { //����ڶ�������Ϊ-w����ʾͳ�Ƶ�������
        int words = count_words(fp); //����count_words�������õ�������
        printf("Word count: %d\n", words); //��ӡ���
    } else { //����ڶ��������Ȳ���-cҲ����-w����ʾ��������
        printf("Invalid parameter: %s\n", argv[1]); //��ӡ������Ϣ
        return -1; //����-1��ʾ�����˳�
    }
    fclose(fp); //�ر��ļ�
    return 0; //����0��ʾ�����˳�
}

