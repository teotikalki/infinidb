/* Copyright (C) 2013 Calpont Corp.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; version 2 of
   the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */

/***************************************************************************
 *
 *   $Id: filebuffer.cpp 2035 2013-01-21 14:12:19Z rdempsey $
 *
 *   jrodriguez@calpont.com   *
 *                                                                         *
 ***************************************************************************/

#include "filebuffer.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

namespace dbbc {
	
FileBuffer::FileBuffer() : fDataLen(0), fLbid(-1), fVerid(0)
{
}

FileBuffer::FileBuffer(const FileBuffer& rhs) {

	if (this==NULL || this==&rhs)
		return;
	
	fLbid = rhs.fLbid;
	fVerid = rhs.fVerid;
	setData(rhs.fByteData, rhs.fDataLen);
	fListLoc=rhs.listLoc();
	fDataLen=rhs.fDataLen;
}


FileBuffer::FileBuffer(const BRM::LBID_t lbid, const BRM::VER_t ver, const u_int8_t* data, const uint32_t len) {
	fLbid = lbid;
	fVerid = ver;
	fDataLen=len;
	setData(data, fDataLen);
}


FileBuffer::FileBuffer(const BRM::LBID_t lbid, const BRM::VER_t ver) {
	fLbid=lbid;
	fVerid=ver;
	fDataLen=0;
}


FileBuffer& FileBuffer::operator= (const FileBuffer& rhs) {
	fLbid = rhs.fLbid;
	fVerid = rhs.fVerid;
	fDataLen=rhs.fDataLen;
	setData(rhs.fByteData, fDataLen);
	fListLoc=rhs.listLoc();
	return *this;
}

void FileBuffer::setData(const u_int8_t* d, const int len)
{
	if (d==NULL || len <=0)
		return;
	
	fDataLen=len;
	memcpy(fByteData, d, len);
}

void FileBuffer::setData(const uint8_t *d)
{
	fDataLen = 8192;
	memcpy(fByteData, d, 8192);
}

FileBuffer::~FileBuffer() {
}

}