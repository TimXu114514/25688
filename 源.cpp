/*开发日志：
做交互便于自测
一、List ArrayList LinkedList(数组和指针）
	1、数组；大小定a[MaxSize]；元素为int型
	2、每次运行最后都要输出list（繁琐）/要求输出list时才输出 print_r 创建test目录进行运行测试
二、Search
	1、Search_1:检索对应元素，输出全部下标“给定元素x，在list上查找x，并输出pos[]”*【检索到->输出 printf("%d",a[i]) ->继续检索】/
								  【检索全部->输出】
								   两种方法都要记录全部符合要求的元素的下标，便于增删移；
								   都需要“如何自适应产生对应数量的整型进行赋值”或寻找其他方法
							 *!*(1)创建另一个同大小数组作为下标组记录下标，完成一次操作后通过Clean清除
	2、Search_2:检索对应下标->输出元素（int Search atl）“给定pos，在list上获取元素”
	3、不论是1还是2，本质上都是通过下标进行操作
三、append/insert
	1、检验是否溢出ListSize！= MaxSize
	2、不指定插入位置append/指定插入位置insert 输入下标+元素（下标对应元素）
	3、不指定：CurrentPos后插入元素
	   指定：a[ListSize+1]=a[ListSize]
	->4、多个元素同时add的方法
							检测add元素个数y,对应下标，运用下标组pos[]
							元素组分阶段
四、Delete
	1、同add操作
	2、但Delete不仅仅只有“下标对应元素”，还有“元素对应下标”，运用Search_1记录的下标组进行操作
五、Modify/Swap
	1、替换下标对应元素
	2、替换全部指定元素 Search_1根据下标更改
六、排序
	1、数组排序，现成的代码
七、Remove
	1、清零
		   1)全部元素替换为0
	2、既然list一开始就创建了新数组，Clean还有什么作用？节省内存
*/
#include <iostream>
#include <math.h>
#include "stdlib.h"
#include "ArrayList.h"
#include <stdio.h>


using namespace std;

//基础信息展示
void showBasicInfo(ArrayList alist) {
	int maxSize = alist.getMaxSize();
	int listSize = alist.getListSize();
	int currentPos = alist.getCurrentPos();
	int* list = alist.getList();
	//获取maxSize
	cout << "最大长度为" << maxSize << endl;
	//获取listSize
	cout << "数组长度为" << listSize << endl;
	//获取currentPos
	cout << "当前位置为" << currentPos << endl;
	//获取当前alist		
	for (int i = 0; i < listSize - 1; i++) {
		cout << list[i] << " ";
	}
	cout << list[listSize - 1] << endl;
}

//检索所有要求值
void showAllPos(ArrayList alist) {
	int value;
	cout << "请输入要检索的值(将会显示所有该值的位置，从0开始)" << endl;
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
	cout << "请输入要前往的位置" << endl;
	cin >> position;
	if (alist->setCurrentPos(position) == false) {
		cout << "要求的位置不存在！！！" << endl;
	}
	else {
		cout << "位置修改成功。。。" << endl;
	}
}
//
void showPos(ArrayList alist) {
	int value;
	cout << "请输入要检索的值(将显示第一个该值的位置)" << endl;
	cin >> value;
	int position = alist.searchValue(value);
	if (position != -1)
		cout << "第一个该值的位置为" << position << endl;
}
//
void showValue(ArrayList alist) {
	int position;
	cout << "请输入要检索位置" << endl;
	cin >> position;
	int value = alist.searchAt(position);
	if (value != NULL)
		cout << "该位置的值为" << value << endl;
	else
		cout << "该位置不存在！！！" << endl;
}
//
void appendValue(ArrayList* alist) {
	int value;
	cout << "请输入要追加的值" << endl;
	cin >> value;
	bool isAppended = alist->append(value);
	if (isAppended == false)
		cout << "满了！无法追加啊" << endl;
	else
		cout << "追加成功" << endl;

}

//
void insertValue(ArrayList* alist) {
	int value;
	cout << "请输入要插入的值" << endl;
	cin >> value;
	int position;
	cout << "请输入要插入的位置" << endl;
	cin >> position;

	if (alist->setCurrentPos(position) == false)
		cout << "该位置不存在！" << endl;
	else {
		alist->setCurrentPos(position);
		if (alist->insert(value) == false)
			cout << "满了！无法插入啊" << endl;
		else
			cout << "插入成功" << endl;
	}
}

//
void deleteV(ArrayList* alist) {
	int value;
	cout << "请输入要删除的值" << endl;
	cin >> value;
	while (alist->searchValue(value) != -1) {
		alist->deleteValue(value);
	}
	cout << "已经找不到该值了" << endl;
}

//
void deleteP(ArrayList* alist) {
	int position;
	cout << "请输入要删除的位置" << endl;
	cin >> position;
	if (alist->setCurrentPos(position) == false)
		cout << "该位置不存在！" << endl;
	else {
		alist->setCurrentPos(position);
		alist->deleteAt();
		cout << "已删除该位置的值！" << endl;
	}
}
//
void clear(ArrayList* alist) {
	alist->clean();
	if (alist->clean() == false)
		cout << "清除失败！" << endl;
	else
		cout << "清除成功！" << endl;
}

int main() {
	//最大长度
	int size;
	cout << "请输入最大长度" << endl;
	cin >> size;
	//创建alist
	ArrayList alist = ArrayList(size);

	int maxSize = alist.getMaxSize();
	int listSize = alist.getListSize();
	int currentPos = alist.getCurrentPos();
	int* list = alist.getList();

	while (1) {
		//基本信息获取
		maxSize = alist.getMaxSize();
		listSize = alist.getListSize();
		currentPos = alist.getCurrentPos();
		list = alist.getList();
		
		//操作
		int op;
		cout << "请输入要进行的操作的序号：(1)显示基本信息(2)改变当前位置(3)检索定值(数组中第一个)(4)检索全部定值(5)检索指定位置的值(6)追加值(7)插入值(8)删除定值(9)删除指定位置的值(1~9外任意数字)清空" << endl;
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
