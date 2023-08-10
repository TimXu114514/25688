/*������־��
�����������Բ�
һ��List ArrayList LinkedList(�����ָ�룩
	1�����飻��С��a[MaxSize]��Ԫ��Ϊint��
	2��ÿ���������Ҫ���list��������/Ҫ�����listʱ����� print_r ����testĿ¼�������в���
����Search
	1��Search_1:������ӦԪ�أ����ȫ���±ꡰ����Ԫ��x����list�ϲ���x�������pos[]��*��������->��� printf("%d",a[i]) ->����������/
								  ������ȫ��->�����
								   ���ַ�����Ҫ��¼ȫ������Ҫ���Ԫ�ص��±꣬������ɾ�ƣ�
								   ����Ҫ���������Ӧ������Ӧ���������ͽ��и�ֵ����Ѱ����������
							 *!*(1)������һ��ͬ��С������Ϊ�±����¼�±꣬���һ�β�����ͨ��Clean���
	2��Search_2:������Ӧ�±�->���Ԫ�أ�int Search atl��������pos����list�ϻ�ȡԪ�ء�
	3��������1����2�������϶���ͨ���±���в���
����append/insert
	1�������Ƿ����ListSize��= MaxSize
	2����ָ������λ��append/ָ������λ��insert �����±�+Ԫ�أ��±��ӦԪ�أ�
	3����ָ����CurrentPos�����Ԫ��
	   ָ����a[ListSize+1]=a[ListSize]
	->4�����Ԫ��ͬʱadd�ķ���
							���addԪ�ظ���y,��Ӧ�±꣬�����±���pos[]
							Ԫ����ֽ׶�
�ġ�Delete
	1��ͬadd����
	2����Delete������ֻ�С��±��ӦԪ�ء������С�Ԫ�ض�Ӧ�±ꡱ������Search_1��¼���±�����в���
�塢Modify/Swap
	1���滻�±��ӦԪ��
	2���滻ȫ��ָ��Ԫ�� Search_1�����±����
��������
	1�����������ֳɵĴ���
�ߡ�Remove
	1������
		   1)ȫ��Ԫ���滻Ϊ0
	2����Ȼlistһ��ʼ�ʹ����������飬Clean����ʲô���ã���ʡ�ڴ�
*/
#include <iostream>
#include <math.h>
#include "stdlib.h"
#include "ArrayList.h"
#include <stdio.h>


using namespace std;

//������Ϣչʾ
void showBasicInfo(ArrayList alist) {
	int maxSize = alist.getMaxSize();
	int listSize = alist.getListSize();
	int currentPos = alist.getCurrentPos();
	int* list = alist.getList();
	//��ȡmaxSize
	cout << "��󳤶�Ϊ" << maxSize << endl;
	//��ȡlistSize
	cout << "���鳤��Ϊ" << listSize << endl;
	//��ȡcurrentPos
	cout << "��ǰλ��Ϊ" << currentPos << endl;
	//��ȡ��ǰalist		
	for (int i = 0; i < listSize - 1; i++) {
		cout << list[i] << " ";
	}
	cout << list[listSize - 1] << endl;
}

