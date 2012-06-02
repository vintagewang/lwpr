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
#ifndef LWPR_SIMPLE_PROCESS_POOL_H__
#define LWPR_SIMPLE_PROCESS_POOL_H__
#include "LWPRType.h"
#include <list>

namespace LWPR
{
	/**
	 * �򵥽��̳ع��ܣ��ܴ����̶���Ŀ�Ľ��̣���ά�������������н��������˳���������
	 */
	class SimpleProcessPool
	{
	public:
		/**
		 * ���캯��
		 */
		SimpleProcessPool();

		/**
		 * ��������
		 */
		virtual ~SimpleProcessPool();

		/**
		 * ����������������
		 */
		void SetProcessNum(int process_num);

		/**
		 * ��ʼ����
		 */
		void Run(int argc, char** argv);

		/**
		 * �ӽ���ִ����
		 */
		virtual int DoChildWork(int argc, char** argv) = 0;

	private:
		int m_nProcessNum;
		std::list < int > m_ProcessList;
	};
};

#endif // end of LWPR_SIMPLE_PROCESS_POOL_H__
