#include <vector>
using namespace std;

long long sum(vector<int> &a) 
{
	long long llRes = 0;
	size_t uiSize = a.size();

	for (size_t i = 0; i < uiSize; ++i)
	{
		llRes += (long long)a[i];
	}

	return llRes;
}
