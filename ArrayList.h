#pragma once
class ArrayList
{
public:
	//创建初始list
	ArrayList(int size);
	
	//设定当前位置
	//如果设定的位置大于最大长度，就返回-1
	bool setCurrentPos(int position);

	//获取基本信息
	int getMaxSize();
	int getListSize();
	int getCurrentPos();
	int* getList();

	//给定一个值value，返回该值在ArrayList的第一个位置
	//如果ArrayList没有该值，就返回-1
	int searchValue(int value);

	//给定一个值value，返回在ArrayList中该值的所有位置
	//如果ArrayList没有该值，返回的位置的数组(大小为listSize)中均为-1
	int* searchAllValue(int value);

	//给定一个位置(从0开始)，返回该位置在ArrayList的值
	int searchAt(int location);

	//在ArrayList尾部追加给定的值
	bool append(int value);

	//通过调整当前位置currentPos，插入给定的值
	bool insert(int insertvalue);
	
	//给定一个值，删除第一个该值
	bool deleteValue(int value);

	//通过调整当前位置CurrentPos，进行数据删除
	bool deleteAt();

	/*//给定一个值，对第一个该值替换成指定值
	bool modifyValue(int value, int newvalue);

	//通过调整当前位置CurrentPos，进行数据替换
	bool modifyAt(int newvalue);

	//根据元素从小到大排序
	bool sortinascendingorder();

	//根据元素从大到小排序
	bool sortindescendingorder();
	*/
	//清零
	bool clean();
	
private:
	int maxSize;
	int listSize;
	int currentPos;
	int* list;
	//int* Pos = (int*)malloc(sizeof(int)*MaxSize);//下标
};