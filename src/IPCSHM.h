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
#ifndef LWPR_IPCSHM_H__
#define LWPR_IPCSHM_H__
#include "LWPRType.h"
#include "Exception.h"

namespace LWPR
{
	class IPCSHM
	{
	public:
		/**
		 * ����һ�������ڴ����
		 */
		static IPCID_T Create(const IPCKEY_T key,
		                      int size,
		                      IPC_CREATE_TYPE_E type = LWPR::CREATE_NEW_ONE,
		                      int perm = IPC_DEFAULT_PERM);

		/**
		 * ����IPC Key������Ӧ��IPC ID
		 */
		static IPCID_T GetID(const IPCKEY_T key);

		/**
		 * ����һ�������ڴ����
		 */
		static void Destroy(const IPCID_T id);

		/**
		 * ���ں˽������ڴ��ַ�������������
		 */
		static void* Mount(const IPCID_T id, PERMISSION_E prms = LWPR::RW);

		/**
		 * ж�ر����̹��صĽ��̵�ַ
		 */
		static void Unmount(void *addr);

		/**
		 * ����MagicCode��ȡϵͳ�пɷ��ʵĹ����ڴ�ID
		 */
		static int FetchSHMID(IPCIDList& ids, LWPR::UINT32 magic_code);

	private:
	};

	DEFINE_EXCEPTION(LWPR_IPC_SHM_GET_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SIZE_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SHMAT_ERR);
	DEFINE_EXCEPTION(LWPR_IPC_SHM_SHMDT_ERR);

	DEFINE_EXCEPTION(LWPR_IPC_SHM_NOT_EXIST);
};

#endif // end of LWPR_IPCSHM_H__
