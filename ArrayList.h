#pragma once
class ArrayList
{
public:
	//������ʼlist
	ArrayList(int size);
	
	//�趨��ǰλ��
	//����趨��λ�ô�����󳤶ȣ��ͷ���-1
	bool setCurrentPos(int position);

	//��ȡ������Ϣ
	int getMaxSize();
	int getListSize();
	int getCurrentPos();
	int* getList();

	//����һ��ֵvalue�����ظ�ֵ��ArrayList�ĵ�һ��λ��
	//���ArrayListû�и�ֵ���ͷ���-1
	int searchValue(int value);

	//����һ��ֵvalue��������ArrayList�и�ֵ������λ��
	//���ArrayListû�и�ֵ�����ص�λ�õ�����(��СΪlistSize)�о�Ϊ-1
	int* searchAllValue(int value);

	//����һ��λ��(��0��ʼ)�����ظ�λ����ArrayList��ֵ
	int searchAt(int location);

	//��ArrayListβ��׷�Ӹ�����ֵ
	bool append(int value);

	//ͨ��������ǰλ��currentPos�����������ֵ
	bool insert(int insertvalue);
	
	//����һ��ֵ��ɾ����һ����ֵ
	bool deleteValue(int value);

	//ͨ��������ǰλ��CurrentPos����������ɾ��
	bool deleteAt();

	/*//����һ��ֵ���Ե�һ����ֵ�滻��ָ��ֵ
	bool modifyValue(int value, int newvalue);

	//ͨ��������ǰλ��CurrentPos�����������滻
	bool modifyAt(int newvalue);

	//����Ԫ�ش�С��������
	bool sortinascendingorder();

	//����Ԫ�شӴ�С����
	bool sortindescendingorder();
	*/
	//����
	bool clean();
	
private:
	int maxSize;
	int listSize;
	int currentPos;
	int* list;
	//int* Pos = (int*)malloc(sizeof(int)*MaxSize);//�±�
};