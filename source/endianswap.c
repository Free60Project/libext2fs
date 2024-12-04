// Copyright (c) 2024 Aiden Isik

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#include "endianswap.h"

// Network to host: big to little endian. 32-bit.
uint32_t ntohl(uint32_t in)
{
	uint32_t out = in;

	if('AB' == 0b0100001001000001) // Big endian, need to swap bytes
	{
		out = ((0xFF000000 & in) >> 24) | ((0x00FF0000 & in) >> 8) | ((0x0000FF00 & in) << 8) | ((0x000000FF & in) << 24);
	}

	return out;
}

// Host to network: little to big endian. 32-bit.
uint32_t htonl(uint32_t in)
{
	uint32_t out = in;

	if('AB' == 0b0100000101000010) // Little endian, need to swap bytes
	{
		out = ((0xFF000000 & in) >> 24) | ((0x00FF0000 & in) >> 8) | ((0x0000FF00 & in) << 8) | ((0x000000FF & in) << 24);
	}

	return out;
}

// Network to host: big to little endian. 16-bit.
uint16_t ntohs(uint16_t in)
{
	uint16_t out = in;

	if('AB' == 0b0100001001000001) // Big endian, need to swap bytes
	{
		out = ((in & 0x00FF) << 8) | ((in & 0xFF00) >> 8);
	}

	return out;
}

// Host to network: little to big endian. 16-bit.
uint16_t htons(uint16_t in)
{
	uint16_t out = in;

	if('AB' == 0b0100000101000010) // Little endian, need to swap bytes
	{
		out = ((in & 0x00FF) << 8) | ((in & 0xFF00) >> 8);
	}

	return out;
}


