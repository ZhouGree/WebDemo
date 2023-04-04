#include "sort.h"

void insertSort(int* a, int n) {
	if (a == NULL || n==0) {
		printf("���������Ϊ�գ��޷�����");
		return;
	}
	/*int front = a[0], latter = a[0], len = sizeof(a) / sizeof(a[0]) - 1;
	if (n > len) {
		n = len;
	}*/
	int front = a[0], latter = a[0];
	for (int i = 1; i < n; i++) {
		front = a[i - 1];
		latter = a[i];
		for (int j = i - 1; j >= 0; j--) {
			
			if (latter > front) {
				break;
			}
			//�ѽϴ�������Ƶ����
			if (a[j] > latter ) {
				a[j + 1 ] = a[j];
				//����ȵ�һ��Ԫ��С������ڵ�һ��λ��
				if (j == 0)
					a[j] = latter;
				continue;
			}
			//�ҵ�����С�������嵽������
			else if(a[j] <= latter)
			{
				a[j + 1] = latter;
				break;
			}
		}
	}
}

void Merge(int* a, int begin, int mid, int end, int* temp) {
 	int i = begin, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		//������������
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= end) {
		temp[k] = a[j];
		j++;
		k++;
	}
	//������õ�Ԫ��
	for (int i = 0; i < k; i++) {
		a[begin + i] = temp[i];
	}

}

void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	//�õݹ��˼������鲻�ϻ���ֱ��������ֻʣһ��Ԫ��
	if (begin < end ) {
		MergeArray(a, begin, (begin + mid) / 2, mid, temp);
		MergeArray(a, mid + 1, (mid + 1 + end) / 2, end, temp);
		Merge(a, begin, mid, end, temp);
	}
}

void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin >= end)
		return;
	//�õݹ��Ȱ����黮��
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid + 1, end, temp);
	int i = begin, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[begin + i] = temp[i];
}

void QuickSort_Recursion(int* a, int begin, int end) {
	if (a == NULL) {
		printf("���������Ϊ�գ��޷�����");
		return;
	}
	if (begin > end)
		return;
	/*int len = (sizeof(a) / sizeof(a[0])) - 1;
	if (end > len) {
		end = len;
	}*/
	int key = a[begin], b = begin, e = end, change ;
	while (b != e) {
		//�������ұ߿�ʼ�ҳ���keyС����
		while (a[e] >= key && e > b) {
			e--;
		}
		//��������߿�ʼ�ҳ���key�����
		while (a[b] <= key && e > b)
		{
			b++;
		}
		//������������
		if (e > b) {
			change = a[e];
			a[e] = a[b];
			a[b] = change;
		}
	}
	//���û�н������Ǹ�Ԫ�ر�key���Ǿ����Ǹ�Ԫ��ǰһԪ����key����
	if (a[b] > key)
	{
		//a[b-1]�ض���keyС
		change = a[b - 1];
		a[b - 1] = a[begin];
		a[begin] = change;
	}
	else
	{
		//������û�н������Ǹ�Ԫ�ر�keyС�����߾ͽ�����
		change = a[b];
		a[b] = a[begin];
		a[begin] = change;
	}
	//�õݹ鲻�϶����߿���
	QuickSort_Recursion(a, begin, b - 1);
	QuickSort_Recursion(a, b + 1, end);
}

void QuickSort(int* a, int size) {
	//
	int* stack = (int*)malloc(size * sizeof(int));
	int top = -1, begin = 0, end = 0;
	//��βλ���Ⱥ���ջ
	if (top < size - 1) {
		stack[++top] = 0;
		stack[++top] = size - 1;
	}
	//ջ����Ϊ-1�����ǿ�ջ
	while (top >= 0)
	{
		//��βλ���Ⱥ��ջ
		end = stack[top--];
		begin = stack[top--];
		//���м���Ϊ����
		int pivot = a[(begin + end) / 2];
		int i = begin, j = end, change = 0;
		while (i < j) {
			//������ҳ���������Ԫ��
			while (a[i] < pivot)
				i++;
			//���ұ��ҳ���������Ԫ��
			while (a[j] > pivot)
			{
				j--;
			}
			//������û�н�����ʵ�ʱ�򻥻�
			if (i <= j) {
				change = a[i];
				a[i] = a[j];
				a[j] = change;
				i++;
				j--;
			}
		}
		//��jû���ߵ�������λ��,iû���ߵ�����βλ��
		if (begin < j) {
			stack[++top] = begin;
			stack[++top] = j;
		}
		if (i < end) {
			stack[++top] = i;
			stack[++top] = end;
		}

	}
}

int Partition(int* a, int begin, int end) {
	if (begin >= end)
		return 0;
	//�ҵ�һ��Ԫ�ص�����
	int pivot = a[begin], i = begin, j = end;
	while (i < j) {
		//���ұ��ұ�����С��Ԫ��
		while (a[j] >= pivot && i < j)
			j--;
		
		a[i] = a[j];
		//������ұ�������Ԫ��
		while (a[i] <= pivot && i < j)
		{
			i++;
		}
		a[j] = a[i];
	}
	//����ѭ����������µ��Ǹ�Ԫ�ظ��ǵ��ˣ����ڸ�ֵ��ȥ
	a[j] = pivot;
	//�õݹ���������߿���
	Partition(a, begin, i - 1);
	Partition(a, i + 1, end);
	//return 1;
}

