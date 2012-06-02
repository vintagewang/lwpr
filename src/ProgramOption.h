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
#ifndef LWPR_PROGRAM_OPTION_H__
#define LWPR_PROGRAM_OPTION_H__
#include "LWPRType.h"
#include <string>
#include <map>
#include <vector>

namespace LWPR
{
	class ProgramOption
	{
	public:
		/**
		 * ���캯��
		 */
		ProgramOption();

		/**
		 * ��������
		 */
		virtual ~ProgramOption();

		/**
		 * ����������ѡ��
		 */
		bool ParseCmdlineOption(int argc, char **argv, const char *optstring);

		/**
		 * ѡ���Ƿ���Ч
		 */
		bool IsOptionValid(char opt);

		/**
		 * ��ȡѡ����Ӧ�Ĳ����б�
		 */
		bool GetArgumentsByOption(char opt, std::vector< std::string >& args);

		/**
		 * ��ȡ������������һ������
		 */
		const std::string& GetFirstArgument() const;

	protected:
		/**
		 * ��������ѡ�������֮��У���������Ƿ�����Ӧ������
		 */
		virtual bool CheckCmdline();

	protected:
		// ����ȷʶ���ѡ��
		std::map< char, std::vector<std::string> > m_Options;
		// ��ѡ���⣬�������õĲ���
		std::vector<std::string> m_OtherArguments;
		// ��ʶ�����Чѡ��
		std::vector<char> m_InvalidOptions;
		// �����һ����������������
		std::string m_strFirstArgument;
	};
};

#endif // end of LWPR_PROGRAM_OPTION_H__