//��������Ҫ��ֵ
void showAllPos(ArrayList alist) {
	int value;
	cout << "������Ҫ������ֵ(������ʾ���и�ֵ��λ�ã���0��ʼ)" << endl;
	cin >> value;
	int* p = alist.searchAllValue(value);
	int listSize = alist.getListSize();
	//Position = alist.searchAllValue(value);
	for (int i = 0; i < listSize - 1; i++)
		cout << p[i] << " ";
	cout << p[listSize] << endl;
	delete[] p;
}
//
void changeCurrentPos(ArrayList* alist) {
	int position;
	cout << "������Ҫǰ����λ��" << endl;
	cin >> position;
	if (alist->setCurrentPos(position) == false) {
		cout << "Ҫ���λ�ò����ڣ�����" << endl;
	}
	else {
		cout << "λ���޸ĳɹ�������" << endl;
	}
}
//
void showPos(ArrayList alist) {
	int value;
	cout << "������Ҫ������ֵ(����ʾ��һ����ֵ��λ��)" << endl;
	cin >> value;
	int position = alist.searchValue(value);
	if (position != -1)
		cout << "��һ����ֵ��λ��Ϊ" << position << endl;
}
//
void showValue(ArrayList alist) {
	int position;
	cout << "������Ҫ����λ��" << endl;
	cin >> position;
	int value = alist.searchAt(position);
	if (value != NULL)
		cout << "��λ�õ�ֵΪ" << value << endl;
	else
		cout << "��λ�ò����ڣ�����" << endl;
}
//
void appendValue(ArrayList* alist) {
	int value;
	cout << "������Ҫ׷�ӵ�ֵ" << endl;
	cin >> value;
	bool isAppended = alist->append(value);
	if (isAppended == false)
		cout << "���ˣ��޷�׷�Ӱ�" << endl;
	else
		cout << "׷�ӳɹ�" << endl;

}

//
void insertValue(ArrayList* alist) {
	int value;
	cout << "������Ҫ�����ֵ" << endl;
	cin >> value;
	int position;
	cout << "������Ҫ�����λ��" << endl;
	cin >> position;

	if (alist->setCurrentPos(position) == false)
		cout << "��λ�ò����ڣ�" << endl;
	else {
		alist->setCurrentPos(position);
		if (alist->insert(value) == false)
			cout << "���ˣ��޷����밡" << endl;
		else
			cout << "����ɹ�" << endl;
	}
}

//
void deleteV(ArrayList* alist) {
	int value;
	cout << "������Ҫɾ����ֵ" << endl;
	cin >> value;
	while (alist->searchValue(value) != -1) {
		alist->deleteValue(value);
	}
	cout << "�Ѿ��Ҳ�����ֵ��" << endl;
}

//
void deleteP(ArrayList* alist) {
	int position;
	cout << "������Ҫɾ����λ��" << endl;
	cin >> position;
	if (alist->setCurrentPos(position) == false)
		cout << "��λ�ò����ڣ�" << endl;
	else {
		alist->setCurrentPos(position);
		alist->deleteAt();
		cout << "��ɾ����λ�õ�ֵ��" << endl;
	}
}
//
void clear(ArrayList* alist) {
	alist->clean();
	if (alist->clean() == false)
		cout << "���ʧ�ܣ�" << endl;
	else
		cout << "����ɹ���" << endl;
}

int main() {
	//��󳤶�
	int size;
	cout << "��������󳤶�" << endl;
	cin >> size;
	//����alist
	ArrayList alist = ArrayList(size);

	int maxSize = alist.getMaxSize();
	int listSize = alist.getListSize();
	int currentPos = alist.getCurrentPos();
	int* list = alist.getList();

	while (1) {
		//������Ϣ��ȡ
		maxSize = alist.getMaxSize();
		listSize = alist.getListSize();
		currentPos = alist.getCurrentPos();
		list = alist.getList();
		
		//����
		int op;
		cout << "������Ҫ���еĲ�������ţ�(1)��ʾ������Ϣ(2)�ı䵱ǰλ��(3)������ֵ(�����е�һ��)(4)����ȫ����ֵ(5)����ָ��λ�õ�ֵ(6)׷��ֵ(7)����ֵ(8)ɾ����ֵ(9)ɾ��ָ��λ�õ�ֵ(1~9����������)���" << endl;
		cin >> op;

		switch (op) {
		case 1:
			showBasicInfo(alist);
			break;
		case 2:
			changeCurrentPos(&alist);
			break;
		case 3:
			showPos(alist);
			break;
		case 4:
			showAllPos(alist);
			break;
		case 5:
			showValue(alist);
			break;
		case 6:
			appendValue(&alist);
			break;
		case 7:
			insertValue(&alist);
			break;
		case 8:
			deleteV(&alist);
			break;
		case 9:
			deleteP(&alist);
			break;
		default:
			clear(&alist);
			break;
		}

	}
}
