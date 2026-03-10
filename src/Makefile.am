NULL=

AM_CPPFLAGS = \
	-I$(srcdir) \
	-DPACKAGE_LIB_DIR=\""$(libdir)"\" \
	$(NULL)

reloadgtk_includedir = $(includedir)/reloadgtk

bin_PROGRAMS = reloadgtk
reloadgtk_SOURCES = \
	reloadgtk.c \
	$(NULL)

reloadgtk_CFLAGS = \
	$(GTK_CFLAGS) \
	$(XLIB_CFLAGS) \
	$(GMODULE_CFLAGS) \
	-Werror-implicit-function-declaration \
	$(NULL)

reloadgtk_LDADD = \
	$(GTK_LIBS) \
	$(XLIB_LIBS) \
	$(GMODULE_LIBS) \
	$(NULL)
