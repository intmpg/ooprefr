#include "stdafx.h"
#include "Perform.h"

using namespace std;

void ReadVector(vf &a)
{
	float f;
	while (scanf("%f", &f) == 1)
	{
		a.push_back(f);
	}
}

void OutputVector(const vf &a)
{
	for_each(a.begin(), a.end(), [](float n){printf("%.3f ", n); });
}

int _tmain(int argc, _TCHAR* argv[])
{
	vf v;
	ReadVector(v);
	Perform(v);
	OutputVector(v);
	v.clear();
	return 0;
}

