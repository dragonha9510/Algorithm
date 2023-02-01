#pragma once
#include "Useful.h"

typedef struct mynode
{
	bool visit;
	bool end;
	vector<mynode> node;
}NODE;

typedef struct Trie
{
	vector<NODE> node;
	Trie()
	{
		for (int i = 0; i < 9; ++i)
			node.push_back(NODE());
	}

	bool insert(string n)
	{
		vector<NODE>* check = &node;

		for (size_t i = 0; i < n.size(); ++i)
		{
			int idx = (n[i] - '0') - 1;

			if ((*check)[idx].visit != true)
			{
				(*check)[idx].visit = true;

				if (i == n.size() - 1)
				{
					(*check)[idx].end = true;
					return false;
				}
			}

			else if ((*check)[idx].end == true)
				return true;

			if (i == n.size() - 1)
				return true;

			check = &((*check)[idx].node);

			if (check->size() == 0)
			{
				for (int i = 0; i < 9; ++i)
					check->push_back(NODE());
			}
		}

		return false;
	}
}TRIE;

bool solution03(vector<string> phone_book)
{
	Trie trie;

	for (const auto& p : phone_book)
	{
		if (trie.insert(p))
			return false;
	}

	return true;
}