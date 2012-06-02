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
#ifndef LWPR_INPUT_STREAM_H__
#define LWPR_INPUT_STREAM_H__
#include "LWPRType.h"
#include "Buffer.h"
#include "Object.h"
#include "StringBuffer.h"
#include "Exception.h"

namespace LWPR
{
	class InputStream : public Object
	{
		InputStream(const InputStream& rhs);
		InputStream& operator=(const InputStream& rhs);

	public:
		/**
		 * ���캯��
		 */
		InputStream(Buffer_ptr buf);
		/**
		 * ���ö�ƫ����
		 */
		void Reset();

		/**
		 * ��Buffer������һ��BOOL
		 */
		BOOL ReadBOOL();

		/**
		 * ��Buffer������һ�����������������ֽ���ת���ɱ����ֽ���
		 */
		INT8 ReadINT8();
		UINT8 ReadUINT8();
		INT16 ReadINT16();
		UINT16 ReadUINT16();
		INT32 ReadINT32();
		UINT32 ReadUINT32();
		INT64 ReadINT64();
		UINT64 ReadUINT64();
		/**
		 * ������һ��float�͵ĸ�����
		 */
		FP32 ReadFloat();
		/**
		 * ������һ��double�͵ĸ�����
		 */
		FP64 ReadDouble();
		/**
		 * ������һ���ַ���
		 */
		std::string ReadString();
		/**
		 * ������һ��buffer
		 */
		Buffer_ptr ReadAny();
		void ReadArray(void* buf);
		/**
		 * ������һ���ı���
		 */
		StringBuffer_ptr ReadLine();

	private:
		Buffer_var	m_vBuffer;
		int			m_nOffSet;
	};

	DECLAREVAR(InputStream);

	DEFINE_EXCEPTION(UnmarshalException);
};

#endif // end of LWPR_INPUT_STREAM_H__
