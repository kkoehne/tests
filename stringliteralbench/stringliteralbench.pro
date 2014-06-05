#-------------------------------------------------
#
# Project created by QtCreator 2014-06-04T12:58:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_stringliteralbenchmark
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG += c++11
DEFINES += QT_USE_QSTRINGBUILDER

SOURCES += tst_stringliteralbenchmark.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
