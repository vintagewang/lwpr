/**
 * Copyright 2012 Wangxr, vintage.wang@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "EventMsqDispatch.h"
#include <assert.h>

namespace LWPR
{

	//////////////////////////////////////////////////////////////////////////
	event_msq_option::event_msq_option()
		: nMsqId(-1),
		  nThreadCount(10),
		  pHandler(NULL)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	EventMsqDispatch::EventMsqDispatch(const EVENT_MSQ_OPTION_T& opt)
		: m_EventMsqOption(opt),
		  m_bContinue(true)
	{
		assert(m_EventMsqOption.nMsqId >= 0);
		assert(m_EventMsqOption.nThreadCount > 0);
		assert(m_EventMsqOption.pHandler != NULL);
	}

	EventMsqDispatch::~EventMsqDispatch()
	{
	}

	void EventMsqDispatch::Start()
	{
		// �����̶߳���
		for(int i = 0; i < m_EventMsqOption.nThreadCount; i++)
		{
			EventMsqThreadImpl* pThread = new EventMsqThreadImpl(*this);
			m_Threads.push_back(pThread);
		}

		// �����߳�
		for(size_t j = 0; j < m_Threads.size(); j++)
		{
			m_Threads[j]->Start();
		}
	}

	void EventMsqDispatch::Halt()
	{
		m_bContinue = false;
		EVENT_MSQ_MAGIC_MSG_T msg;
		IPCMSQ::SendMsg(m_EventMsqOption.nMsqId, (const char*)&msg, sizeof(msg));
	}

	void EventMsqDispatch::Reap()
	{
		// �����߳�
		for(int i = 0; i < m_EventMsqOption.nThreadCount; i++)
		{
			m_Threads[i]->Join();
			delete m_Threads[i];
		}
	}

	//////////////////////////////////////////////////////////////////////////
	EventMsqThreadImpl::EventMsqThreadImpl(EventMsqDispatch& dispatch)
		: m_EventMsqDispatch(dispatch)
	{
	}

	EventMsqThreadImpl::~EventMsqThreadImpl()
	{
	}

	void EventMsqThreadImpl::Run()
	{
		while(m_EventMsqDispatch.m_bContinue)
		{
			try
			{
				Buffer bufMsg;
				memset(bufMsg.Inout(), 0, bufMsg.Capacity());
				IPCMSQ_RET_TYPE_E nRetMsq = IPCMSQ_RET_OK;

				{
					// ��������ȡ��Ϣ���У������ٽ�����
					// ����֤��linuxƽ̨����Ҫ��������������ƽ̨�����߳�ʵ�ֻ��Ƶ������ԣ����ܱ�֤��Ϣ����ʱԭ�Ӳ���
					Synchronized syn(m_EventMsqDispatch.m_Mutex);

					if(!m_EventMsqDispatch.m_bContinue)
					{
						return;
					}
					else
					{
						nRetMsq = IPCMSQ::ReceiveMsg(m_EventMsqDispatch.m_EventMsqOption.nMsqId, bufMsg);
					}
				}

				if(nRetMsq == IPCMSQ_RET_OK)
				{
					// ����յ�����Ϣ�Ƿ��ǹر���Ϣ
					EVENT_MSQ_MAGIC_MSG_T msg;
					if(bufMsg.Size() == sizeof(msg)
					   && !memcmp(bufMsg.Inout(), &msg, sizeof(msg)))
					{
						return;
					}

					try
					{
						m_EventMsqDispatch.m_EventMsqOption.pHandler->DoReceiveMsqData(bufMsg);
					}
					catch(...)
					{
					}
				}
			}
			catch(const LWPR::Exception& e)
			{
				fprintf(stderr, "%s\n", e.what());
			}
		}
	}
};
