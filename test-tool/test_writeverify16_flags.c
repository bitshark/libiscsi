/* 
   Copyright (C) 2013 Ronnie Sahlberg <ronniesahlberg@gmail.com>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>

#include "iscsi.h"
#include "scsi-lowlevel.h"
#include "iscsi-test-cu.h"

void
test_writeverify16_flags(void)
{ 
	int ret;
	unsigned char *buf = alloca(block_size);

	CHECK_FOR_DATALOSS;

	logging(LOG_VERBOSE, LOG_BLANK_LINE);
	logging(LOG_VERBOSE, "Test WRITEVERIFY16 flags");


	logging(LOG_VERBOSE, "Test WRITEVERIFY16 with BYTCHK==1");
	memset(buf, 0xa6, block_size);
	ret = writeverify16(sd, 0,
			    block_size, block_size, 0, 0, 1, 0, buf,
			    EXPECT_STATUS_GOOD);
	if (ret == -2) {
		logging(LOG_NORMAL, "[SKIPPED] WRITEVERIFY16 is not implemented.");
		CU_PASS("WRITEVERIFY16 is not implemented.");
		return;
       	}	
	CU_ASSERT_EQUAL(ret, 0);
}
