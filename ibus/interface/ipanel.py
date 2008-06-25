# vim:set noet ts=4:
#
# ibus - The Input Bus
#
# Copyright (c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place, Suite 330,
# Boston, MA  02111-1307  USA

__all__ = ("IPanel", )

import dbus.service
from ibus.common import \
	IBUS_PANEL_IFACE

class IPanel (dbus.service.Object):
	# define method decorator.
	method = lambda **args: \
		dbus.service.method (dbus_interface = IBUS_PANEL_IFACE, \
							**args)

	# define signal decorator.
	signal = lambda **args: \
		dbus.service.signal (dbus_interface = IBUS_PANEL_IFACE, \
							**args)

	# define async method decorator.
	async_method = lambda **args: \
		dbus.service.method (dbus_interface = IBUS_PANE_IFACE, \
							async_callbacks = ("reply_cb", "error_cb"), \
							**args)
	@method (in_signature = "iiii")
	def SetCursorLocation (self, x, y, w, h): pass

	@method (in_signature = "svub")
	def UpdatePreedit (self, text, attrs, cursor_pos, visible): pass

	@method (in_signature = "svb")
	def UpdateAuxString (self, text, attrs, visible): pass

	@method (in_signature = "vb")
	def UpdateLookupTable (self, lookup_table, visible): pass

	@method (in_signature = "v")
	def RegisterProperties (self, props): pass

	@method (in_signature = "v")
	def UpdateProperty (self, prop): pass

	@method ()
	def ShowLanguageBar (self): pass

	@method ()
	def HideLanguageBar (self): pass

	@method (in_signature = "s")
	def FocusIn (self, ic): pass

	@method (in_signature = "s")
	def FocusOut (self, ic): pass

	@method ()
	def StatesChanged (self): pass

	@method ()
	def Reset (self): pass

	@method ()
	def Destroy (self): pass

	#signals
	@signal ()
	def PageUp (self): pass

	@signal ()
	def PageDown (self): pass

	@signal ()
	def CursorUp (self): pass

	@signal ()
	def CursorDown (self): pass

	@signal ()
	def PropertyActivate (self, prop_name, prop_state): pass

	@signal ()
	def PropertyShow (self, prop_name): pass

	@signal ()
	def PropertyHide (self, prop_name): pass

