#include <stdio.h>
#include <iostream>
#include <string.h>
#include "ArrayList.h"
#include <stdlib.h>

using namespace std;



ArrayList::ArrayList(int size)
{
	//设置数组最大长度
	this->maxSize = size;

	//将数组长度初始化为0
	this->listSize = 0;

	//当前位置初始化为0
	this->currentPos = 0;

	//创建list数组
	this->list = (int*)malloc(sizeof(int)*size);//数组

}

bool ArrayList::setCurrentPos(int position)
{
	//当前位置未超出list长度
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
	//ArrayList为空
	if(listSize == 0) 
		return -1;
	
	//for循环检索
	for(int i = 0; i < listSize; i++)
		if(list[i] == value)
			return i;
	
	return -1;
}

int* ArrayList::searchAllValue(int value)
{
	//ArrayList为空
	if(listSize == 0) 
		return NULL;
	
	int* pos = new int[listSize];
	for (int i = 0; i < listSize; i++)
		pos[i] = -1; //初始化pos数组

	int j = 0;
	for(int i = 0; i < listSize; i++)
		if(list[i] == value)
			pos[j++] = i;
	return pos;
}

int ArrayList::searchAt(int location)
{
	//ArrayList为空
	if (listSize == 0)
		return NULL;

	if (location >= listSize)
		return NULL;

	return list[location];
}

bool ArrayList::append(int value)
{
	//ArrayList 满？
	if (listSize == maxSize)
		return false;

	//追加插入
	list[listSize] = value;
	listSize++;
	currentPos = listSize;
	
	return true;
}

bool ArrayList::insert(int insertvalue)
{
	//ArrayList 满？
	if (listSize == maxSize)
		return false;

	//在指定位置插入值
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
	//ArrayList为空
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



