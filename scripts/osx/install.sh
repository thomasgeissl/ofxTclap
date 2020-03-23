#!/bin/sh
OFVERSION=0.11.0
GHUSER=thomasgeissl
GHREPO=ofxTclap

curl -O https://openframeworks.cc/versions/v${OFVERSION}/of_v${OFVERSION}_osx_release.zip
unzip -a -qq of_v${OFVERSION}_osx_release.zip
rm of_v${OFVERSION}_osx_release.zip
cd of_v${OFVERSION}_osx_release/addons

git clone https://github.com/${GHUSER}/${GHREPO}.git
cd $GHREPO

for d in example*/ ; do
    echo "$d"
    cd $d
    make
    cd ..
done