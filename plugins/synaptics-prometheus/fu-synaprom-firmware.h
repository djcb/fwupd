/*
 * Copyright (C) 2019 Richard Hughes <richard@hughsie.com>
 * Copyright (C) 2019 Synaptics Inc
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <glib.h>

#define FU_SYNAPROM_FIRMWARE_TAG_MFW_HEADER		0x0001
#define FU_SYNAPROM_FIRMWARE_TAG_MFW_PAYLOAD		0x0002
#define FU_SYNAPROM_FIRMWARE_TAG_CFG_HEADER		0x0003
#define FU_SYNAPROM_FIRMWARE_TAG_CFG_PAYLOAD		0x0004

/* le */
typedef struct __attribute__((packed)) {
	guint32			 product;
	guint32			 id;			/* MFW unique id used for compat verification */
	guint32			 buildtime;		/* unix-style build time */
	guint32			 buildnum;		/* build number */
	guint8			 vmajor;		/* major version */
	guint8			 vminor;		/* minor version */
	guint8			 unused[6];
} FuSynapromFirmwareMfwHeader;

/* le */
typedef struct __attribute__((packed)) {
	guint32			 product;
	guint32			 id1;			/* verification ID */
	guint32			 id2;			/* verification ID */
	guint16			 version;		/* config version */
	guint8			 unused[2];
} FuSynapromFirmwareCfgHeader;

GPtrArray	*fu_synaprom_firmware_new		(GBytes		*blob,
							 GError		**error);
GBytes		*fu_synaprom_firmware_get_bytes_by_tag	(GPtrArray	*firmware,
							 guint16	 tag,
							 GError		**error);
GBytes		*fu_synaprom_firmware_generate		(void);
