/* Generated by wayland-scanner 1.23.0 */

/*
 * Copyright © 2008-2011  Kristian Høgsberg
 * Copyright © 2010-2013  Intel Corporation
 * Copyright © 2012-2013  Collabora, Ltd.
 * Copyright © 2018       Purism SPC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

extern const struct wl_interface wl_seat_interface;
extern const struct wl_interface zwp_virtual_keyboard_v1_interface;

static const struct wl_interface *virtual_keyboard_unstable_v1_types[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	&wl_seat_interface,
	&zwp_virtual_keyboard_v1_interface,
};

static const struct wl_message zwp_virtual_keyboard_v1_requests[] = {
	{ "keymap", "uhu", virtual_keyboard_unstable_v1_types + 0 },
	{ "key", "uuu", virtual_keyboard_unstable_v1_types + 0 },
	{ "modifiers", "uuuu", virtual_keyboard_unstable_v1_types + 0 },
	{ "destroy", "", virtual_keyboard_unstable_v1_types + 0 },
};

WL_EXPORT const struct wl_interface zwp_virtual_keyboard_v1_interface = {
	"zwp_virtual_keyboard_v1", 1,
	4, zwp_virtual_keyboard_v1_requests,
	0, NULL,
};

static const struct wl_message zwp_virtual_keyboard_manager_v1_requests[] = {
	{ "create_virtual_keyboard", "on", virtual_keyboard_unstable_v1_types + 4 },
};

WL_EXPORT const struct wl_interface zwp_virtual_keyboard_manager_v1_interface = {
	"zwp_virtual_keyboard_manager_v1", 1,
	1, zwp_virtual_keyboard_manager_v1_requests,
	0, NULL,
};

