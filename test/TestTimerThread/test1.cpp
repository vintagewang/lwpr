/*
 * $Id: test1.cpp 49 2010-10-17 12:02:31Z vintage $
 */
/*
 * ����LWPR::TimerThread���Ƿ�������ִ�ж�ʱ
 */
#include "TimerThread.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class MyReq : public LWPR::WorkRequest
{
public:
	void DoWork()
	{
		cout << "Oh I am working" << endl;
	}
};

/**
 * ������
 */
int main(int argc, char *argv[])
{
	LWPR::TimerThread t;

	MyReq* p =  new MyReq;

	// �������
	t.AddTimerRequest(p, 3);

	sleep(1);

	t.AddTimerRequest(p, 6);

	sleep(1000000);
	return 0;
}
