/* Common definition for memset/bzero implementation.
   All versions must be listed in ifunc-impl-list.c.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <ifunc-init.h>

extern __typeof (REDIRECT_NAME) OPTIMIZE (niagara4) attribute_hidden;
extern __typeof (REDIRECT_NAME) OPTIMIZE (niagara1) attribute_hidden;
extern __typeof (REDIRECT_NAME) OPTIMIZE (ultra1) attribute_hidden;

static inline void *
IFUNC_SELECTOR (int hwcap)
{
  if (hwcap & HWCAP_SPARC_CRYPTO)
    return OPTIMIZE (niagara4);
  if (hwcap & HWCAP_SPARC_BLKINIT)
    return OPTIMIZE (niagara1);
  return OPTIMIZE (ultra1);
}