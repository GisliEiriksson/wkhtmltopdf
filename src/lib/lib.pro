# Copyright 2010 wkhtmltopdf authors
#
# This file is part of wkhtmltopdf.
#
# wkhtmltopdf is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# wkhtmltopdf is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with wkhtmltopdf.  If not, see <http:#www.gnu.org/licenses/>.

TEMPLATE = lib
CONFIG += dll
QT += gui

include(../../common.pri)
include(lib.pri)

DEF_FILE = $$_PRO_FILE_PWD_/lib.def
CONFIG(static, shared|static): DEFINES += QT_NODLL

unix {
   headers.target=headers
   headers.files=../../include/wkhtmltox/*.h ../../include/wkhtmltox/*.inc
   headers.path=$$INSTALLBASE/include/wkhtmltox

   QMAKE_EXTRA_TARGETS += headers
   INSTALLS += headers
}

windows {
   TARGET_EXT=.dll
   QT_PLUGIN += qwindows
   QT_PLUGIN.platforms += qwindows
   # https://bugzilla.redhat.com/show_bug.cgi?id=1257630
   LIBS += -L$$[QT_INSTALL_PLUGINS]/platforms
   debug:LIBS += -lqwindowsd
   release:LIBS += -lqwindows
}

TARGET=wkhtmltox
INSTALLS += target
wkhtmltox.path=$$INSTALLBASE/lib

DESTDIR = ../../bin
target.path=$$INSTALLBASE/lib