void QuickSort_Random(int* a, int begin, int end) {
	if (begin > end)
		return;
	//������һ��Ԫ�ص�����
	int random = ((rand() % (end - begin + 1)) + begin);
	int b = begin, e = end, pivot = a[begin], change;
	a[begin] = a[random];
	a[random] = pivot;
	//�����Ԫ�ػ�����λ��
	pivot = a[begin];
	while (b != e) {
		while (a[e] >= pivot && e > b) {
			e--;
		}
		while (a[b] <= pivot && e > b)
		{
			b++;
		}
		if (e > b) {
			change = a[e];
			a[e] = a[b];
			a[b] = change;
		}
	}
	//���źú󣬽�������һ��������С��������
	if (a[b] > pivot)
	{
		change = a[b - 1];
		a[b - 1] = a[begin];
		a[begin] = change;
	}
	else
	{
		change = a[b];
		a[b] = a[begin];
		a[begin] = change;
	}
	QuickSort_Random(a, begin, b - 1);
	QuickSort_Random(a, b + 1, end);

} 

void QuickSort_Three(int* a, int begin, int end, int mid) {
	if (a == NULL) {
		printf("���������Ϊ�գ��޷�����");
		return;
	}
	//ȡ�м��Ԫ��Ϊ����
	int pivot = a[begin], x1 = a[begin], x2 = a[mid], x3 = a[end];
	if (x1 <= x2 && x2 <= x3) {
		a[begin] = x2;
		a[mid] = pivot;
	}
	else if(x2 <= x3 && x3 <= x1)
	{
		a[begin] = x3;
		a[end] = pivot;
	}
	//���������Ƶ���λ��
	pivot = a[begin];
	if (begin > end)
		return;
	int b = begin, e = end, change;
	while (b != e) {
		while (a[e] >= pivot && e > b) {
			e--;
		}
		while (a[b] <= pivot && e > b)
		{
			b++;
		}
		if (e > b) {
			change = a[e];
			a[e] = a[b];
			a[b] = change;
		}
	}
	if (a[b] > pivot)
	{
		change = a[b - 1];
		a[b - 1] = a[begin];
		a[begin] = change;
	}
	else
	{
		change = a[b];
		a[b] = a[begin];
		a[begin] = change;
	}
	int mid1 = (begin + b - 1) / 2, mid2 = (b + 1 + end) / 2;
	a[b] = pivot;
	QuickSort_Three(a, begin, b - 1, mid1);
	QuickSort_Three(a, b + 1, end, mid2);
}

void CountSort(int* a, int size, int max) {
	/*int len = sizeof(a) / sizeof(a[0]), max1 = max + 1;
	if (size > len) {
		size = len;
	}*/
	if (size <= 0 || max <= 0) {
		return;
	}
	//���������鿪��һ����һ����ڴ�ռ�
	int max1 = max + 1;
	int* p = (int*)malloc(max1 * sizeof(int)), * p2 = (int*)malloc(size * sizeof(int));
	int num;
	//�����������ʼ��Ϊ0������Ӱ����
	for (int i = 0; i <= max; i++) {
		p[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		p2[i] = a[i];
	}
	//����
	for (int i = 0; i < size; i++) {
		num = a[i];
		p[num] += 1;
	}
	//����ۼӣ����ӦԪ�ص�ֵ������λ��
	for (int i = 1; i <= max; i++) {
		p[i] += p[i - 1];
	}
	//���ݼ���������±������Ӧ��ֵ��ֵ��a����
	for (int i = size - 1 ; i >= 0; i--) {
		num = p2[i];
		a[p[num] - 1] = p2[i];
		p[num] -= 1;
	}
	free(p);
	free(p2);
}

void RadixCountSort(int* a, int size) {
	if (size <= 0) {
		return;
	}
	int max = a[0];
	//�ҳ����ֵ
	for (int i = 0; i < size; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int max1 = max + 1, radix = 1;
	int* p = (int*)malloc(size * sizeof(int)), * count = (int*)malloc(sizeof(int) * max1);
	while (max / radix > 0) {
		for (int i = 0; i <= max; i++)
			count[i] = 0;
		for (int i = 0; i < size; i++)
			count[a[i] / radix % 10] += 1;
		for (int i = 1; i <= max; i++)
			count[i] += count[i - 1];
		for (int i = size - 1; i >= 0; i--)
			p[--count[a[i] / radix % 10]] = a[i];
		for (int i = 0; i < size; i++)
			a[i] = p[i];
		//
		radix *= 10;
	}

	free(count);
	free(p);
}

void ColorSort(int* a, int size) {
	if (a == NULL) {
		printf("���������Ϊ�գ��޷�����");
		return;
	}
	/*int m, len = sizeof(a) / sizeof(a[0]);
	if (size > len) {
		size = len;
	}*/
	int m;
	int* p1 = a, * p2 = a + size - 1, * p = a;
	for (int i = 0; i < size; i++) {
		//ʹpָ��Ϊ0��Ԫ��
		for (; *p == 0;) {
			p++;
		}
		//���p1ָ��0���ͺͲ�ָ��0��p����
		if (p1[i] == 0 && (&p1[i]) > p) {
			m = p1[i];
			p1[i] = *p;
			*p = m;
			p++;
		}
		else if(p1[i] == 2)
		{
			//���p1ָ��2���ͺͲ�ָ��2��p2����
			m = p1[i];
			p1[i] = *p2;
			*p2 = m;
			p2--;
		}
		//ʹp2ָ��Ϊ2��Ԫ��
		for (; *p2 == 2;) {
			p2--;
		}
		//���p1[i]�ĵ�ַ����p2ָ��ĵ�ַһ�������˳�ѭ��
		if(&p1[i] == p2)
		{
			break;
		}
	}
}

