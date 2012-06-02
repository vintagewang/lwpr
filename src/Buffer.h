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
#ifndef LWPR_BUFFER_H__
#define LWPR_BUFFER_H__

#include "LWPRType.h"
#include "Object.h"
#include "Var.h"
#include "Exception.h"

namespace LWPR
{
	class StringBuffer;

	const int BUFFER_DEFAULT_CAPACITY = 128;

	class Buffer : public LWPR::Object
	{
	public:

		/**
		 * ���캯��
		 */
		Buffer(int capacity = BUFFER_DEFAULT_CAPACITY);

		/**
		 * �������캯��
		 */
		Buffer(const Buffer& rhs);

		/**
		 * ��ֵ����������
		 */
		Buffer& operator= (const Buffer& rhs);

		/**
		 * ��������
		 */
		virtual ~Buffer();

		/**
		 * ���������ݳ�ʼ��Ϊ0
		 */
		void Reset();

		/**
		 * �����ڴ���׵�ַ���������߶�д
		 */
		virtual char *Inout() const;

		/**
		 * ���ط�����ڴ��С
		 */
		virtual int Capacity() const;

		/**
		 * �������÷�����ڴ��С
		 */
		virtual int Capacity(int capacity);

		/**
		 * �����ڴ����Ч��С
		 */
		int Size(int sz);

		/**
		 * �����ڴ����Ч��С
		 */
		int Size() const;

		/**
		 * ����һ�ݻ�����
		 */
		Buffer* CopyValueOf(int offset, int count);

		/**
		 * ת����һ���ַ���������
		 */
		StringBuffer* ToString(int offset, int count);

	protected:
		void Realloc(int size);

	protected:
		int     m_capacity;	///< �ڴ��Ĵ�С
		int     m_size;		///< �ڴ�����Ч��С��Ĭ��Ϊ0
		char    *m_pbuf;	///< �ڴ����׵�ַ
	};

	DECLAREVAR(Buffer);

	DEFINE_EXCEPTION(LWPR_MEM_NOT_ENOUGH);
};

#endif // end of LWPR_BUFFER_H__
