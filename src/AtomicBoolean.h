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
#ifndef LWPR_ATOMIC_BOOLEAN_H__
#define LWPR_ATOMIC_BOOLEAN_H__
#include "LWPRType.h"

namespace LWPR
{
	class AtomicBoolean
	{
	public:
		/**
		 * ���캯��
		 */
		AtomicBoolean(bool initialValue = false);

		/**
		 * �����ǰֵ == Ԥ��ֵ������ԭ�ӷ�ʽ����ֵ����Ϊ�����ĸ���ֵ
		 * @return ����ɹ����򷵻� true������ False ָʾʵ��ֵ��Ԥ��ֵ�����
		 */
		bool CompareAndSet(bool expect, bool update);

		/**
		 * ���ص�ǰֵ
		 */
		bool Get() const;

		/**
		 * ����Ϊ����ֵ����������ǰ��ֵ
		 * @return ��ǰ��ֵ
		 */
		bool GetAndSet(bool newValue);

		/**
		 * ������������Ϊ����ֵ��
		 */
		void Set(bool newValue);

		/**
		 * ����ת��������
		 */
		operator bool () const;

	private:
		volatile int m_nValue;
	};
};

#endif // end of LWPR_ATOMIC_BOOLEAN_H__
