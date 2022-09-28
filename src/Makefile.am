## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet2

projet2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	houssem_fonction.c houssem_fonction.h \
	nada_fonction.c nada_fonction.h \
	nada_callbacks.c nada_callbacks.h \
	houssem_callbacks.c houssem_callbacks.h \
	hamzacallbacks.c hamzacallbacks.h \
	hamzafonction.c hamzafonction.h \
	rayacallbacks.c rayacallbacks.h \
	rayafonction.c rayafonction.h \
	firascallbacks.c firascallbacks.h \
	firasfonction.c firasfonction.h \
	nourcallbacks.c nourcallbacks.h \
	nourfonction.c nourfonction.h 

projet2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)
AM_LDFLAGS=-L/usr/bin
projet2_LDADD+=-lcurl
