/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
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
 * Copyright (c) 2018 by Delphix. All rights reserved.
 */

#ifndef _SYS_DATASET_KSTATS_H
#define	_SYS_DATASET_KSTATS_H

#include <sys/aggsum.h>
#include <sys/dmu.h>
#include <sys/kstat.h>

typedef struct dataset_aggsum_stats_t {
	aggsum_t das_writes;
	aggsum_t das_nwritten;
	aggsum_t das_reads;
	aggsum_t das_nread;
} dataset_aggsum_stats_t;

typedef struct dataset_kstat_values {
	kstat_named_t dkv_ds_name;
	kstat_named_t dkv_writes;
	kstat_named_t dkv_nwritten;
	kstat_named_t dkv_reads;
	kstat_named_t dkv_nread;
} dataset_kstat_values_t;

typedef struct dataset_kstats {
	dataset_aggsum_stats_t dk_aggsums;
	kstat_t *dk_kstats;
} dataset_kstats_t;

void dataset_kstats_create(dataset_kstats_t *, objset_t *);
void dataset_kstats_destroy(dataset_kstats_t *);

void dataset_kstats_update_write_kstats(dataset_kstats_t *, int64_t);
void dataset_kstats_update_read_kstats(dataset_kstats_t *, int64_t);

#endif /* _SYS_DATASET_KSTATS_H */