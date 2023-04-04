#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

#define MAXK 1e5

void showFunction() {
	printf("\n\n\n<<<Function Menu>>>\n");
	printf("   1. ���������㷨\n");
	printf("   2. �鲢����\n");
	//printf("   3. �鲢����\n");
	printf("   3. ��������\n");
	//printf("   5. �������򣨷ǵݹ�棩\n");
	//printf("   6. �������������ţ�\n");
	printf("   4. ��������\n");
	printf("   5. ������������\n");
	printf("   6. ��ɫ����(ֻ��012��������)\n");
	printf("   7. �˳�\n");
	printf("   ��������Ӧ������");

}

//����������ݣ������浽�ļ���
void Random_Save(int num, char Typename[]) {
	if (num == 0) {
		return;
	}
	FILE* fp;
	srand((unsigned int)time(NULL));
	//int* p = (int*)malloc(num * sizeof(int));
	int temp = 0;
	if ((fp = fopen(Typename, "w")) == NULL) {
			printf("�����ļ�ʧ�ܣ�\n");
			exit(0);
	}
	for (int i = 0; i < num; i++)
	{
		if (strcmp(Typename, "��������.txt") == 0) {
			//assert(p);
			//*(p + i) = rand() % 1000;
			temp = rand() % 1000;
		}
		else if (strcmp(Typename, "ֻ��012������.txt") == 0) {
			//assert(p);
			//*(p + i) = rand() % 3;
			temp = rand() % 3;
		}
		//assert(p);
		fprintf(fp, "%d\t", temp);
	}
	//д�������־�������ȡ����
	fputs("\nover\n", fp);
	printf("\n�����ѱ��棡\n");
	//free(p);
	fclose(fp);
}

//���ļ��ж�ȡ����
int* Open(int num,char Typename[]) {
	FILE* fp;
	int* p = (int*)malloc(num * sizeof(int));
	if ((fp = fopen(Typename, "r")) == NULL) {
		printf("���ļ�ʧ�ܣ�\n");
		return NULL;
	}
	while(!feof(fp))
	{
		for (int i = 0; i < num; i++) {
			assert(p);
			fscanf_s(fp, "%d", &p[i]);
		}
		return p;
	}
	return NULL;

}

void showTest() {
	printf("\n\n\n<<<Test Menu>>>\n");
	printf("   1. ��������������\n");
	printf("   2. ֻ��012������\n");
	printf("   ��������Ӧ������");
}

