#! /bin/sh

cd ..
doxygen doxygen/Doxyfile
mkdir -p ./docs
cp -R docs/ ./docs/
