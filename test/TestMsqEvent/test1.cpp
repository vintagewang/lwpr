/*
 * $Id: test1.cpp 1 2010-09-30 14:35:38Z vintage $
 */
/*
 * ����LWPR::EventMsqDispatch���Ƿ�����������
 * �䵱Server
 */
#include "EventMsqDispatch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class Receiver : public LWPR::EventMsqHandler
{
public:
	/**
	 * ���캯��
	 */
	Receiver() {}

	/**
	 * ��������
	 */
	~Receiver() {}

	/**
	 * �����յ�����Ϣ��������
	 */
	void DoReceiveMsqData(LWPR::Buffer& msg)
	{
		printf("Receiver::DoReceiveMsqData -------------------------------------------------------------\n");

		LWPR::INT32 nMsgType = 0;
		memcpy(&nMsgType, msg.Inout(), sizeof(nMsgType));
		printf("Receiver::DoReceiveMsqData Current thread id [%u] nMsgType [%d] nMsgLength [%d] [%s]\n",
		       LWPR::Thread::GetCurrentThreadId(),
		       nMsgType,
			   msg.Size(),
		       msg.Inout() + sizeof(LWPR::INT32));
	}
};

int main(int argc, char *argv[])
{
	try
	{
		LWPR::EVENT_MSQ_OPTION_T opt;
		opt.nMsqId = LWPR::IPCMSQ::Create();
		opt.nThreadCount = 50;
		opt.pHandler = new Receiver();

		printf("opt.nMsqId = %d\n", opt.nMsqId);

		LWPR::EventMsqDispatch disp(opt);

		disp.Start();

		disp.Reap();
	}
	catch(const LWPR::Exception& e)
	{
		fprintf(stderr, "%s\n", e.what());
	}

	return 0;
}
