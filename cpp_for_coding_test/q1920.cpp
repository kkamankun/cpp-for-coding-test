#include <iostream>
#define MAX_HASH 4294967
#pragma warning(disable:4996)

using namespace std;

typedef struct Node
{
	int id;
	Node* hashNext;
}Node;

Node* hashTable[MAX_HASH];  // 해시테이블 생성
// 키값 생성
int HASH_KEY(int data) {
	int key;
	if (data < 0) {
		key = data / 1000;
		key *= -1;
	}
	else {
		key = data / 1000;
		key *= 2;
	}
	return key;
}

void AddHashData(int key, Node* node)
{
	int hash_key = HASH_KEY(key);
	if (hashTable[hash_key] == NULL)
	{
		hashTable[hash_key] = node;
	}
	else
	{
		node->hashNext = hashTable[hash_key];
		hashTable[hash_key] = node;
	}
}

int FindHashData(int id)
{
	int hash_key = HASH_KEY(id);
	if (hashTable[hash_key] == NULL)
		return 0;

	if (hashTable[hash_key]->id == id)
	{
		return 1;
	}
	else
	{
		Node* node = hashTable[hash_key];
		while (node->hashNext)
		{
			if (node->hashNext->id == id)
			{
				return 1;
			}
			node = node->hashNext;
		}
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int nInput;  // -2^31 ~ 2^31
		cin >> nInput;
		Node* node = new Node();
		node->id = nInput;
		node->hashNext = NULL;
		AddHashData(node->id, node);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int mInput;
		scanf("%d", &mInput);
		printf("%d \n", FindHashData(mInput));
	}
	return 0;
}