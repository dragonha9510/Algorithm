#pragma once
#include "Useful.h"

typedef struct queueNode
{
	queueNode(int num)
	{
		data = num;
		front = nullptr;
		back = nullptr;
	}

	int data;
	queueNode* front;
	queueNode* back;
}NODE;

typedef struct midQueue
{
	midQueue() 
	{
		node = nullptr;
		size = 0;
	}
	~midQueue()
	{
		NODE* curNode = node;
		NODE* deleteNODE = nullptr;
		while (curNode != nullptr)
		{
			deleteNODE = curNode;
			curNode = curNode->back;
		}

		while (deleteNODE != nullptr)
		{
			curNode = deleteNODE->front;
			delete deleteNODE;
			deleteNODE = curNode;
		}
	}

	NODE* node;
	int size = 0;

	void PUSH(int num)
	{
		++size;

		if (node == nullptr)
		{
			node = new NODE(num);

			return;
		}

		if (node->data >= num)
		{
			NODE* temp = new NODE(num);

			temp->back = node;
			node->front = temp;
			node = temp;

			return;
		}

		NODE* curNode = node;
		NODE* temp = node;
		NODE* newNode = new NODE(num);

		while (curNode != nullptr)
		{
			if (curNode->data >= num)
			{
				newNode->front = curNode->front;
				newNode->back = curNode;
				curNode->front = newNode;
				temp->back = newNode;

				return;
			}

			temp = curNode;
			curNode = curNode->back;
		}

		temp->back = newNode;
		newNode->front = temp;
	}

	void POP()
	{
		int midIdx = ((size + size % 2) / 2) - 1;
		--size;
		NODE* curNode = node;
		for (int i = 0; i < midIdx; ++i)
			curNode = curNode->back;

		if (curNode == node)
		{
			delete node;
			node = nullptr;
			return;
		}

		NODE* front = curNode->front;
		NODE* back = curNode->back;

		if(front != nullptr)
			front->back = back;
		if(back != nullptr)
			back->front = front;

		delete curNode;
		curNode = nullptr;
	}

	int SIZE()
	{
		return size;
	}

	string CHECK()
	{
		if (size == 0)
			return "NO ITEM";

		int midIdx = ((size + size % 2) / 2) - 1;
		NODE* curNode = node;
		for (int i = 0; i < midIdx; ++i)
			curNode = curNode->back;

		return IntToString(curNode->data);
	}

}Queue, QUEUE;

vector<string> solution()
{
	midQueue que;
	vector<string> answer;

	int num = 0;
	string order = "";
	cin >> num;

	while (num-- != 0)
	{
		cin >> order;

		if (order == "POP")
			que.POP();
		else if (order == "SIZE")
		{
			answer.push_back(IntToString(que.SIZE()));
			continue;
		}
		else
		{
			int data = 0;
			cin >> data;

			que.PUSH(data);
		}

		answer.push_back(que.CHECK());
	}

	return answer;
}