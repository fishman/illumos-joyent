/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*
 * file: symintUtil.c
 * desc: utilities for symint code
 * date: 11/08/88
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "debug.h"
#include "symint.h"

/*
 * _Malloc is used to monitor the allocation
 * of memory.  If failure occurs, we detect it and exit.
 */

void *
_Malloc(uint_t item_count, uint_t item_size)
{
	void *p;

	if ((p = calloc(item_count, item_size)) == NULL) {
		DEBUG_EXP(printf("- size=%d, count=%d\n",
		    item_size, item_count));
		_err_exit("calloc: Out of space");
	}
	return (p);
}