//�������Ԫ��
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ȡ�����ҷ�ֹ������
int judge_int(void)
{
	int len, num = 0, arg = 1;
	char word[10] = "\0";
	int m, j = 1, k = 0;
	while (j)
	{
		scanf_s("\t\t\t\t\t%s", word, 10);
		len = strlen(word);
		for (m = 0; m < len; m++)
		{
			//��������������
			if (word[m] < '0' || word[m]>'9')
			{
				printf("������������");
				break;
			}
			else
			{
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	//���ַ���������
	for (m = 0; m < len; m++)
	{
		for (int i = 0; i <= j; i++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	num = num / 10;
	return num;
}

//�ҳ��������ֵ
int Max(int* a, int size) {
	if (a == NULL) {
		return 0;
	}
	int max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

clock_t start, stop;

double duration;

int main() {
	int choice, num = 0, mid = 0, max = 0;
	char Type[20] = "��������.txt";
	int* p = NULL, * temp = NULL;
	do
	{
		showFunction();
		choice = judge_int();
		system("cls");
		switch (choice)
		{
		case 1: 
		{
			printf("<<<��������>>>��\n");
			showTest();
			choice = judge_int();
			//��ȡ����������
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num, Type);
			p = Open(num, Type);
			//��������ʱ�䣬����ִ�г���ƽ��ֵ
			if(num < 10000)
			{
				start = clock();
				for (int i = 0; i < MAXK; i++)
					insertSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				//�������������
				printf("����������ʱ��%2.3e seconds\n", duration);
				Print(p, num);
			}
			else
			{
				start = clock();
				insertSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK ;
				//�������������
				printf("����������ʱ��%2.3e seconds\n", duration);
				
			}
			free(p);
			p = NULL;
			break;
		}
		case 2:
		{
			printf("<<<�鲢��������>>>��\n");
			showTest();
			choice = judge_int();
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			//��ȡ����������ͬʱ��ȷ��tempҪ���ٿռ�Ĵ�С
			num = num + 1;
			mid = (num - 2) / 2;
			temp = (int*)malloc(num * sizeof(int));
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num - 1, Type);
			p = Open(num - 1, Type);
			//��������ʱ��
			if (num < 10001) {
				start = clock();
				for (int i = 0; i < MAXK; i++)
					MergeArray(p, 0, mid, num - 2, temp);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("������ϲ����鲢������ʱ��%2.3e seconds\n", duration);
				Print(p, num - 1);

				p = Open(num - 1, Type);
				start = clock();
				for (int i = 0; i < MAXK; i++)
					MergeSort(p, 0, num - 2, temp);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("�鲢������ʱ��%2.3e seconds\n", duration);
				Print(p, num - 1);
			}
			else
			{
				start = clock();
				MergeArray(p, 0, mid, num - 2, temp);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK ;
				printf("������ϲ����鲢������ʱ��%2.3e seconds\n", duration);

				p = Open(num - 1, Type);
				start = clock();
				MergeSort(p, 0, num - 2, temp);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK ;
				printf("�鲢������ʱ��%2.3e seconds\n", duration);
			}
			free(temp);
			free(p);
			p = NULL;
			break;
		}
		case 3:
		{
			printf("<<<��������>>>��\n");
			showTest();
			choice = judge_int();
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			mid = (num-1) / 2;
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num, Type);
			p = Open(num, Type);
			if (num < 10000) {
				start = clock();
				for (int i = 0; i < MAXK; i++)
					QuickSort_Recursion(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("�ݹ�����������ʱ��%2.3e seconds\n", duration);
				Print(p, num);

				p = Open(num, Type);
				start = clock();
				for (int i = 0; i < MAXK; i++)
					QuickSort(p, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("�ǵݹ�����������ʱ��%2.3e seconds\n", duration);
				Print(p, num);

				p = Open(num, Type);
				start = clock();
				for (int i = 0; i < MAXK; i++)
					QuickSort_Recursion(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("ѡ��һ��Ԫ��Ϊ��������������ʱ��%2.3e seconds\n", duration);
				Print(p, num);

				p = Open(num, Type);
				start = clock();
				for (int i = 0; i < MAXK; i++)
					QuickSort_Random(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("�����������������ʱ��%2.3e seconds\n", duration);
				Print(p, num);

				p = Open(num, Type);
				start = clock();
				for (int i = 0; i < MAXK; i++)
					QuickSort_Three(p, 0, num , mid);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("������������������ʱ��%2.3e seconds\n", duration);
				Print(p, num);
			}
			else
			{
				start = clock();
				QuickSort_Recursion(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK;
				printf("�ݹ�����������ʱ��%2.3e seconds\n", duration);

				p = Open(num, Type);
				start = clock();
				QuickSort(p, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK;
				printf("�ǵݹ�����������ʱ��%2.3e seconds\n", duration);
				
				p = Open(num, Type);
				start = clock();
				QuickSort_Recursion(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK;
				printf("ѡ��һ��Ԫ��Ϊ��������������ʱ��%2.3e seconds\n", duration);
				
				p = Open(num, Type);
				start = clock();
				QuickSort_Random(p, 0, num - 1);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK ;
				printf("�����������������ʱ��%2.3e seconds\n", duration);
				
				p = Open(num, Type);
				start = clock();
				QuickSort_Three(p, 0, num , mid);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK;
				printf("������������������ʱ��%2.3e seconds\n", duration);
			}
			free(p);
			p = NULL;
			break;
		}
	    case 4:
		{
			printf("<<<��������>>>��\n");
			showTest();
			choice = judge_int();
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num, Type);
			p = Open(num, Type);
			max = Max(p, num);
			if (num < 100000) {
				start = clock();
				for (int i = 0; i < MAXK; i++)
					CountSort(p, num, max);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("����������ʱ��%2.3e seconds\n", duration);
				Print(p, num);
			}
			else
			{
				start = clock();
				CountSort(p, num, max);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK;
				printf("����������ʱ��%2.3e seconds\n", duration);

			}
			free(p);
			p = NULL;
			break;
		}
		case 5:
		{
			printf("<<<������������>>>��\n");
			showTest();
			choice = judge_int();
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num, Type);
			p = Open(num, Type);
			if (num < 10000) {
				start = clock();
				for (int i = 0; i < MAXK; i++)
					RadixCountSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("��������������ʱ��%2.3e seconds\n", duration);
				Print(p, num);
			}
			else
			{
				start = clock();
				RadixCountSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK ;
				printf("��������������ʱ��%2.3e seconds\n", duration);
			}
			free(p);
			p = NULL;
			break;
		}
		case 6:
		{
			printf("<<<��ɫ����>>>��\n");
			showTest();
			choice = judge_int();
			printf("������Ҫ���Ե���������\n");
			num = judge_int();
			if (choice == 2) {
				strcpy(Type, "ֻ��012������.txt");
			}
			else
			{
				strcpy(Type, "��������.txt");
			}
			Random_Save(num, Type);
			p = Open(num, Type);
			if (num < 100000) {
				start = clock();
				for (int i = 0; i < MAXK; i++)
					ColorSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("��ɫ������ʱ��%2.3e seconds\n", duration);
				Print(p, num);
			}
			else
			{
				start = clock();
				ColorSort(p, num);
				stop = clock();
				duration = ((double)(stop - start)) / CLK_TCK / MAXK;
				printf("��ɫ������ʱ��%2.3e seconds\n", duration);
			}
			free(p);
			p = NULL;
			break;
		}
		case 7:
		{
			if (p != NULL) {
				free(p);
			}
			
			break;
		}
		default:
		{
			
			printf("�������������֣���1-7��\n");
			break;
		}
		}
	} while (choice != 7);
	
}