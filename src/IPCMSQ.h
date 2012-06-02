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
#ifndef LWPR_IPCMSQ_H__
#define LWPR_IPCMSQ_H__
#include "LWPRType.h"
#include "Var.h"
#include "Buffer.h"
#include "LWPRType.h"
#include "Exception.h"
//#include "IPCMsgBuffer.h"

namespace LWPR
{
	typedef enum ipcmsq_ret_type_e
	{
		IPCMSQ_RET_FAILED = -1,		// ipc msq����
		IPCMSQ_RET_OK = 0,			// ipc msq�ɹ�
		IPCMSQ_RET_MSG_FULL = 1,	// ipc msq���Ͷ�����Ϣ��
		IPCMSQ_RET_NO_MSG = 2,		// ipc msq���ն�������Ϣ
		IPCMSQ_RET_EINTR = 3,		// ipc msqϵͳ���ñ��ź��ж�
	} IPCMSQ_RET_TYPE_E;

	const int MSG_RCV_SIZE_DEFAULT = 2048;

	class IPCMSQ
	{
	public:
		/**
		 * ����һ����Ϣ����
		 */
		static IPCID_T Create(const IPCKEY_T key,
		                      IPC_CREATE_TYPE_E type = LWPR::CREATE_NEW_ONE,
		                      int perm = IPC_DEFAULT_PERM);

		/**
		 * ����һ����Ϣ����(IPC_PRIVATE)
		 */
		static IPCID_T Create();

		/**
		 * ����IPC Key������Ӧ��IPC ID
		 */
		static IPCID_T GetID(const IPCKEY_T key);

		/**
		 * ����һ����Ϣ����
		 */
		static void Destroy(const IPCID_T id);

		/**
		 * ������з���һ����Ϣ��Ĭ��Ϊ������ʽ
		 */
		static void Send(const IPCID_T id, const Buffer& msg, bool blocked = true);

		/**
		 * ������з���һ����Ϣ��Ĭ��Ϊ������ʽ
		 */
		static IPCMSQ_RET_TYPE_E SendMsg(IPCID_T id, const char*buf, int length, bool blocked = true);

		/**
		 * �Ӷ����н���һ����Ϣ����ɾ�������е�������Ϣ��Ĭ��Ϊ����ģʽ
		 */
		static LWPR::Buffer_ptr Receive(const IPCID_T id, long type = 0, bool blocked = true);

		/**
		 * �Ӷ����н���һ����Ϣ����ɾ�������е�������Ϣ��Ĭ��Ϊ����ģʽ
		 */
		static IPCMSQ_RET_TYPE_E ReceiveMsg(IPCID_T id, Buffer& msg, bool blocked = true);

	};

	DEFINE_EXCEPTION(LWPR_IPC_MSQ_GET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_SND_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_RCV_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_CTL_ERR);

	DEFINE_EXCEPTION(LWPR_IPC_MSQ_EXIST);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_NOT_EXIST);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_RCV_NOMSG);
	DEFINE_EXCEPTION(LWPR_IPC_MSQ_SND_MSQFULL);
};

#endif // end of LWPR_IPCMSQ_H__
