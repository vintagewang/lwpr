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
#ifndef LWPR_STRING_BUFFER_H__
#define LWPR_STRING_BUFFER_H__
#include "LWPRType.h"
#include "Buffer.h"

namespace LWPR
{
	class StringBuffer : public Buffer
	{
	public:
		/**
		 * ���캯��
		 */
		StringBuffer();
		StringBuffer(int capacity = BUFFER_DEFAULT_CAPACITY);
		StringBuffer(char* str);
		StringBuffer(const char* str);
		StringBuffer(const Buffer& buf);
		StringBuffer(const StringBuffer& strbuf);

		/**
		 * ��ֵ����������
		 */
		void operator= (char* str);
		void operator= (const char* str);
		void operator= (const Buffer& buf);
		void operator= (const StringBuffer& strbuf);

		/**
		 * ���ַ���ĩ��׷��
		 */
		char* Append(const char* str);

		/**
		 * �����ַ���ָ��
		 */
		char* str() const;

		/**
		 * �����ַ����ĳ���
		 */
		int Length() const;

		/**
		 * ȥ��ǰ��ո��Ʊ�������з�
		 */
		char* Trim();

		/**
		 * ����ch���ַ����е�һ�γ��ֵ�λ��
		 */
		int FindFirstOf(char ch, int index = 0) const;

	private:
	};

	DECLAREVAR(StringBuffer);
};

#endif // end of LWPR_STRING_BUFFER_H__
