#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/bitcoin.png
ICON_DST=../../src/qt/res/icons/bitcoin.ico
convert ${ICON_SRC} -resize 16x16 magpiecoin-y-16.png
convert ${ICON_SRC} -resize 32x32 magpiecoin-y-32.png
convert ${ICON_SRC} -resize 48x48 magpiecoin-y-48.png
convert magpiecoin-y-16.png magpiecoin-y-32.png magpiecoin-y-48.png ${ICON_DST}

