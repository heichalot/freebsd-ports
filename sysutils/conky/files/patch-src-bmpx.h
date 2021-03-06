--- src/bmpx.h.orig	2009-09-23 22:04:47.000000000 +0300
+++ src/bmpx.h	2009-09-23 22:02:05.000000000 +0300
@@ -0,0 +1,39 @@
+/* -*- mode: c; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*-
+ * vim: ts=4 sw=4 noet ai cindent syntax=c
+ *
+ * Conky, a system monitor, based on torsmo
+ *
+ * Please see COPYING for details
+ *
+ * Copyright (c) 2005-2009 Brenden Matthews, Philip Kovacs, et. al.
+ *	(see AUTHORS)
+ * All rights reserved.
+ *
+ * This program is free software: you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation, either version 3 of the License, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ * You should have received a copy of the GNU General Public License
+ * along with this program.  If not, see <http://www.gnu.org/licenses/>.
+ *
+ */
+
+#ifndef BMPX_H_
+#define BMPX_H_
+
+void update_bmpx(void);
+struct bmpx_s {
+	char *title;
+	char *artist;
+	char *album;
+	char *uri;
+	int bitrate;
+	int track;
+};
+
+#endif /*BMPX_H_*/
