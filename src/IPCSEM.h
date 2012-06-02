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
#ifndef LWPR_IPCSEM_H__
#define LWPR_IPCSEM_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{
	/**
	 * ���ļ����ᵽ���ź�������Ϊ��д��������
	 * ���������ͣ����������д��
	 */
	class IPCSEM
	{
	public:
		/**
		 * ����һ���ź�������ֵ�ź���
		 * iswrlock��־�Ƿ��Ƕ�д��������Ƕ�д�����������ź�����ֵΪSHRT_MAX
		 * ����ʱ��1��д��ʱ����SHRT_MAX
		 */
		static IPCID_T Create(const IPCKEY_T key,
		                      bool iswrlock = false,
		                      IPC_CREATE_TYPE_E type = LWPR::CREATE_NEW_ONE,
		                      int perm = IPC_DEFAULT_PERM);

		/**
		 * ����IPC Key������Ӧ��IPC ID
		 */
		static IPCID_T GetID(const IPCKEY_T key);

		/**
		 * ����һ���ź�������
		 */
		static void Destroy(const IPCID_T id);

		/**
		 * �����ź���
		 */
		static void Lock(const IPCID_T id, bool blocked = true, bool iswrlock = false);

		/**
		 * �����ź���
		 */
		static void Unlock(const IPCID_T id, bool iswrlock = false);

		/**
		 * �ж��ź����Ƿ��ڼ���״̬
		 */
		static bool IsLocked(const IPCID_T id);
	};

	DEFINE_EXCEPTION(LWPR_IPC_SEM_GET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_RESET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_LOCK_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_UNLOCK_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_CTL_ERR);

	DEFINE_EXCEPTION(LWPR_IPC_SEM_LOCKED_BEFORE);
	DEFINE_EXCEPTION(LWPR_IPC_SEM_NOT_EXIST);
};

#endif // end of LWPR_IPCSEM_H__
