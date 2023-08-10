#include <stdio.h>
#include <iostream>
#include <string.h>
#include "ArrayList.h"
#include <stdlib.h>

using namespace std;



ArrayList::ArrayList(int size)
{
	//����������󳤶�
	this->maxSize = size;

	//�����鳤�ȳ�ʼ��Ϊ0
	this->listSize = 0;

	//��ǰλ�ó�ʼ��Ϊ0
	this->currentPos = 0;

	//����list����
	this->list = (int*)malloc(sizeof(int)*size);//����

}

bool ArrayList::setCurrentPos(int position)
{
	//��ǰλ��δ����list����
	if (position < listSize) {
		currentPos = position;
		return true;
	}
	return false;
}

int ArrayList::getMaxSize()
{
	return maxSize;
}

int ArrayList::getListSize()
{
	return listSize;
}

int ArrayList::getCurrentPos()
{
	return currentPos;
}

int * ArrayList::getList()
{
	return list;
}



int ArrayList::searchValue(int value)
{
	//ArrayListΪ��
	if(listSize == 0) 
		return -1;
	
	//forѭ������
	for(int i = 0; i < listSize; i++)
		if(list[i] == value)
			return i;
	
	return -1;
}

int* ArrayList::searchAllValue(int value)
{
	//ArrayListΪ��
	if(listSize == 0) 
		return NULL;
	
	int* pos = new int[listSize];
	for (int i = 0; i < listSize; i++)
		pos[i] = -1; //��ʼ��pos����

	int j = 0;
	for(int i = 0; i < listSize; i++)
		if(list[i] == value)
			pos[j++] = i;
	return pos;
}

int ArrayList::searchAt(int location)
{
	//ArrayListΪ��
	if (listSize == 0)
		return NULL;

	if (location >= listSize)
		return NULL;

	return list[location];
}

bool ArrayList::append(int value)
{
	//ArrayList ����
	if (listSize == maxSize)
		return false;

	//׷�Ӳ���
	list[listSize] = value;
	listSize++;
	currentPos = listSize;
	
	return true;
}

bool ArrayList::insert(int insertvalue)
{
	//ArrayList ����
	if (listSize == maxSize)
		return false;

	//��ָ��λ�ò���ֵ
	for (int i = listSize - 1; i >= currentPos; i--)
		list[i + 1] = list[i];
	list[currentPos] = insertvalue;
	listSize++;
	return true;
}

bool ArrayList::deleteValue(int value)
{
	int i = searchValue(value);
	for (; i < listSize - 1; i++)
		list[i] = list[i + 1];
	listSize--;
	return true;
}

bool ArrayList::deleteAt()
{
	for (int i = currentPos; i < listSize - 1; i++)
		list[i] = list[i + 1];
	listSize--;
	return true;
}

/*bool ArrayList::modifyValue(int value, int newvalue)
{
	//ArrayListΪ��
	if (listSize == 0)
		return false;

	return false;
}

bool ArrayList::modifyAt(int newvalue)
{
	return false;
}

bool ArrayList::sortinascendingorder()
{
	return false;
}

bool ArrayList::sortindescendingorder()
{
	return false;
}
*/
bool ArrayList::clean()
{
	void free(int* list);
	void free(int* Pos);
	return true;
}



