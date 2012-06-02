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
#ifndef LWPR_FILE_UTIL_H__
#define LWPR_FILE_UTIL_H__
#include <vector>
#include <string>

namespace LWPR
{
	class FileUtil
	{
	public:
		static bool IsFileExist(const char* fileName);

		/**
		 * �ݹ齨��Ŀ¼
		 * file ��� ��ȫ·�����ļ���
		 *      ��:  /post_app/hd_app/center2/file/20071229/11/rptd/100711030306220071229.rpt
		 *
		 * ����file
		 */
		static char *BuildFile(const char *file);

		/*
		 * �ݹ齨��Ŀ¼
		 * path ��� ��ȫ·��
		 *      ��:  /post_app/hd_app/center2/file/20071229/11/rptd
		 *           /post_app/hd_app/center2/file/20071229/11/rptd/
		 *
		 * ����@path
		 */
		static char *BuildPath(const char *path);

		/**
		 * ȥ���ļ�·���������ļ���
		 */
		static std::string GetBaseName(const char* file);

		/**
		 * �����ļ���չ��
		 */
		static std::string ChangeFileExtName(const char* file, const char* ext);

		/**
		 * �����ļ��������ɿ�����궨��
		 */
		static std::string GenHeaderDef(const char* file);
	};
};

#endif // end of LWPR_FILE_UTIL_H__
