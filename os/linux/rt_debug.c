/*
 * Copyright (C) 2016 Philip Worrall
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/os/rt_debug.h"

#define RT_ERROR_MSG 0
#define RT_DEBUG_MSG 1

void rt_dprintk(int type, const char * format, ...)
{
	va_list ap;

	va_start(ap, format);
	if (type == RT_DEBUG_MSG)
		printk(KERN_DEBUG KBUILD_MODNAME ": ");
	else
		printk(KERN_ERR KBUILD_MODNAME ": ");
	vprintk(format, ap);
	va_end(ap);
}

void rt_fmt_msg(const char * format, ...)
{
    rt_dprintk(RT_DEBUG_MSG, format);
}

void rt_fmt_emsg(const char * format, ...)
{
    rt_dprintk(RT_ERROR_MSG, format);
}

