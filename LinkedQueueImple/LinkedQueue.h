template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType> *next;
};

template<class ItemType>
class QueueType
{
public:
	QueueType(void);
	void MakeEmpty();
	bool IsEmpty();
	void Enqueueu(ItemType Item);
	void Dequeue();
	int size();
	ItemType RetrieveItem(int i);
	~QueueType(void);
private:
	NodeType<ItemType> *qRear;
	NodeType<ItemType> *qFront;
	int _size;
};


template<class ItemType> int QueueType<ItemType>::size()
{
	return _size;
}
template<class ItemType> QueueType<ItemType>::QueueType(void)
{
	qFront = nullptr;
	qRear = nullptr;
	_size = 0;
}

template<class ItemType> bool QueueType<ItemType>::IsEmpty()
{
	return (qFront == nullptr && qRear == nullptr);
}

template<class ItemType> void QueueType<ItemType>::MakeEmpty()
{
	qFront = nullptr;
	qRear = nullptr;
	_size = 0;
}


template<class ItemType> void QueueType<ItemType>::Enqueueu(ItemType newItem)
{
	NodeType<ItemType> *location;
	location = new NodeType<ItemType>;
	location->info = newItem;
	location->next = nullptr;
	if(qRear == nullptr)
	{
		qFront = location;
	}
	else
	{
		qRear->next = location;
	}
	qRear = location;
	_size++;
}

template<class ItemType> void QueueType<ItemType>::Dequeue()
{
	if(IsEmpty())
	{
		throw("Pop On Empty Stack");
	}
	NodeType<ItemType> *tempPtr;
	tempPtr = new NodeType<ItemType>;
	tempPtr = qFront;
	qFront= qFront->next;
	delete tempPtr;
	_size--;
}

template<class ItemType>ItemType QueueType<ItemType>::RetrieveItem(int index)
{
	if(index>_size)
	{
		throw("index exceeds stack size.");
	}
	NodeType<ItemType> *tempPtr;
	tempPtr = qFront;
	for(int i =0;i<index;i++)
	{
		tempPtr=tempPtr->next;
	}
	return tempPtr->info;
}

template<class ItemType> QueueType<ItemType>::DeleteHelper(TreeNode<ItemType> **node)
{
	if((*node) != nullptr)
	{
		DeleteHelper((*node)->right);
		DeleteHelper((*node)->left);
		delete (*node);
		(*node) = nullptr;
	}
}

template<class ItemType> QueueType<ItemType>::~QueueType(void)
{
	DeleteHelper(*root);
}
