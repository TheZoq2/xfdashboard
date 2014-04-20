/*
 * focusable: An interface which can be inherited by actors to get
 *            by focus manager for keyboard navigation
 * 
 * Copyright 2012-2014 Stephan Haller <nomad@froevel.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef __XFDASHBOARD_FOCUSABLE__
#define __XFDASHBOARD_FOCUSABLE__

#include <clutter/clutter.h>

G_BEGIN_DECLS

#define XFDASHBOARD_TYPE_FOCUSABLE				(xfdashboard_focusable_get_type())
#define XFDASHBOARD_FOCUSABLE(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj), XFDASHBOARD_TYPE_FOCUSABLE, XfdashboardFocusable))
#define XFDASHBOARD_IS_FOCUSABLE(obj)			(G_TYPE_CHECK_INSTANCE_TYPE((obj), XFDASHBOARD_TYPE_FOCUSABLE))
#define XFDASHBOARD_FOCUSABLE_GET_IFACE(obj)	(G_TYPE_INSTANCE_GET_INTERFACE((obj), XFDASHBOARD_TYPE_FOCUSABLE, XfdashboardFocusableInterface))

typedef struct _XfdashboardFocusable			XfdashboardFocusable;
typedef struct _XfdashboardFocusableInterface	XfdashboardFocusableInterface;

struct _XfdashboardFocusableInterface
{
	/*< private >*/
	/* Parent interface */
	GTypeInterface				parent_interface;

	/*< public >*/
	/* Virtual functions */
	gboolean (*can_focus)(XfdashboardFocusable *self);
	void (*set_focus)(XfdashboardFocusable *self);
	void (*unset_focus)(XfdashboardFocusable *self);

	gboolean (*handle_key_event)(XfdashboardFocusable *self, const ClutterEvent *inEvent);
};

/* Public API */
GType xfdashboard_focusable_get_type(void) G_GNUC_CONST;

gboolean xfdashboard_focusable_can_focus(XfdashboardFocusable *self);
void xfdashboard_focusable_set_focus(XfdashboardFocusable *self);
void xfdashboard_focusable_unset_focus(XfdashboardFocusable *self);

gboolean xfdashboard_focusable_handle_key_event(XfdashboardFocusable *self, const ClutterEvent *inEvent);

G_END_DECLS

#endif	/* __XFDASHBOARD_FOCUSABLE__ */