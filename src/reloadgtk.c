/*
 *      lxappearance.c
 *
 *      Copyright 2010 PCMan <pcman.tw@gmail.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <glib/gstdio.h>

#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <gdk/gdkx.h>
#include <string.h>


static void reload_all_programs()
{
    GdkEventClient event;
    event.type = GDK_CLIENT_EVENT;
    event.send_event = TRUE;
    event.window = NULL;
    event.message_type = gdk_atom_intern("_GTK_READ_RCFILES", FALSE);
    event.data_format = 8;
    gdk_event_send_clientmessage_toall((GdkEvent *)&event);
}

static void update_cursor_demo()
{
    GtkListStore* store = gtk_list_store_new(1, GDK_TYPE_PIXBUF);
    GdkCursor* cursor;
    GdkCursorType types[] = {
        GDK_LEFT_PTR,
        GDK_HAND2,
        GDK_WATCH,
        GDK_FLEUR,
        GDK_XTERM,
        GDK_LEFT_SIDE,
        GDK_TOP_LEFT_CORNER,
        GDK_SB_H_DOUBLE_ARROW};
    int i;
    for(i = 0; i < (int)G_N_ELEMENTS(types); ++i)
    {
        GtkTreeIter it;
        cursor = gdk_cursor_new(types[i]);
        GdkPixbuf* pix = gdk_cursor_get_image(cursor);
        gdk_cursor_unref(cursor);
        if (pix != NULL)
        {
            gtk_list_store_insert_with_values(store, &it, -1, 0, pix, -1);
            g_object_unref(pix);
        }
    }
    g_object_unref(store);

    /* gtk+ programs should reload named cursors correctly.
     * However, if the cursor is inherited from the root window,
     * gtk+ won't change it. So we need to update the cursor of root window.
     * Unfortunately, this doesn't work for non-gtk+ programs.
     * KDE programs seem to require special handling with XFixes */
    cursor = gdk_cursor_new(GDK_LEFT_PTR);
    i = gdk_display_get_n_screens(gdk_display_get_default());
    while(--i >= 0)
    {
        GdkScreen* screen = gdk_display_get_screen(gdk_display_get_default(), i);
        gdk_window_set_cursor(gdk_screen_get_root_window(screen), cursor);
    }
    gdk_cursor_unref(cursor);
}

int main(int argc, char** argv)
{
    gtk_init( &argc, &argv);
    reload_all_programs();
    update_cursor_demo();
    return 0;
}

