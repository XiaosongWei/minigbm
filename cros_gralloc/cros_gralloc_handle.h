/*
 * Copyright 2016 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef CROS_GRALLOC_HANDLE_H
#define CROS_GRALLOC_HANDLE_H

#include <cstdint>
#include <cutils/native_handle.h>

#define DRV_MAX_PLANES 4

/*
 * Only use 32-bit integers in the handle. This guarantees that the handle is
 * densely packed (i.e, the compiler does not insert any padding).
 */

struct cros_gralloc_handle {
	native_handle_t base;
	int32_t fds[DRV_MAX_PLANES];
	uint32_t strides[DRV_MAX_PLANES];
	uint32_t offsets[DRV_MAX_PLANES];
	uint32_t sizes[DRV_MAX_PLANES];
	uint32_t format_modifiers[2 * DRV_MAX_PLANES];
	uint32_t width;
	uint32_t height;
	uint32_t format;   /* DRM format */
	uint32_t flags[2]; /* driver creation time flags */
	uint32_t magic;
	uint32_t pixel_stride;
	int32_t droid_format;
	int32_t usage; /* Android usage. */
	uint32_t consumer_usage;
	uint32_t producer_usage;
	uint32_t yuv_color_range;   // YUV Color range.
	uint32_t is_updated;        // frame updated flag
	uint32_t is_encoded;        // frame encoded flag
	uint32_t is_encrypted;
	uint32_t is_key_frame;
	uint32_t is_interlaced;
	uint32_t is_mmc_capable;
	uint32_t compression_mode;
	uint32_t compression_hint;
	uint32_t codec;
};

typedef const struct cros_gralloc_handle *cros_gralloc_handle_t;

#endif
